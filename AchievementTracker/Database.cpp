#include "Database.h"

Database::Database()
{

}

Database::~Database()
{

}
void Database::addPlayer(unsigned int _pId, string _pName)
{
  playerMap[_pId] = Player(_pId, _pName);
  cout << "AddPlayer " << _pId << " " << _pName << " - DONE." << endl;
}
void Database::addGame(unsigned int _gId, string _gName)
{
  gameMap[_gId] = Game(_gId, _gName);
  cout << "AddGame " << _gId << " " << _gName << " - DONE." << endl;
}
void Database::addAchievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts)
{
  gameMap[_gId].addAchievement(_aId, _aName, _aPts);
  cout << "AddAchievement " << _gId << " " << _aId << " " << _aName << " " << _aPts << " - DONE." << endl;
  //gameMap[_gId].printAllAchs();
}
void Database::plays(unsigned int _pId, unsigned int _gId, string _pIgn)
{
  cout << "Plays " << _pId << " " << _gId << " " << _pIgn << " - DONE." << endl;
}
void Database::addFriends(unsigned int _pId1, unsigned int _pId2)
{
  cout << "AddFriends " << _pId1 << " " << _pId2 << " - DONE." << endl;
}
void Database::achieve(unsigned int _pId, unsigned int _gId, unsigned int _aId)
{
  cout << "Achieve " << _pId << " " << _gId << " " << _aId << " - DONE." << endl;
}
void Database::friendsWhoPlay(unsigned int _pId, unsigned int _gId)
{
  cout << "FriendsWhoPlay " << _pId << " " << _gId << " - DONE." << endl;
}
void Database::comparePlayers(unsigned int _pId1, unsigned int _pId2, unsigned int _gId)
{
  cout << "ComparePlayers " << _pId1 << " " << _pId2 << " " << _gId << " - DONE." << endl;
}
void Database::summarizePlayer(unsigned int _pId)
{
  cout << "SummarizePlayer " << _pId << " - DONE." << endl;
}
void Database::summarizeGame(unsigned int _gId)
{
  cout << "SummarizeGame " << _gId << " - DONE." << endl;
}
void Database::summarizeAchievement(unsigned int _gId, unsigned int _aId)
{
  cout << "SummarizeAchievement " << _gId << " " << _aId << " " << " - DONE." << endl;
}
void Database::achievementRanking()
{
  cout << "AchievementRanking " << " - DONE." << endl;
}

void Database::processInput()
{
  cout << ">";

  string input;
  getline(cin, input);

  smatch m;

  if (regex_search(input, m, regex("^[[:blank:]]*([a-zA-Z]+)[[:blank:]]*")))
  {
    string op = m[1].str();

    // strip off operation keyword, get remainder of input string
    input = m.suffix().str();

    if (op.compare("AddPlayer") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+\"(.+?)\"");
      if (regex_search(input, m, e))
      {
        //for (auto x : m) cout << "<" << x << "> ";
        addPlayer(stoi(m[1].str()), m[2].str());
      }
    }
    else if (op.compare("AddGame") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+\"(.+?)\"");
      if (regex_search(input, m, e))
      {
        addGame(stoi(m[1].str()), m[2].str());
      }
    }
    else if (op.compare("AddAchievement") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)[[:blank:]]+\"(.+?)\"[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        addAchievement(stoi(m[1].str()), stoi(m[2].str()), m[3].str(), stoi(m[4].str()));
      }
    }
    else if (op.compare("Plays") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)[[:blank:]]+\"(.+?)\"");
      if (regex_search(input, m, e))
      {
        plays(stoi(m[1].str()), stoi(m[2].str()), m[3].str());
      }
    }
    else if (op.compare("AddFriends") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        addFriends(stoi(m[1].str()), stoi(m[2].str()));
      }
    }
    else if (op.compare("Achieve") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        achieve(stoi(m[1].str()), stoi(m[2].str()), stoi(m[3].str()));
      }
    }
    else if (op.compare("FriendsWhoPlay") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        friendsWhoPlay(stoi(m[1].str()), stoi(m[2].str()));
      }
    }
    else if (op.compare("ComparePlayers") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        comparePlayers(stoi(m[1].str()), stoi(m[2].str()), stoi(m[3].str()));
      }
    }
    else if (op.compare("SummerizePlayer") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)");
      if (regex_search(input, m, e))
      {
        summarizePlayer(stoi(m[1].str()));
      }
    }
    else if (op.compare("SummarizeGame") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)");
      if (regex_search(input, m, e))
      {
        summarizeGame(stoi(m[1].str()));
      }
    }
    else if (op.compare("SummarizeAchievement") == 0)
    {
      regex e("^[[:blank:]]*([0-9]+)[[:blank:]]+([0-9]+)");
      if (regex_search(input, m, e))
      {
        summarizeAchievement(stoi(m[1].str()), stoi(m[2].str()));
      }
    }
    else if (op.compare("AchievementRanking") == 0)
    {
      achievementRanking();
    }
    
  }



}


