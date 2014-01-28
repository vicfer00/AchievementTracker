#include "Database.h"
#include <iomanip>

Database::Database()
{

}

Database::~Database()
{

}
bool scoreCom(const pair<string, unsigned int>& lhs, const pair<string, unsigned int>& rhs)
{
  return rhs.second < lhs.second;
}


void Database::addPlayer(unsigned int _pId, string _pName)
{
  playerMap[_pId] = Player(_pId, _pName);
  cout << "AddPlayer " << _pId << " " << _pName << " - DONE." << endl;
  cout << endl;
}

void Database::addGame(unsigned int _gId, string _gName)
{
  gameMap[_gId] = Game(_gId, _gName);
  cout << "AddGame " << _gId << " " << _gName << " - DONE." << endl;
  cout << endl;
}

void Database::addAchievement(unsigned int _gId, unsigned int _aId, string _aName, unsigned int _aPts)
{
  gameMap[_gId].addAchievement(_aId, _aName, _aPts);
  cout << "AddAchievement " << _gId << " " << _aId << " " << _aName << " " << _aPts << " - DONE." << endl;
  cout << endl;
}

void Database::plays(unsigned int _pId, unsigned int _gId, string _pIgn)
{
  game_Itr gItr = gameMap.find(_gId);
  playerMap[_pId].plays(gItr, _pIgn);
  cout << "Plays " << _pId << " " << _gId << " " << _pIgn << " - DONE." << endl;
  cout << endl;
}

void Database::addFriends(unsigned int _pId1, unsigned int _pId2)
{
  player_Itr pItr1 = playerMap.find(_pId1);
  player_Itr pItr2 = playerMap.find(_pId2);
  pItr1->second.addFriends(pItr2);
  pItr2->second.addFriends(pItr1);
  cout << "AddFriends " << _pId1 << " " << _pId2 << " - DONE." << endl;
  cout << endl;
}

void Database::achieve(unsigned int _pId, unsigned int _gId, unsigned int _aId)
{
  ach_Itr it = gameMap[_gId].getAchItr(_aId);
  playerMap[_pId].achieve(_gId, it);
  cout << "Achieve " << _pId << " " << _gId << " " << _aId << " - DONE." << endl;
  cout << endl;
}

void Database::friendsWhoPlay(unsigned int _pId, unsigned int _gId)
{
  Player p = playerMap[_pId];
  Game g = gameMap[_gId];

  cout << endl;

  bool atLeastOne = false;
  for (int i = 0; i < p.friends.size(); i++)
  {
    Player friendPlayer = p.friends[i]->second;
    if (friendPlayer.plays(_gId))
    {
      if (!atLeastOne)
      {
        cout << "Friends with " << p.getPlayerName()
          << " who play \'" << g.getGameName()
          << "\':"
          << endl;
        atLeastOne = true;
      }

      cout << friendPlayer.getPlayerName() << endl;
    }
  }
  cout << "FriendsWhoPlay " << _pId << " " << _gId << " - DONE." << endl;
  cout << endl;
}

void Database::comparePlayers(unsigned int _pId1, unsigned int _pId2, unsigned int _gId)
{

  cout << endl;
  cout << "ComparePlayers " << _pId1 << " " << _pId2 << " " << _gId << " - DONE." << endl;
  cout << endl;
}

