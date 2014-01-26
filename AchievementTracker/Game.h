#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>
#include "Achievement.h"

using namespace std;

struct classComp {
  bool operator() (const int& lhs, const int& rhs) const
  {
    return lhs<rhs;
  }
};

class Game
{
  unsigned int gameId;
  string gameName;
  int playerCount;

  map<int, Achievement, classComp> achMap;

public:
  Game() {};

  Game(unsigned int _gId, string _gName)
    : gameId(_gId), gameName(_gName), playerCount(0) {};

  void addAchievement(unsigned int _aId, string _aName, unsigned int _aPts)
  {
    achMap[_aId] = Achievement(gameId, _aId, _aName, _aPts);
  }

  string getGameName()
  {
    return gameName;
  }

  void printAllAchs()
  {
    map<int, Achievement, classComp>::iterator it;
    for (it = achMap.begin(); it != achMap.end(); it++)
    {
      cout << "achID: " << it->first
        << ", gameId: " << it->second.getGameId()
        << ", achPts: " << it->second.getAchPts()
        << endl;

    }
  }
};

#endif
