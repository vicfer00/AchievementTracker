// main.cpp : Defines the entry point for the console application.
//
#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string>
#include "Database.h"

// debug
#include <fstream>
#include <Windows.h>

using namespace std;

void processInput();


int main(int argc, char* argv[])
{
  Database db;
  char in[MAX_CHAR];
  ifstream ifs;
  ifs.open("debug.dat");
  cout << "Successfully opened data file." << endl;
  while (ifs.good() && !ifs.eof()) {
    ifs.getline(in, MAX_CHAR);
    db.processInput(string(in));
  }

  Sleep(100000);
  //while(true)
  //{
   // db.processInput();
  //}

	return 0;
}