void Database::summarizePlayer(unsigned int _pId)
{
  Player p = playerMap[_pId];

  cout << endl;
  cout << "Player: " << p.getPlayerName() << "\tTotal Gamerscore: " << p.getPlayerPts() << " pts";
  cout << endl << endl;
  cout << left 
    << setw(WIDTH_TITLE) << " "
    << setw(WIDTH_GAME_NAME) << "Name"
    << setw(WIDTH_NUMBER) << "Achievements"
    << setw(WIDTH_GMR_SCORE) << "Gamerscore"
    << setw(WIDTH_IGN) << "IGN";
  cout << endl;
  cout << setw(WIDTH_TITLE) << " " 
    << "--------------------------------------------------------------------";
  cout << endl;

  for (int i = 0; i < p.gameEntries.size(); i++)
  {
    Player::gameEntry g_entry = p.gameEntries[i];

    string gameName = to_string(i + 1) + ". " + g_entry.getGameName();
    string achievements = to_string(g_entry.getEntryNumAchs()) + "/" + to_string(g_entry.getGameNumAchs());
    string gamerscore = to_string(g_entry.getEntryPts()) + " pts";
    string ign = g_entry.getPlayerIgn();

    if (i == 0)
    {
      cout << setw(WIDTH_TITLE) << "Games:";
    }
    else
    {
      cout << setw(WIDTH_TITLE) << " ";
    }

    cout << left
      << setw(WIDTH_GAME_NAME) << gameName
      << setw(WIDTH_NUMBER) << achievements
      << setw(WIDTH_GMR_SCORE) << gamerscore
      << setw(WIDTH_IGN) << ign
      << endl;
  }

  cout << endl;
  cout << left
    << setw(WIDTH_TITLE) << " "
    << setw(WIDTH_PLAYER_NAME) << "Name"
    << setw(WIDTH_GMR_SCORE) << "Gamerscore";
  cout << endl;
  cout << setw(WIDTH_TITLE) << " " 
    << "--------------------------------------------------------------------";
  cout << endl;
  for (int i = 0; i < p.friends.size(); i++)
  {
    Player f = p.friends[i]->second;

    string playerName = to_string(i + 1) + ". " + f.getPlayerName();
    string gamerscore = to_string(f.getPlayerPts()) + " pts";

    if (i == 0)
    {
      cout << setw(WIDTH_TITLE) << "Friends:";
    }
    else
    {
      cout << setw(WIDTH_TITLE) << " ";
    }

    cout << left
      << setw(WIDTH_PLAYER_NAME) << playerName
      << setw(WIDTH_GMR_SCORE) << gamerscore
      << endl;
  }


  cout << endl;
  cout << "SummarizePlayer " << _pId << " - DONE." << endl;
  cout << endl;
}

void Database::summarizeGame(unsigned int _gId)
{ 
  Game g = gameMap[_gId];
  cout << endl;
  cout << "Game: " << g.getGameName();
  cout << endl << endl;

  cout << left
    << setw(WIDTH_TITLE) << " "
    << setw(WIDTH_PLAYER_NAME) << "Name"
    << setw(WIDTH_NUMBER) << "Achievements"
    << setw(WIDTH_GMR_SCORE) << "Gamerscore"
    << setw(WIDTH_IGN) << "IGN";
  cout << endl;
  cout << setw(WIDTH_TITLE) << " "
    << "---------------------------------------------------------------------";
  cout << endl;

 int count = 0;

  // print record of all players who play given game

  // loop through each player
  for (player_Itr pItr = playerMap.begin(); pItr != playerMap.end(); pItr++)
  {
    Player p = pItr->second;
    // loop through each of the games the player plays
    for (int i = 0; i < p.gameEntries.size(); i++)
    {
      // see whether player plays given game
      if (p.gameEntries[i].getGameId() == _gId)
      {
        // print player's info in given game
        count++;

        Player::gameEntry g_entry = p.gameEntries[i];

        string playerName = to_string(count) + ". " + p.getPlayerName();
        string achievements = to_string(g_entry.getEntryNumAchs()) + "/" + to_string(g_entry.getGameNumAchs());
        string gamerscore = to_string(g_entry.getEntryPts()) + " pts";
        string ign = g_entry.getPlayerIgn();

        if (count == 1)
        {
          cout << setw(WIDTH_TITLE) << "Players:";
        }
        else
        {
          cout << setw(WIDTH_TITLE) << " ";
        }

        cout << left
          << setw(WIDTH_GAME_NAME) << playerName
          << setw(WIDTH_NUMBER) << achievements
          << setw(WIDTH_GMR_SCORE) << gamerscore
          << setw(WIDTH_IGN) << ign
          << endl;
        break;
      }
    }
    
  }
  cout << endl;

  count = 0;
  //print all achievements associated with given game
  cout << left
    << setw(WIDTH_TITLE_ACHIEVEMENT) << " "
    << setw(WIDTH_ACHIEVEMENT_NAME) << "Name"
    << setw(WIDTH_DEFAULT) << "Times Completed";
  cout << endl;
  cout << setw(WIDTH_TITLE_ACHIEVEMENT) << " "
    << "----------------------------------------------------------------";
  cout << endl;

  //loop through all achievements of given game
  for (ach_Itr aItr = g.achMap.begin(); aItr != g.achMap.end(); aItr++)
  {
    Achievement a = aItr->second;
    count++;

    string achName = to_string(count) + ". " + a.getAchName();
    string timeCompleted = to_string(a.getTimesCompleted());

    if (count == 1)
    {
      cout << setw(WIDTH_TITLE_ACHIEVEMENT) << "Achievements:";
    }
    else
    {
      cout << setw(WIDTH_TITLE_ACHIEVEMENT) << " ";
    }

    cout << left
      << setw(WIDTH_ACHIEVEMENT_NAME) << achName
      << setw(WIDTH_NUMBER) << timeCompleted
      << endl;
  }


  cout << endl;
  cout << "SummarizeGame " << _gId << " - DONE." << endl;
  cout << endl;
}

