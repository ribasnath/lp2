#include "person.hpp"

bool SaveData(string filename, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ)
{
  ofstream filewriter(filename);
  if(!filewriter.is_open()) return false;

  for(size_t i = 0; i < listPF.size(); i++)
  {
    PersonPF p = listPF.at(i);
    filewriter << "1" << endl
    << p.name << endl
    << p.momName << endl
    << p.cpf << endl
    << p.addr << endl
    << p.tele << endl;
  }

  for(size_t i = 0; i < listPJ.size(); i++)
  {
    PersonPJ p = listPJ.at(i);
    filewriter << "2" << endl
    << p.corpName << endl
    << p.cnpj << endl
    << p.addr << endl
    << p.tele << endl
    << p.capital << endl;
  }

  filewriter.close();
  return true;
}

bool LoadData(string filename, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ)
{
  ifstream filereader(filename);

  if(!filereader.is_open()) return false;

  string tmp;
  while(getline(filereader, tmp))
  {
    if(tmp == "1")
    {
      PersonPF p;
      getline(filereader, p.name);
      getline(filereader, p.momName);
      getline(filereader, p.cpf);
      getline(filereader, p.addr);
      getline(filereader, p.tele);

      listPF.push_back(p);
      continue;
    }

    if(tmp == "2")
    {
      PersonPJ p;
      getline(filereader, p.corpName);
      getline(filereader, p.cnpj);
      getline(filereader, p.addr);
      getline(filereader, p.tele);
      getline(filereader, tmp);
      p.capital = stoi(tmp);

      listPJ.push_back(p);
      continue;
    }
  }

  filereader.close();
  return true;
}

PersonPF addPF()
{
  PersonPF newPF;

  if(fdebug) cout << "Enter with a new PF" << endl;
  if(fdebug) cout << "Name: ";
  getline(cin, newPF.name);

  if(fdebug) cout << "Mother's Name: ";
  getline(cin, newPF.momName);

  if(fdebug) cout << "CPF: ";
  getline(cin, newPF.cpf);

  if(fdebug) cout << "Address: ";
  getline(cin, newPF.addr);

  if(fdebug) cout << "Phone: ";
  getline(cin, newPF.tele);

  return newPF;
}

PersonPJ addPJ()
{
  PersonPJ newPJ;
  string tmp;

  if(fdebug) cout << "Enter with a new PJ" << endl;
  if(fdebug) cout << "Corporate Name: ";
  getline(cin, newPJ.corpName);

  if(fdebug) cout << "CNPJ: ";
  getline(cin, newPJ.cnpj);

  if(fdebug) cout << "Address: ";
  getline(cin, newPJ.addr);

  if(fdebug) cout << "Phone: ";
  getline(cin, newPJ.tele);

  if(fdebug) cout << "Capital: ";
  getline(cin, tmp);
  newPJ.capital = stoi(tmp);

  return newPJ;
}

bool RemovePF(size_t index, vector<PersonPF> &listPF)
{
  if(index > listPF.size())
  {
    if(fdebug) cout << "Error, invalid index." << endl;
    return false;
  }

  listPF.erase(listPF.begin()+index);

  return true;
}

bool RemovePJ(size_t index, vector<PersonPJ> &listPJ)
{
  if(index > listPJ.size())
  {
    if(fdebug) cout << "Error, invalid index." << endl;
    return false;
  }

  listPJ.erase(listPJ.begin()+index);

  return true;
}

bool AscList(vector<string> &names, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ)
{
  for(size_t i = 0; i < listPF.size(); i++)
    names.push_back(listPF.at(i).name);

  for(size_t i = 0; i < listPJ.size(); i++)
    names.push_back(listPJ.at(i).corpName);
  
  cout << "Names in Ascending Order: " << endl;
  sort(names.begin(), names.end());

  for(size_t i = 0; i < names.size(); i++)
    cout << names.at(i) << endl;

  return true;
}