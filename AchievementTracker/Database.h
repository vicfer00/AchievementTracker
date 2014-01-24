#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;

class Game
{
  unsigned int gameId;
  string gameName;
  int playerCount;

public:
  Game() {};

  Game(unsigned int _gId, string _gName) 
    : gameId(_gId), gameName(_gName), playerCount(0) {};
};

class Player
{
  unsigned int playerId;
  string playerName;

public:
  Player() {};

  Player(unsigned int _pId, string _pName) 
    : playerId(_pId), playerName(_pName) {};
};

class Achievement
{
  unsigned int achId;
  string achName;
  unsigned int gameId;
  unsigned int achPoints;

public:
  Achievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts)
    : achId(_aId), achName(_aName), gameId(_gId), achPoints(_aPts) {};
};

struct classComp {
  bool operator() (const int& lhs, const int& rhs) const
  {
    return lhs<rhs;
  }
};

class Database
{
private:
  map<int, Player, classComp> playerMap;
  map<int, Game, classComp> gameMap;
  map<int, Achievement, classComp> achievementMap;


public:
  Database();

  ~Database();

  void addPlayer(unsigned int _pId, string _pName);
  void addGame(unsigned int _gId, string _gName);
  void addAchievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts);
  void plays(unsigned int _pId, unsigned int _gId, string _pIgn);
  void addFriends(unsigned int _pId1, unsigned int _pId2);
  void achieve(unsigned int _pId, unsigned int _gId, unsigned int _aId);
  void friendsWhoPlay(unsigned int _pId, unsigned int _gId);
  void comparePlayers(unsigned int _pId1, unsigned int _pId2, unsigned int _gId);
  void summarizePlayer(unsigned int _pId);
  void summarizeGame(unsigned int _gId);
  void summarizeAchievement(unsigned int _gId, unsigned int _aId);
  void achievementRanking();

  void processInput();
};