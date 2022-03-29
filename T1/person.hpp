#ifndef H_PERSON
#define H_PERSON

#define fdebug 0

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;

struct PersonPF
{
  string name;
  string momName;
  string cpf;
  string addr;
  string tele;
};

struct PersonPJ
{
  string corpName;
  string cnpj;
  string addr;
  string tele;
  size_t capital;
};

bool SaveData(string filename, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ);

bool LoadData(string filename, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ);

bool RemovePF(size_t index, vector<PersonPF> &listPF);
bool RemovePJ(size_t index, vector<PersonPJ> &listPJ);

PersonPF addPF();
PersonPJ addPJ();

bool AscList(vector<string> &names, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ);

#endif