#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
using namespace std;

class Achievement
{
  unsigned int achId;
  string achName;
  unsigned int gameId;
  unsigned int achPts;

public:
  Achievement() {};
  Achievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts)
    : achId(_aId), achName(_aName), gameId(_gId), achPts(_aPts) {};
  unsigned int getGameId()
  {
    return gameId;
  }
  unsigned int getAchPts()
  {
    return achPts;
  }
};

#endif
