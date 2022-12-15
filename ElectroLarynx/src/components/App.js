/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import { FlatList, StyleSheet, View, Text } from 'react-native';
import Signup from './Signup';
import Login from './Login';
import AppStyles from '../styles/AppStyles';
import {useAuth0, Auth0Provider} from 'react-native-auth0';

const App = () => {
  return (
    <Auth0Provider domain={"dev-ejp81yk157h52u8t.us.auth0.com"} clientId={"BdBMWwTTB3MqF1MiPuoAgdkzrpDVd4QM"}>
      <View style={AppStyles.appView}>
        <Login />
      </View>
    </Auth0Provider>
  );
}

export default App;
