/*
####################################
# DEC7532-02655                    #
# Aluna: Nathália Geraldino Ribas  #
# Matrícula: 20250334              #
####################################
*/

#include "coder.hpp"

int main()
{
    string filename;
        
    while(true)
    {
        char op;

        cout << "! Menu !" << endl;
        cout << "1 - Encode" << endl;
        cout << "2 - Decode" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter choice: ";
        cin >> op;

        if(op == '1')
        {
            Encode();
            continue;
        }
        else if(op == '2')
        {
            Decode();
            continue;
        }
        else if(op == '3') break;
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}