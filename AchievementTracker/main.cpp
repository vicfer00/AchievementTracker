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
  //map<int, string>::iterator it = 

  Database db;
  while(true)
  {
    db.processInput();
  }

	return 0;
}
