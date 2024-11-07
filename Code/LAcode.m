% Read the input image
img = imread('img.jpg');
sizeOrg = size(img);


% Split the image into red, green, and blue color channels
R = img(:,:,1);
G = img(:,:,2);
B = img(:,:,3);

% Compress each color channel using SVD
k = 100; % The number of singular values to keep
[UR, SR, VR] = svd(double(R));
[UG, SG, VG] = svd(double(G));
[UB, SB, VB] = svd(double(B));
compressedR = UR(:,1:k) * SR(1:k,1:k) * VR(:,1:k)';
compressedG = UG(:,1:k) * SG(1:k,1:k) * VG(:,1:k)';
compressedB = UB(:,1:k) * SB(1:k,1:k) * VB(:,1:k)';

% Combine the compressed color channels into a single compressed image
compressedImg = cat(3, uint8(compressedR), uint8(compressedG), uint8(compressedB));

% Display the original and compressed images side-by-side
figure;
subplot(1,2,1);
imshow(img);
title('Original Image');
subplot(1,2,2);
imshow(compressedImg);
title(sprintf('Compressed Image (k=%d)', k));