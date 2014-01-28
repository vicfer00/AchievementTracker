#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
using namespace std;

class Achievement;
typedef map<int, Achievement>::iterator ach_Itr;

class Achievement
{
  unsigned int achId;
  string achName;
  unsigned int gameId;
  unsigned int achPts;
  unsigned int timesAchieved;
public:
  Achievement() {};
  Achievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts)
    : achId(_aId), achName(_aName), gameId(_gId), achPts(_aPts), timesAchieved(0) {};
  void incrementTimesAchieved()
  {
    timesAchieved++;
  }
  unsigned int getAchId()
  {
    return achId;
  }
  unsigned int getGameId()
  {
    return gameId;
  }
  unsigned int getAchPts()
  {
    return achPts;
  }
  unsigned int getTimesCompleted()
  {
    return timesAchieved;
  }
  string getAchName()
  {
    return achName;
  }
};

#endif
