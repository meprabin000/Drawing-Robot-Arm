import { useState } from "react";
import { Image, Pressable, Text, TextInput, TouchableOpacity, View } from "react-native";
import { HStack, VStack } from "react-native-flex-layout";
import SignupStyles from "../styles/SignupStyles.js";

const Signup = (props) => {
    const [firstName, setFirstName] = useState("");
    const [lastName, setLastName] = useState("");
    const [email, setEmail] = useState("")
    const [username, setUsername] = useState("");
    const [password, setPassword] = useState("");
    const [reenteredPassword, setReenteredPassword] = useState("");
    


    return (
        <VStack spacing={5} style={SignupStyles.mainView}>
            {/* Logo image */}
            <View style={SignupStyles.signupDisplay}>
                <Image
                    style={SignupStyles.logo}
                    source={require('../assets/images/logo.png')}
                />
                <Text style={SignupStyles.titleView}>Sign Up</Text>
            </View>

            {/* Username Password Box */}
            <View style={SignupStyles.inputDisplay}>
                <HStack style={SignupStyles.firstLastNameStack} spacing={10}>
                    <View style={[SignupStyles.inputWrapper, SignupStyles.firstLastNameWrapper]}>
                        <TextInput
                            style={SignupStyles.inputBoxDisplay}
                            onChangeText={setFirstName}
                            value={firstName}
                            placeholder="First Name"
                        />
                    </View>

                    <View style={[SignupStyles.inputWrapper, SignupStyles.firstLastNameWrapper]}>
                        <TextInput
                            style={SignupStyles.inputBoxDisplay}
                            onChangeText={setLastName}
                            value={lastName}
                            placeholder="Last Name"
                        />
                    </View>
                </HStack>

                <View style={SignupStyles.inputWrapper}>
                    <TextInput
                        style={SignupStyles.inputBoxDisplay}
                        onChangeText={setEmail}
                        value={email}
                        placeholder="Email Address"
                    />
                </View>


                <View style={SignupStyles.inputWrapper}>
                    <TextInput
                        style={SignupStyles.inputBoxDisplay}
                        onChangeText={setUsername}
                        value={username}
                        placeholder="Username"
                    />
                </View>

                <View style={SignupStyles.inputWrapper}>
                    <TextInput
                        style={SignupStyles.inputBoxDisplay}
                        onChangeText={setPassword}
                        value={password}
                        secureTextEntry={true}
                        placeholder="Password"
                    />
                </View>

                <View style={SignupStyles.inputWrapper}>
                    <TextInput
                        style={SignupStyles.inputBoxDisplay}
                        onChangeText={setReenteredPassword}
                        value={reenteredPassword}
                        secureTextEntry={true}
                        placeholder="Reenter Password"
                    />
                </View>
            </View>
            
            {/* Sign in Button */}
            <View style={SignupStyles.signInButtonWrapper}>
                <Pressable onPress={(e) => console.log("Create Account Clicked!")}>
                    <Text style={SignupStyles.signInText}>Create Account</Text>
                </Pressable>
            </View>

            {/* Don't have an account */}
            <View style={SignupStyles.registerHereWrapper}>
                <Text style={SignupStyles.noAccountText}>Already have an account?</Text>
                <TouchableOpacity onPress={(e) => console.log("Register Here pressed!")}>
                    <Text style={SignupStyles.registerHere}>Login Here!</Text>
                </TouchableOpacity>
            </View>
        </VStack>
    );
}

export default Signup;