import { Text, View, Pressable } from "react-native";
export const addTolist = (e, setTodos, todos) => {
  if (e.nativeEvent.text !== "") {
    setTodos([...todos, e.nativeEvent.text]);
    e.target.clear();
  } else alert("Please enter a task");
};

export const printTodo = (todos, styles, setTodos, isLightTheme) => {
  return todos.map((todo, index) => {
    return (
      <View key={index} style={[styles.displayTask, styles.todoItem]}>
        <Text style={[styles.todoText, isLightTheme ? styles.todoTextColorL : styles.todoTextColorD]}>{todo}</Text>
        <Pressable
          onPress={() => delTask(index, setTodos, todos)}
          style={[styles.border, styles.delButton]}
        >
          <Text style={{color: "white"}}>Delete</Text>
        </Pressable>
      </View>
    );
  });
};

const delTask = (index, setTodos, todos) => {
  setTodos(todos.filter((todo, i) => i !== index));
};
