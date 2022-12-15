import { StyleSheet } from "react-native";

const SignupStyles = StyleSheet.create( {
    logo: {
        width: 75,
        height: 75,
        resizeMode: 'contain'
    },
    signupDisplay: {
        width: '100%',
        height: '20%',
        alignItems: 'center',
        position: 'relative'
    },
    mainView: {
        height: '100%',
        width: '100%',
    },
    titleView: {
        fontSize: 40,
        fontWeight: '500'
    },
    inputDisplay: {
        paddingRight: 20,
        paddingLeft: 20,
        width: '100%',
        alignItems: "center"
        // backgroundColor: 'blue'
    },
    inputWrapper: {
        borderWidth: 0.2,
        borderColor: 'red',
        borderRadius: 10,
        width: 350,
        marginTop: 20
    },
    firstLastNameWrapper: {
        width: 170,
    },
    inputBoxDisplay: {
        height: 40,
        padding: 10,
        fontSize: 20
    },
    forgotPasswordButton: {
        fontSize: 15,
        textAlign: 'center'
    },
    forgotPasswordButtonWrapper: {
        marginTop: 20,
    },
    signInButtonWrapper: {
        backgroundColor: 'red',
        borderRadius: 20,
        marginLeft: 50,
        marginRight: 50,
        padding: 5,
        marginTop: 80
    },
    signInText: {
        color: 'white',
        textAlign: 'center',
        fontSize: 25
    },
    noAccountText: {
        textAlign: 'center',
        color: '#888888'
    },
    registerHereWrapper: {
        marginTop: 70
    },
    registerHere: {
        textAlign: 'center',
        paddingTop: 5,
        fontSize: 15,
        textDecorationLine: 'underline',
        fontWeight: '400'
    }
})

export default SignupStyles;