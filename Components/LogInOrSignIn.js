import { Button, StyleSheet, Text, View } from "react-native";
import React from "react";
import { TextInput } from "react-native-paper";

const LogInOrSignIn = () => {
  return (
    <View style={[styles.center, styles.outerBox]}>
      <Text style={[styles.headingText]}>Log In</Text>
      <TextInput style={[styles.textInput]}></TextInput>

      <TextInput style={[styles.textInput]}></TextInput>
      
      <TextInput style={[styles.textInput]}></TextInput>
      <Button title="LogIn"></Button>
    </View>
  );
};

export default LogInOrSignIn;

const styles = StyleSheet.create({
  center: {
    // justifyContent: "around",
    alignItems: "center",
    flex: 1,
  },
  outerBox: {
    // borderWidth: 2,
    // borderColor: "black",
    margin: 30,
    marginBottom: "35%",
    marginTop: "35%",
    // borderRadius: 50,
  },
  textInput: {
    width: "82%",
    marginBottom:4,
    marginTop: 8,
  },
  headingText: {
    fontSize: 50,
  }
});
