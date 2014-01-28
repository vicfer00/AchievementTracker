#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Game.h"

using namespace std;

class Player;
typedef map<int, Player>::iterator player_Itr;

class Player
{
  unsigned int playerId;
  string playerName;
  unsigned int playerPts;

  // class storing IGN and achievements
  class gameEntry;
  
public:
    // vector storing games this player plays
  vector<gameEntry> gameEntries;

  // vector storing iterators to friends
  vector<player_Itr> friends;
  
  Player() {};

  Player(unsigned int _pId, string _pName)
    : playerId(_pId), playerName(_pName), playerPts(0) {};

  //
  void plays(game_Itr _gItr, string _pIgn)
  {
    gameEntry g = gameEntry(_gItr, _pIgn);
    gameEntries.push_back(g);
  }

  void addFriends(player_Itr _pItr)
  {
    friends.push_back(_pItr);
  }

  void achieve(unsigned int _gId, ach_Itr _achItr)
  {
    // add achievement onto achievement list in corresponding gameEntry
    for (vector<gameEntry>::iterator it = gameEntries.begin(); it != gameEntries.end(); it++)
    {
      if (it->getGameId() == _gId)
      {
        it->insertAch(_achItr);
        _achItr->second.incrementTimesAchieved();
        playerPts += _achItr->second.getAchPts();
        break;
      }
    }
  }

  string getPlayerName()
  {
    return playerName;
  }

  unsigned int getPlayerPts()
  {
    return playerPts;
  }

  bool plays(unsigned int _gId)
  {
    for (int i = 0; i < gameEntries.size(); i++)
    {
      if (gameEntries[i].getGameId() == _gId)
        return true;
    }
    return false;
  }

  class gameEntry
  {
    game_Itr gameItr;
    string playerIgn;

  public:
    vector<ach_Itr> achVec;
    gameEntry() {};
    gameEntry(game_Itr _gItr, string _pIgn)
    {
      gameItr = _gItr;
      playerIgn = _pIgn;

      // increment player count in game
      gameItr->second.incrementPlayerCount();
    }

    void insertAch(ach_Itr _achItr)
    {
      achVec.push_back(_achItr);
    }
    unsigned int getGameId()
    {
      return gameItr->second.getGameId();
    }
    string getGameName()
    {
      return gameItr->second.getGameName();
    }
    unsigned int getGameNumAchs()
    {
      return gameItr->second.getNumAchs();
    }
    unsigned int getEntryNumAchs()
    {
      return achVec.size();
    }
    string getPlayerIgn()
    {
      return playerIgn;
    }

    unsigned int getEntryPts()
    {
      int s = 0;
      for (int i = 0; i < achVec.size(); i++)
      {
        s += achVec[i]->second.getAchPts();
      }
      return s;
    }
  };
};

#endif
