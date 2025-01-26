import {
  StyleSheet,
  Text,
  TextInput,
  View,
  StatusBar,
  Pressable,
  Keyboard,
  useColorScheme,
} from "react-native";
import React, { useEffect, useState } from "react";
import { addTolist, printTodo } from "./ToDoManagerFunc";

const ToDoManager = () => {
  const [isFocused, setIsFocused] = useState(false);
  const [todos, setTodos] = useState([]);
  const [isLightTheme, setIsLightTheme] = useState(true);
  const color = useColorScheme();
  console.log(color);

  useEffect(() => {
    if (color === "light") {
      setIsLightTheme(true);
    } else setIsLightTheme(false);
  }, [color]);

  return (
    <Pressable
      onPress={() => Keyboard.dismiss()}
      style={[styles.dismissKeyboard, isLightTheme ? styles.screenL : styles.screenD]}
    >
      <View style={styles.marginTop}>
        <View
          style={[
            styles.border,
            isLightTheme ? styles.borderColorL : styles.borderColorD,
            styles.widthDiv,
            styles.roundedFull,
            styles.center,
            isFocused ? styles.focused : null,
          ]}
        >
          <TextInput
            style={[
              styles.widthInput,
              styles.center,
              isLightTheme ? styles.textInputColorL : styles.textInputColorD,
            ]}
            placeholderTextColor = {isLightTheme ? "black" : "white"} 
            onFocus={() => setIsFocused(true)}
            onBlur={() => setIsFocused(false)}
            placeholder="Enter Task to Enter"
            onSubmitEditing={(e) => {
              addTolist(e, setTodos, todos);
            }}
            blurOnSubmit={false}
          />
        </View>
        <Text style={styles.center}>Task List</Text>
        <View>{printTodo(todos, styles, setTodos,  isLightTheme)}</View>

      </View>
    </Pressable>
  );
};

export default ToDoManager;

const styles = StyleSheet.create({
  border: {
    borderWidth: 1,
  },
  borderColorL: {
    borderColor: "black",
    backgroundColor: "white",
  },
  borderColorD: {
    borderColor: "white",
    backgroundColor: "black",
  },
  textInputColorL: {
    backgroundColor: "transparent ",
    color: "black",
  },
  textInputColorD: {
    backgroundColor: "transparent ",
    color: "white",
  },
  marginTop: {
    marginTop: StatusBar.currentHeight + 10,
  },
  roundedFull: {
    borderRadius: 100,
  },
  widthInput: {
    width: "98%",
  },
  widthDiv: {
    width: "92%",
  },
  center: {
    alignSelf: "center",
  },
  focused: {
    borderColor: "#4CAF50",
    shadowColor: "#4CAF50",
    shadowOpacity: 0.5,
    shadowRadius: 1,
    elevation: 0.5,
    // backgroundColor: "#F7F7F7",
    paddingVertical: 8,
    paddingHorizontal: 16,
  },
  todoItem: {
    padding: 10,
    borderBottomWidth: 1,
    borderBottomColor: "#ccc",
  },
  todoText: {
    width: "82%",
    paddingLeft: 16,
  },
  todoTextColorL:{
    color: "black",
  },
  todoTextColorD:{
    color: "white",
  },
  delButton: {
    alignItems: "center",
    justifyContent: "center",
    paddingHorizontal: "3%",
    paddingVertical: "3%",
    borderRadius: 10,
    elevation: 3,
    backgroundColor: "red",
    height: 50,
    borderColor: "red",
  },
  displayTask: {
    display: "flex",
    flexDirection: "row",
    alignItems: "center",
  },
  dismissKeyboard: {
    height: "100%",
    width: "100%",
  },
  screenL: {
    backgroundColor: "white",
  },
  screenD: {
    backgroundColor: "black",
  },
});
