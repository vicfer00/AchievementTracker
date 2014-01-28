#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>
#include "Achievement.h"

using namespace std;

class Game;
typedef map<int, Game>::iterator game_Itr;


class Game
{
  unsigned int gameId;
  string gameName;
  unsigned int playerCount;

public:
  map<int, Achievement> achMap;

  Game() {};

  Game(unsigned int _gId, string _gName)
    : gameId(_gId), gameName(_gName), playerCount(0) {};

  void addAchievement(unsigned int _aId, string _aName, unsigned int _aPts)
  {
    achMap[_aId] = Achievement(gameId, _aId, _aName, _aPts);
  }

  void incrementPlayerCount()
  {
    playerCount++;
  }

  string getGameName()
  {
    return gameName;
  }

  unsigned int getGameId()
  {
    return gameId;
  }

  unsigned int getNumAchs()
  {
    return achMap.size();
  }

  unsigned int getPlayerCount()
  {
    return playerCount;
  }

  ach_Itr getAchItr(unsigned int _aId)
  {
    return achMap.find(_aId);
  }
};

#endif