void Database::summarizeAchievement(unsigned int _gId, unsigned int _aId)
{
  Game g = gameMap[_gId];
  Achievement a = g.achMap[_aId];

  cout << endl;
  cout << "Achievement '" << a.getAchName()
    << "' in '" << g.getGameName() << "'" << endl;
  cout << "-> " << a.getTimesCompleted() << " out of " << g.getPlayerCount()
    << " players who play this game completed this Achievement.";
  cout << endl << endl;

  cout << left
    << setw(WIDTH_TITLE) << " "
    << setw(WIDTH_PLAYER_NAME) << "Name"
    << setw(WIDTH_IGN) << "IGN";
  cout << endl;
  cout << setw(WIDTH_TITLE) << " "
    << "---------------------------------------------------------------------";
  cout << endl;

  int count = 0;

  // loop through each player
  for (player_Itr pItr = playerMap.begin(); pItr != playerMap.end(); pItr++)
  {
    Player p = pItr->second;

    // loop through each game the player plays
    for (int i = 0; i < p.gameEntries.size(); i++)
    {
      Player::gameEntry g_entry = p.gameEntries[i];
      // check for gId match
      if (g_entry.getGameId() == _gId)
      {
        // loop through each achievement this player has in this game
        for (int j = 0; j < g_entry.achVec.size(); j++)
        {
          Achievement  a_temp = g_entry.achVec[j]->second;
          // check for aId match
          if (a_temp.getAchId() == _aId)
          {
            count++;

            // print player's info
            string playerName = to_string(count) + ". " + p.getPlayerName();
            string ign = g_entry.getPlayerIgn();

            if (count == 1)
            {
              cout << setw(WIDTH_TITLE) << "Players:";
            }
            else
            {
              cout << setw(WIDTH_TITLE) << " ";
            }

            cout << left
              << setw(WIDTH_PLAYER_NAME) << playerName
              << setw(WIDTH_IGN) << ign
              << endl;
            break;
          }
        }

        break;
      }
    }
  }

  cout << endl;
  cout << "SummarizeAchievement " << _gId << " " << _aId << " " << " - DONE." << endl;
  cout << endl;
}

void Database::achievementRanking()
{
  // sort the players by their score
  vector<pair<string, unsigned int>> v;
  for (player_Itr pItr = playerMap.begin(); pItr != playerMap.end(); pItr++)
  {
    Player p = pItr->second;
    v.push_back(pair<string, unsigned int>(p.getPlayerName(), p.getPlayerPts()));
  }

  sort(v.begin(), v.end(), scoreCom);

  cout << left
    << setw(WIDTH_TITLE) << " "
    << setw(WIDTH_PLAYER_NAME) << "Name"
    << setw(WIDTH_NUMBER) << "Gamerscore";
  cout << endl;
  cout << setw(WIDTH_TITLE) << " "
    << "---------------------------------------------------------------------";
  cout << endl;

  for (int i = 0; i < v.size(); i++)
  {
    string playerName = to_string(i + 1) + ". " + v[i].first;
    string gamerscore = to_string(v[i].second) + " pts";

    if (i == 0)
    {
      cout << setw(WIDTH_TITLE) << "Players:";
    }
    else
    {
      cout << setw(WIDTH_TITLE) << " ";
    }

    cout << left
      << setw(WIDTH_PLAYER_NAME) << playerName
      << setw(WIDTH_GMR_SCORE) << gamerscore
      << endl;
  }


  cout << endl;
  cout << "AchievementRanking " << " - DONE." << endl;
  cout << endl;
}

void Database::processInput(string input)
{
  //cout << ">";

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
    else if (op.compare("SummarizePlayer") == 0)
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


