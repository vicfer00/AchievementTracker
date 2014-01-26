// main.cpp : Defines the entry point for the console application.
//
#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string>
#include "Database.h"

using namespace std;

void processInput();

int main(int argc, char* argv[])
{
  map<int, string> m;
  map<int, string, classComp>::iterator it = m.insert(m.begin(), pair<int, string>(50, string("this is a string")));
  m.insert(m.begin(), pair<int, string>(10, string("this is another string")));
  m.insert(m.begin(), pair<int, string>(100, string("this is a bigger string")));


  std::cout << it->first << " => " << it->second << '\n';
  for (it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  printf("Size of iterator : %d\n", sizeof(map<int, int>::iterator));

  Database db;
  while(true)
  {
    db.processInput();
  }

	return 0;
}
