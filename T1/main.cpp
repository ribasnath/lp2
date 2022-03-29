/*
####################################
# DEC7532-02655                    #
# Aluna: Nathália Geraldino Ribas  #
# Matrícula: 20250334              #
####################################
*/

#include "person.hpp"

int main()
{
  vector<PersonPF> listPF;
  vector<PersonPJ> listPJ;

  LoadData("database.dat", listPF, listPJ);

  while(true)
  {
    SaveData("database.dat", listPF, listPJ);

    char op;

    if(fdebug) cout << "MY PAPA'S COMPANY - SIG" << endl;
    if(fdebug) cout << "1. Add PF..." << endl;
    if(fdebug) cout << "2. Add PJ..." << endl;
    if(fdebug) cout << "3. Remove PF by Index..." << endl;
    if(fdebug) cout << "4. Remove PJ by Index..." << endl;
    if(fdebug) cout << "5. Print Names in Ascending Order" << endl;
    if(fdebug) cout << "6. Exit" << endl;
    if(fdebug) cout << "Option: ";

    cin >> op;

    cin.ignore();

    if(op == '1')
    {
      PersonPF newPF = addPF();
      listPF.push_back(newPF);
      continue;
    }

    if(op == '2')
    {
      PersonPJ newPJ = addPJ();
      listPJ.push_back(newPJ);
      continue;
    }

    if(op == '3')
    {
      size_t index;

      if(fdebug) cout << "Enter a index to remove: ";
      cin >> index;

      RemovePF(index, listPF);
      continue;
    }

    if(op == '4')
    {
      size_t index;

      if(fdebug) cout << "Enter a index to remove: ";
      cin >> index;

      RemovePJ(index, listPJ);

      continue;
    }

    if(op == '5')
    {
      vector<string> names;

      AscList(names, listPF, listPJ);

      continue;
    }

    if(op == '6') break;
  }


  return 0;
}