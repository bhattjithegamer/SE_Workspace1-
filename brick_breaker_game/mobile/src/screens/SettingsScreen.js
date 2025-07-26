import React, { useState, useEffect } from 'react';
import {
  View,
  Text,
  StyleSheet,
  Switch,
  TouchableOpacity,
  ScrollView,
  Alert,
  ActivityIndicator,
} from 'react-native';
import LinearGradient from 'react-native-linear-gradient';
import Icon from 'react-native-vector-icons/MaterialIcons';

const SettingsScreen = () => {
  const [settings, setSettings] = useState({
    soundEnabled: true,
    vibrationEnabled: true,
    autoSave: true,
    difficulty: 'normal',
    theme: 'dark',
  });
  const [loading, setLoading] = useState(false);

  const difficultyOptions = [
    { label: 'Easy', value: 'easy' },
    { label: 'Normal', value: 'normal' },
    { label: 'Hard', value: 'hard' },
  ];

  const themeOptions = [
    { label: 'Dark', value: 'dark' },
    { label: 'Light', value: 'light' },
    { label: 'Neon', value: 'neon' },
  ];

  const handleToggle = (key) => {
    setSettings(prev => ({
      ...prev,
      [key]: !prev[key]
    }));
  };

  const handleSelect = (key, value) => {
    setSettings(prev => ({
      ...prev,
      [key]: value
    }));
  };

  const saveSettings = async () => {
    setLoading(true);
    try {
      // In a real app, you would save to backend or local storage
      await new Promise(resolve => setTimeout(resolve, 1000));
      Alert.alert('Success', 'Settings saved successfully!');
    } catch (error) {
      Alert.alert('Error', 'Failed to save settings');
    } finally {
      setLoading(false);
    }
  };

  const resetSettings = () => {
    Alert.alert(
      'Reset Settings',
      'Are you sure you want to reset all settings to default?',
      [
        { text: 'Cancel', style: 'cancel' },
        {
          text: 'Reset',
          style: 'destructive',
          onPress: () => {
            setSettings({
              soundEnabled: true,
              vibrationEnabled: true,
              autoSave: true,
              difficulty: 'normal',
              theme: 'dark',
            });
          },
        },
      ]
    );
  };

  const renderSettingItem = ({ icon, title, subtitle, children }) => (
    <View style={styles.settingItem}>
      <View style={styles.settingHeader}>
        <Icon name={icon} size={24} color="#00d4ff" style={styles.settingIcon} />
        <View style={styles.settingText}>
          <Text style={styles.settingTitle}>{title}</Text>
          {subtitle && <Text style={styles.settingSubtitle}>{subtitle}</Text>}
        </View>
      </View>
      <View style={styles.settingControl}>
        {children}
      </View>
    </View>
  );

  const renderToggleSetting = (icon, title, subtitle, key) => (
    <View style={styles.settingItem}>
      <View style={styles.settingHeader}>
        <Icon name={icon} size={24} color="#00d4ff" style={styles.settingIcon} />
        <View style={styles.settingText}>
          <Text style={styles.settingTitle}>{title}</Text>
          {subtitle && <Text style={styles.settingSubtitle}>{subtitle}</Text>}
        </View>
      </View>
      <Switch
        value={settings[key]}
        onValueChange={() => handleToggle(key)}
        trackColor={{ false: '#333', true: '#00d4ff' }}
        thumbColor={settings[key] ? '#ffffff' : '#f4f3f4'}
      />
    </View>
  );

  const renderSelectSetting = (icon, title, subtitle, key, options) => (
    <View style={styles.settingItem}>
      <View style={styles.settingHeader}>
        <Icon name={icon} size={24} color="#00d4ff" style={styles.settingIcon} />
        <View style={styles.settingText}>
          <Text style={styles.settingTitle}>{title}</Text>
          {subtitle && <Text style={styles.settingSubtitle}>{subtitle}</Text>}
        </View>
      </View>
      <View style={styles.optionsContainer}>
        {options.map((option) => (
          <TouchableOpacity
            key={option.value}
            style={[
              styles.optionButton,
              settings[key] === option.value && styles.optionButtonActive
            ]}
            onPress={() => handleSelect(key, option.value)}
          >
            <Text style={[
              styles.optionText,
              settings[key] === option.value && styles.optionTextActive
            ]}>
              {option.label}
            </Text>
          </TouchableOpacity>
        ))}
      </View>
    </View>
  );

  return (
    <LinearGradient
      colors={['#0c0c0c', '#1a1a2e', '#16213e']}
      style={styles.container}
    >
      <ScrollView style={styles.scrollView} showsVerticalScrollIndicator={false}>
        <View style={styles.header}>
          <Text style={styles.headerTitle}>SETTINGS</Text>
          <Text style={styles.headerSubtitle}>Customize your game experience</Text>
        </View>

        <View style={styles.section}>
          <Text style={styles.sectionTitle}>GAMEPLAY</Text>
          
          {renderToggleSetting(
            'volume-up',
            'Sound Effects',
            'Enable game sound effects',
            'soundEnabled'
          )}
          
          {renderToggleSetting(
            'vibration',
            'Vibration',
            'Enable haptic feedback',
            'vibrationEnabled'
          )}
          
          {renderSelectSetting(
            'speed',
            'Difficulty',
            'Choose game difficulty level',
            'difficulty',
            difficultyOptions
          )}
        </View>

        <View style={styles.section}>
          <Text style={styles.sectionTitle}>APPEARANCE</Text>
          
          {renderSelectSetting(
            'palette',
            'Theme',
            'Choose your preferred theme',
            'theme',
            themeOptions
          )}
        </View>

        <View style={styles.section}>
          <Text style={styles.sectionTitle}>DATA</Text>
          
          {renderToggleSetting(
            'save',
            'Auto Save',
            'Automatically save game progress',
            'autoSave'
          )}
        </View>

        <View style={styles.buttonContainer}>
          <TouchableOpacity
            style={styles.saveButton}
            onPress={saveSettings}
            disabled={loading}
          >
            <LinearGradient
              colors={['#00d4ff', '#0099cc']}
              style={styles.saveButtonGradient}
              start={{ x: 0, y: 0 }}
              end={{ x: 1, y: 1 }}
            >
              {loading ? (
                <ActivityIndicator color="#ffffff" />
              ) : (
                <>
                  <Icon name="save" size={20} color="#ffffff" />
                  <Text style={styles.saveButtonText}>SAVE SETTINGS</Text>
                </>
              )}
            </LinearGradient>
          </TouchableOpacity>

          <TouchableOpacity
            style={styles.resetButton}
            onPress={resetSettings}
          >
            <Icon name="refresh" size={20} color="#ff6b6b" />
            <Text style={styles.resetButtonText}>RESET TO DEFAULT</Text>
          </TouchableOpacity>
        </View>
      </ScrollView>
    </LinearGradient>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  scrollView: {
    flex: 1,
  },
  header: {
    alignItems: 'center',
    paddingVertical: 20,
    paddingHorizontal: 20,
  },
  headerTitle: {
    fontSize: 24,
    fontWeight: 'bold',
    color: '#00d4ff',
    fontFamily: 'monospace',
  },
  headerSubtitle: {
    fontSize: 14,
    color: '#888',
    marginTop: 5,
    fontFamily: 'monospace',
  },
  section: {
    marginBottom: 30,
  },
  sectionTitle: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#00d4ff',
    marginBottom: 15,
    paddingHorizontal: 20,
    fontFamily: 'monospace',
  },
  settingItem: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    paddingHorizontal: 20,
    paddingVertical: 15,
    backgroundColor: 'rgba(0, 0, 0, 0.3)',
    marginHorizontal: 20,
    marginBottom: 10,
    borderRadius: 10,
    borderWidth: 1,
    borderColor: 'rgba(0, 212, 255, 0.2)',
  },
  settingHeader: {
    flexDirection: 'row',
    alignItems: 'center',
    flex: 1,
  },
  settingIcon: {
    marginRight: 15,
  },
  settingText: {
    flex: 1,
  },
  settingTitle: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#ffffff',
    fontFamily: 'monospace',
  },
  settingSubtitle: {
    fontSize: 12,
    color: '#888',
    marginTop: 2,
    fontFamily: 'monospace',
  },
  settingControl: {
    alignItems: 'flex-end',
  },
  optionsContainer: {
    flexDirection: 'row',
    gap: 10,
  },
  optionButton: {
    paddingHorizontal: 15,
    paddingVertical: 8,
    borderRadius: 20,
    borderWidth: 1,
    borderColor: '#333',
    backgroundColor: 'rgba(0, 0, 0, 0.5)',
  },
  optionButtonActive: {
    borderColor: '#00d4ff',
    backgroundColor: 'rgba(0, 212, 255, 0.2)',
  },
  optionText: {
    fontSize: 12,
    color: '#888',
    fontFamily: 'monospace',
  },
  optionTextActive: {
    color: '#00d4ff',
    fontWeight: 'bold',
  },
  buttonContainer: {
    paddingHorizontal: 20,
    paddingBottom: 30,
    gap: 15,
  },
  saveButton: {
    borderRadius: 10,
    overflow: 'hidden',
  },
  saveButtonGradient: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'center',
    paddingVertical: 15,
    gap: 10,
  },
  saveButtonText: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#ffffff',
    fontFamily: 'monospace',
  },
  resetButton: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'center',
    paddingVertical: 15,
    borderRadius: 10,
    borderWidth: 1,
    borderColor: '#ff6b6b',
    backgroundColor: 'rgba(255, 107, 107, 0.1)',
    gap: 10,
  },
  resetButtonText: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#ff6b6b',
    fontFamily: 'monospace',
  },
});

export default SettingsScreen;