#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
  unsigned int playerId;
  string playerName;


public:
  Player() {};

  Player(unsigned int _pId, string _pName)
    : playerId(_pId), playerName(_pName) {};
};

#endif PLAYER_H
