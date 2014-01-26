#include <iostream>
#include <string>
#include <map>
#include <regex>

#include "Player.h"
#include "Achievement.h"
#include "Game.h"

using namespace std;

class Database
{
private:
  map<int, Player, classComp> playerMap;
  map<int, Game, classComp> gameMap;
  map<int, Achievement, classComp> achMap;


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