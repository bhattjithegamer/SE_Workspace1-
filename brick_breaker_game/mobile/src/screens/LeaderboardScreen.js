import React, { useState, useEffect } from 'react';
import {
  View,
  Text,
  StyleSheet,
  FlatList,
  TouchableOpacity,
  ActivityIndicator,
  RefreshControl,
  Alert,
} from 'react-native';
import LinearGradient from 'react-native-linear-gradient';
import Icon from 'react-native-vector-icons/MaterialIcons';

const LeaderboardScreen = () => {
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);
  const [refreshing, setRefreshing] = useState(false);

  const fetchScores = async () => {
    try {
      const response = await fetch('http://localhost:5000/api/scores');
      const data = await response.json();
      setScores(data);
    } catch (error) {
      console.error('Failed to fetch scores:', error);
      Alert.alert('Error', 'Failed to load leaderboard');
    } finally {
      setLoading(false);
      setRefreshing(false);
    }
  };

  useEffect(() => {
    fetchScores();
  }, []);

  const onRefresh = () => {
    setRefreshing(true);
    fetchScores();
  };

  const renderScoreItem = ({ item, index }) => {
    const getMedalIcon = (position) => {
      switch (position) {
        case 0:
          return '🥇';
        case 1:
          return '🥈';
        case 2:
          return '🥉';
        default:
          return null;
      }
    };

    const getBackgroundColor = (position) => {
      switch (position) {
        case 0:
          return ['#ffd700', '#ffed4e'];
        case 1:
          return ['#c0c0c0', '#e5e5e5'];
        case 2:
          return ['#cd7f32', '#daa520'];
        default:
          return ['rgba(0, 0, 0, 0.3)', 'rgba(0, 0, 0, 0.5)'];
      }
    };

    const formatDate = (dateString) => {
      const date = new Date(dateString);
      return date.toLocaleDateString();
    };

    return (
      <LinearGradient
        colors={getBackgroundColor(index)}
        style={styles.scoreItem}
        start={{ x: 0, y: 0 }}
        end={{ x: 1, y: 1 }}
      >
        <View style={styles.scoreLeft}>
          <Text style={[styles.rankText, index < 3 && styles.rankTextMedal]}>
            {getMedalIcon(index) || `${index + 1}.`}
          </Text>
          <View style={styles.playerInfo}>
            <Text style={[styles.playerName, index < 3 && styles.playerNameMedal]}>
              {item.player}
            </Text>
            <Text style={[styles.dateText, index < 3 && styles.dateTextMedal]}>
              {formatDate(item.date_created)}
            </Text>
          </View>
        </View>
        <View style={styles.scoreRight}>
          <Text style={[styles.scoreValue, index < 3 && styles.scoreValueMedal]}>
            {item.score}
          </Text>
          <Text style={[styles.levelText, index < 3 && styles.levelTextMedal]}>
            Level {item.level}
          </Text>
        </View>
      </LinearGradient>
    );
  };

  const renderEmptyList = () => (
    <View style={styles.emptyContainer}>
      <Icon name="leaderboard" size={64} color="#666" />
      <Text style={styles.emptyText}>No scores yet</Text>
      <Text style={styles.emptySubtext}>Be the first to play!</Text>
    </View>
  );

  if (loading) {
    return (
      <LinearGradient
        colors={['#0c0c0c', '#1a1a2e', '#16213e']}
        style={styles.container}
      >
        <View style={styles.loadingContainer}>
          <ActivityIndicator size="large" color="#00d4ff" />
          <Text style={styles.loadingText}>Loading leaderboard...</Text>
        </View>
      </LinearGradient>
    );
  }

  return (
    <LinearGradient
      colors={['#0c0c0c', '#1a1a2e', '#16213e']}
      style={styles.container}
    >
      <View style={styles.header}>
        <Text style={styles.headerTitle}>TOP SCORES</Text>
        <Text style={styles.headerSubtitle}>Best players of all time</Text>
      </View>

      <FlatList
        data={scores}
        renderItem={renderScoreItem}
        keyExtractor={(item) => item.id.toString()}
        style={styles.list}
        contentContainerStyle={styles.listContent}
        showsVerticalScrollIndicator={false}
        refreshControl={
          <RefreshControl
            refreshing={refreshing}
            onRefresh={onRefresh}
            tintColor="#00d4ff"
            colors={['#00d4ff']}
          />
        }
        ListEmptyComponent={renderEmptyList}
      />
    </LinearGradient>
  );
};

const styles = StyleSheet.create({
  container: {
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
  list: {
    flex: 1,
  },
  listContent: {
    paddingHorizontal: 20,
    paddingBottom: 20,
  },
  scoreItem: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: 15,
    marginVertical: 5,
    borderRadius: 10,
    borderWidth: 1,
    borderColor: 'rgba(0, 212, 255, 0.3)',
  },
  scoreLeft: {
    flexDirection: 'row',
    alignItems: 'center',
    flex: 1,
  },
  rankText: {
    fontSize: 18,
    fontWeight: 'bold',
    color: '#00d4ff',
    marginRight: 15,
    fontFamily: 'monospace',
  },
  rankTextMedal: {
    color: '#000',
  },
  playerInfo: {
    flex: 1,
  },
  playerName: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#ffffff',
    fontFamily: 'monospace',
  },
  playerNameMedal: {
    color: '#000',
  },
  dateText: {
    fontSize: 12,
    color: '#888',
    marginTop: 2,
    fontFamily: 'monospace',
  },
  dateTextMedal: {
    color: '#333',
  },
  scoreRight: {
    alignItems: 'flex-end',
  },
  scoreValue: {
    fontSize: 20,
    fontWeight: 'bold',
    color: '#00d4ff',
    fontFamily: 'monospace',
  },
  scoreValueMedal: {
    color: '#000',
  },
  levelText: {
    fontSize: 12,
    color: '#888',
    marginTop: 2,
    fontFamily: 'monospace',
  },
  levelTextMedal: {
    color: '#333',
  },
  emptyContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    paddingVertical: 50,
  },
  emptyText: {
    fontSize: 18,
    color: '#666',
    marginTop: 20,
    fontFamily: 'monospace',
  },
  emptySubtext: {
    fontSize: 14,
    color: '#888',
    marginTop: 5,
    fontFamily: 'monospace',
  },
  loadingContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  loadingText: {
    fontSize: 16,
    color: '#00d4ff',
    marginTop: 20,
    fontFamily: 'monospace',
  },
});

export default LeaderboardScreen;