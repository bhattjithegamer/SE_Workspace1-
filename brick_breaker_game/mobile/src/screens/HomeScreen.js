import React from 'react';
import {
  View,
  Text,
  TouchableOpacity,
  StyleSheet,
  Dimensions,
  StatusBar,
} from 'react-native';
import LinearGradient from 'react-native-linear-gradient';
import Icon from 'react-native-vector-icons/MaterialIcons';

const { width, height } = Dimensions.get('window');

const HomeScreen = ({ navigation }) => {
  const menuItems = [
    {
      title: 'PLAY GAME',
      icon: 'play-arrow',
      onPress: () => navigation.navigate('Game'),
      color: ['#00d4ff', '#0099cc'],
    },
    {
      title: 'LEADERBOARD',
      icon: 'leaderboard',
      onPress: () => navigation.navigate('Leaderboard'),
      color: ['#ff6b6b', '#ff4757'],
    },
    {
      title: 'SETTINGS',
      icon: 'settings',
      onPress: () => navigation.navigate('Settings'),
      color: ['#4ecdc4', '#26d0ce'],
    },
  ];

  return (
    <LinearGradient
      colors={['#0c0c0c', '#1a1a2e', '#16213e']}
      style={styles.container}
    >
      <StatusBar barStyle="light-content" backgroundColor="#0c0c0c" />
      
      {/* Title */}
      <View style={styles.titleContainer}>
        <Text style={styles.title}>BRICK BREAKER</Text>
        <Text style={styles.subtitle}>Classic Arcade Game</Text>
      </View>

      {/* Menu Items */}
      <View style={styles.menuContainer}>
        {menuItems.map((item, index) => (
          <TouchableOpacity
            key={index}
            style={styles.menuItem}
            onPress={item.onPress}
            activeOpacity={0.8}
          >
            <LinearGradient
              colors={item.color}
              style={styles.menuGradient}
              start={{ x: 0, y: 0 }}
              end={{ x: 1, y: 1 }}
            >
              <Icon name={item.icon} size={32} color="#ffffff" />
              <Text style={styles.menuText}>{item.title}</Text>
            </LinearGradient>
          </TouchableOpacity>
        ))}
      </View>

      {/* Footer */}
      <View style={styles.footer}>
        <Text style={styles.footerText}>Tap to play • Swipe to move</Text>
        <Text style={styles.versionText}>v1.0.0</Text>
      </View>
    </LinearGradient>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'space-between',
    alignItems: 'center',
    paddingVertical: 50,
  },
  titleContainer: {
    alignItems: 'center',
    marginTop: 50,
  },
  title: {
    fontSize: 36,
    fontWeight: '900',
    color: '#00d4ff',
    textAlign: 'center',
    fontFamily: 'monospace',
    textShadowColor: 'rgba(0, 212, 255, 0.5)',
    textShadowOffset: { width: 0, height: 0 },
    textShadowRadius: 10,
  },
  subtitle: {
    fontSize: 16,
    color: '#888',
    marginTop: 10,
    fontFamily: 'monospace',
  },
  menuContainer: {
    width: width * 0.8,
    gap: 20,
  },
  menuItem: {
    borderRadius: 15,
    overflow: 'hidden',
    elevation: 5,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.25,
    shadowRadius: 3.84,
  },
  menuGradient: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'center',
    paddingVertical: 20,
    paddingHorizontal: 30,
  },
  menuText: {
    fontSize: 18,
    fontWeight: 'bold',
    color: '#ffffff',
    marginLeft: 15,
    fontFamily: 'monospace',
  },
  footer: {
    alignItems: 'center',
  },
  footerText: {
    fontSize: 14,
    color: '#888',
    textAlign: 'center',
    fontFamily: 'monospace',
  },
  versionText: {
    fontSize: 12,
    color: '#555',
    marginTop: 10,
    fontFamily: 'monospace',
  },
});

export default HomeScreen;