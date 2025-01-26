#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int word_char_count[26] = {0};
void readFile(const char *fileName, int numOfThreads, int blockSize);
void divideThreads(char *urls[], int numOfUrl, int numOfThreads, int blockSize);
size_t writeCallback(void *ptr, size_t size, size_t nmemb, void *data);
void *workerFunction(void *args);
void printGlobalArray();
long getCurrentTimeInMs();

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char **threadUrl;
    int threadID;
    int blockSize;
    int numOfUrl;
} threadArgs;

typedef struct {
    char buffer[1024];
    size_t bufferLen;
    int *tempArray;
    int blockSize;
} CallbackData;

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Invalid number of arguments: ./crawler <Txt File Name> <Number of Threads> <Block Size>\n");
        return -1;
    }
    
    const char *fileName = argv[1];
    int len = strlen(fileName);
    if (len < 4 || strcmp(fileName + len - 4, ".txt") != 0) {
        printf("Error: File name must have a .txt extension.\n");
        return -1;
    }
    
    int numOfThreads = atoi(argv[2]);
    int blockSize = atoi(argv[3]);
    if (numOfThreads <= 0 || blockSize <= 0) {
        printf("Error: Number of Threads and Block Size must be positive integers.\n");
        return -1;
    }

    long startTime = getCurrentTimeInMs();

    readFile(fileName, numOfThreads, blockSize);

    long endTime = getCurrentTimeInMs();
    printf("Total program execution time: %ld ms\n", endTime - startTime);

    printGlobalArray();

    return 0;
}

void readFile(const char *fileName, int numOfThreads, int blockSize) {
    long startFileReadTime = getCurrentTimeInMs();

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    int numOfUrl = 0;
    char *urlLine = NULL;
    size_t lineLength = 0;
    while (getline(&urlLine, &lineLength, file) != -1) {
        numOfUrl++;
    }
    
    char *urls[numOfUrl];
    rewind(file);
    for (int i = 0; i < numOfUrl; i++) {
        getline(&urlLine, &lineLength, file);
        size_t len = strlen(urlLine);
        if (len > 0 && urlLine[len - 1] == '\n') {
            urlLine[len - 1] = '\0';
        }
        urls[i] = strdup(urlLine);
    }

    fclose(file);
    if (urlLine) free(urlLine);

    long endFileReadTime = getCurrentTimeInMs();
    printf("File read time: %ld ms\n", endFileReadTime - startFileReadTime);

    divideThreads(urls, numOfUrl, numOfThreads, blockSize);
}

size_t writeCallback(void *ptr, size_t size, size_t nmemb, void *data) {
    CallbackData *callbackData = (CallbackData *)data;
    size_t totalSize = size * nmemb;
    char *content = (char *)ptr;
    size_t offset = 0;

    while (offset < totalSize) {
        size_t spaceLeft = sizeof(callbackData->buffer) - callbackData->bufferLen;
        size_t toCopy = (totalSize - offset < spaceLeft) ? totalSize - offset : spaceLeft;
        memcpy(callbackData->buffer + callbackData->bufferLen, content + offset, toCopy);
        callbackData->bufferLen += toCopy;
        offset += toCopy;

        while (callbackData->bufferLen >= callbackData->blockSize) {
            char block[callbackData->blockSize + 1];
            memcpy(block, callbackData->buffer, callbackData->blockSize);
            block[callbackData->blockSize] = '\0';

            char *token = strtok(block, " \t\n\r");
            while (token != NULL) {
                char firstChar = token[0];
                if (firstChar >= 'a' && firstChar <= 'z') {
                    callbackData->tempArray[firstChar - 'a']++;
                } else if (firstChar >= 'A' && firstChar <= 'Z') {
                    callbackData->tempArray[firstChar - 'A']++;
                }
                token = strtok(NULL, " \t\n\r");
            }

            memmove(callbackData->buffer, callbackData->buffer + callbackData->blockSize,
                    callbackData->bufferLen - callbackData->blockSize);
            callbackData->bufferLen -= callbackData->blockSize;
        }
    }
    return totalSize;
}

void *workerFunction(void *args) {
    threadArgs *threadArgu = (threadArgs *)args;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (int i = 0; i < threadArgu->numOfUrl; i++) {
            int tempArray[26] = {0};
            CallbackData callbackData = {
                .bufferLen = 0,
                .tempArray = tempArray,
                .blockSize = threadArgu->blockSize
            };

            curl_easy_setopt(curl, CURLOPT_URL, threadArgu->threadUrl[i]);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &callbackData);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                fprintf(stderr, "Thread %d: curl_easy_perform() failed: %s\n",
                        threadArgu->threadID, curl_easy_strerror(res));
            } else {
                if (callbackData.bufferLen > 0) {
                    char remainingBlock[callbackData.bufferLen + 1];
                    memcpy(remainingBlock, callbackData.buffer, callbackData.bufferLen);
                    remainingBlock[callbackData.bufferLen] = '\0';

                    char *token = strtok(remainingBlock, " \t\n\r");
                    while (token != NULL) {
                        char firstChar = token[0];
                        if (firstChar >= 'a' && firstChar <= 'z') {
                            callbackData.tempArray[firstChar - 'a']++;
                        } else if (firstChar >= 'A' && firstChar <= 'Z') {
                            callbackData.tempArray[firstChar - 'A']++;
                        }
                        token = strtok(NULL, " \t\n\r");
                    }
                }

                pthread_mutex_lock(&lock);
                for (int j = 0; j < 26; j++) {
                    word_char_count[j] += tempArray[j];
                }
                pthread_mutex_unlock(&lock);
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return NULL;
}

void divideThreads(char *urls[], int numOfUrl, int numOfThreads, int blockSize) {
    pthread_t threads[numOfThreads];
    threadArgs threadArgu[numOfThreads];

    long startThreadCreationTime = getCurrentTimeInMs();

    for (int i = 0; i < numOfThreads; i++) {
        int urlsPerThread = numOfUrl / numOfThreads + (i < numOfUrl % numOfThreads);
        threadArgu[i].threadUrl = &urls[i * urlsPerThread];
        threadArgu[i].threadID = i;
        threadArgu[i].blockSize = blockSize;
        threadArgu[i].numOfUrl = urlsPerThread;
        pthread_create(&threads[i], NULL, workerFunction, &threadArgu[i]);
    }

    long endThreadCreationTime = getCurrentTimeInMs();
    printf("Thread creation time: %ld ms\n", endThreadCreationTime - startThreadCreationTime);

    long startThreadJoinTime = getCurrentTimeInMs();
    for (int i = 0; i < numOfThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    long endThreadJoinTime = getCurrentTimeInMs();
    printf("Thread join time: %ld ms\n", endThreadJoinTime - startThreadJoinTime);
}

void printGlobalArray() {
    printf("Word Starting Character Counts:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, word_char_count[i]);
    }
}

long getCurrentTimeInMs() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}
