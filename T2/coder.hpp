#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool Encode();
bool Decode();

bool SaveDecod(string filename, vector< pair <unsigned char, size_t > > &table);