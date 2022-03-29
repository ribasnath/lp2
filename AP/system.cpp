#include "system.hpp"

bool Menu()
{
    Teacher t;
    Student s;
    char op;

    while(true)
    {
        cout << " ---------- MENU ---------- " << endl;
        cout << " 1 - Login como Aluno " << endl;
        cout << " 2 - Login como Professor " << endl;
        cout << " 3 - Primeiro Acesso " << endl;
        cout << " 4 - Sair " << endl;
        cout << "Escolha: ";
        cin >> op;

        if(op == '1')
        {
            s.LogIn();
            continue;
        }
        else if(op == '2')
        {
            t.LogIn();
            continue;
        }
        else if(op == '3')
        {
            size_t ch;

            cout << "1 - Professor" << endl;
            cout << "2 - Aluno" << endl;
            cin >> ch;

            if(ch == 1)
                t.SignUp();
            else if(ch == 2)
                s.SignUp();
            else
            {
                cout << "Codigo invalido." << endl;
                return false;
            }

            continue;
        }
        else if(op == '4') break;
        else
        {
            cout << "Codigo invalido." << endl;
            continue;
        }
    }

    return true;
}
