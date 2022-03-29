/*
####################################
# DEC7532-02655                    #
# Aluna: Nath�lia Geraldino Ribas  #
# Matr�cula: 20250334              #
# Sistema para biblioteca          #
#################################### 
*/

#include "library.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Ficha f1;
    int op;

    cout << "    Bem-vindo(a) � biblioteca!" << std::endl;
    cout << "  ------------------------------------" << std::endl;
    cout << "    1. Empr�stimo\n" << "    2. Doa��o\n" << "    3. Devolu��o\n" << "    4. Sair" << std::endl;
    cout << "  ------------------------------------" << std::endl;
    cout << "\n >> Informe a a��o escolhida: ";
    cin >> op;
    
    if(op == 1)
        f1.NewFicha1();
    else if(op == 2)
        f1.NewFicha2();
    else if(op == 3)
        Devolucao();
    else if(op == 4)
        return 0;
    else
        cout << " >> Escolha inv�lida." << std::endl;

    system("PAUSE");
    return 0;
}
