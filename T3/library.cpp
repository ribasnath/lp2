#include "library.hpp"

bool Inicio()
{
    setlocale(LC_ALL, "Portuguese");

    string name, addr, email;
    int op;
    Ficha f1;

    cout << "    Bem-vindo(a) à biblioteca!" << std::endl;
    cout << "  ------------------------------------" << std::endl;
    cout << "    Opções de acesso: " << std::endl;
    cout << "    1. Empréstimo\n" << "    2. Doação\n" << "    3. Devolução\n" << "    4. Sair" << std::endl;
    cout << "  ------------------------------------" << std::endl;
    cout << "\n >> Informe a ação escolhida: ";
    cin >> op;
    
    if(op == 1)
    {
        cout << "    Informações sobre o usuário: " << std::endl;
        cin.ignore();
        cout << "    Nome: ";
        getline(cin, name);
        cout << "    Endereço: ";
        getline(cin, addr);
        cout << "    Email: ";
        getline(cin, email);
        User* u = new User(name, addr, email);
        f1.NewFicha1(u);
    }
    else if(op == 2)
    {
        cout << "    Informações sobre o usuário: " << std::endl;
        cin.ignore();
        cout << "    Nome: ";
        getline(cin, name);
        cout << "    Endereço: ";
        getline(cin, addr);
        cout << "    Email: ";
        getline(cin, email);
        User* u = new User(name, addr, email);
        f1.NewFicha2(u);
    }
    else if(op == 3)
        Devolucao();
    else if(op == 4)
        return false;
    else
        cout << " >> Escolha inválida." << std::endl;

    return true;
}

bool Ficha::NewFicha1(User* u)
{
    setlocale(LC_ALL, "Portuguese");

    string curso;
    string fname;
    int mat;

    cout << "    Curso: ";
    getline(cin, curso);

    cout << "    Número da Matrícula: ";
    cin >> mat;
    
    EmUser* emu = new EmUser(u, mat, curso);

    if(CheckMat(mat) == 0) {
        cout << " >> Não é permitido registrar mais de dois empréstimos por vez." << std::endl;
        return false;
    }
    else if(CheckMat(mat) == 1)
        fname = "e"+std::to_string(mat)+"_2.txt";
    else
        fname = "e"+std::to_string(mat)+".txt";

//////////////////////////////////////////////////////////////////

    cin.ignore();
    cout << "\n    Informações sobre o livro: " << std::endl;

    string ttl, auth;
    size_t y;

    cout << "    Título: ";
    getline(cin, ttl);

    cout << "    Autor: ";
    getline(cin, auth);

    cout << "    Ano: ";
    cin >> y;

    Book* book = new Book(ttl, auth, y);
    Ficha* f = new Ficha(u, book);

    SaveEmp(fname, f, emu);
    delete u;
    return true;
}

bool SaveEmp(string filename, Ficha* ficha, EmUser* emu)
{
    setlocale(LC_ALL, "Portuguese");

    std::ofstream filewriter(filename);

    if(!filewriter.is_open()) return false;

    filewriter << "------------------------------------" << std::endl;
    filewriter << "Ficha - Empréstimo" << std::endl;
    filewriter << "------------------------------------" << std::endl;

    filewriter << "Informações do Aluno:" << std::endl;
    filewriter << "Nome: " << ficha->getName() << std::endl;
    filewriter << "Número de Matrícula: " << emu->getMat() << std::endl;
    filewriter << "Curso: " << emu->getCurso() << std::endl;
    filewriter << "Endereço: " << ficha->getAddr() << std::endl;
    filewriter << "E-mail: " << ficha->getEmail() << std::endl;

    filewriter << "\n\nInformações do Livro:" << std::endl;
    filewriter << "Título: " << ficha->getTitle() << std::endl;
    filewriter << "Autor: " << ficha->getAuthor() << std::endl;
    filewriter << "Ano: " << ficha->getYear() << std::endl;

    filewriter.close();
    delete emu;
    delete ficha;
    return true;
}

bool Ficha::NewFicha2(User* u)
{
    setlocale(LC_ALL, "Portuguese");

    string phone, cpf;

    cout << "    CPF: ";
    getline(cin, cpf);

    cout << "    Telefone: ";
    getline(cin, phone);

    DoaUser* duser = new DoaUser(u, cpf, phone);

//////////////////////////////////////////////////////////////////

    cout << "\n    Informações sobre o livro:" << std::endl;

    string ttl, auth;
    size_t y;

    cout << "    Título: ";
    getline(cin, ttl);

    cout << "    Autor: ";
    getline(cin, auth);

    cout << "    Ano: ";
    cin >> y;

    Book* book = new Book(ttl, auth, y);

    srand(time(0));
    int i = rand();
    string fname = "d"+std::to_string(i)+".txt";

    Ficha* f = new Ficha(u, book);
    SaveDoa(fname, f, duser);
    delete u;
    return true;
}

bool SaveDoa(string filename, Ficha* ficha, DoaUser* duser)
{
    setlocale(LC_ALL, "Portuguese");

    std::ofstream filewriter(filename);
    if(!filewriter.is_open()) return false;

    filewriter << "------------------------------------" << std::endl;
    filewriter << "Ficha - Doação" << std::endl;
    filewriter << "------------------------------------" << std::endl;

    filewriter << "Informações do Doador:" << std::endl;
    filewriter << "Nome: " << ficha->getName() << std::endl;
    filewriter << "CPF: " << duser->getCPF() << std::endl;
    filewriter << "Endereço: " << ficha->getAddr() << std::endl;
    filewriter << "E-mail: " << ficha->getEmail() << std::endl;
    filewriter << "Telefone: " << duser->getPhone() << std::endl;

    filewriter << "\n\nInformações do Livro:" << std::endl;
    filewriter << "Título: " << ficha->getTitle() << std::endl;
    filewriter << "Autor: " << ficha->getAuthor() << std::endl;
    filewriter << "Ano: " << ficha->getYear() << std::endl;

    filewriter.close();
    delete duser;
    delete ficha;
    return true;
}

bool Devolucao()
{
    setlocale(LC_ALL, "Portuguese");

    char fname[15];
    int res;

    cout << "    Selecione sua ficha: ";
    cin >> fname;

    std::ifstream fw(fname);

    if(!fw) {
        cout << " >> Erro. Tente novamente." << std::endl;
        return false;
    }
    fw.close();

    res = remove(fname);
    
    if(res == 0)
        cout << " >> Devolvido com sucesso!" << std::endl;

    return true;
}

//! Uma pessoa não pode pegar mais de 2 livros de cada vez
int CheckMat(int mat)
{
    string fname = "e"+std::to_string(mat)+".txt";
    std::ifstream fmat(fname);

    if(fmat)
    {
        string ad = "e"+std::to_string(mat)+"_2.txt";
        std::ifstream fad(ad);
        if(fad)
            return 0;
        else return 1;
    }
    else return 2;
}