#include <iostream>
#include <string>
#include <map>
#include <regex>

#include "Player.h"
#include "Achievement.h"
#include "Game.h"

using namespace std;


// formatting variables
#define MAX_CHAR 4096
#define WIDTH_NUMBER 15
#define WIDTH_GAME_NAME 20
#define WIDTH_ACHIEVEMENT_NAME 25
#define WIDTH_GMR_SCORE  15
#define WIDTH_IGN 15
#define WIDTH_PLAYER_NAME 20
#define WIDTH_TITLE 10
#define WIDTH_LONG_TITLE 20
#define WIDTH_DEFAULT 20
#define WIDTH_TITLE_ACHIEVEMENT 15
#define WIDTH_COMPARE 28
#define WIDTH_MAX 80



class Database
{
private:
  map<int, Player> playerMap;
  map<int, Game> gameMap;

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