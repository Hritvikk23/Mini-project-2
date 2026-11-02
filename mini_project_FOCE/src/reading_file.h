#pragma once
#include <string>
#include <vector>
using namespace std;

bool readFile(const string &filename, vector<string> &lines);
vector<string> splitline(const string &line);