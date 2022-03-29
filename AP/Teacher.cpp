#include "system.hpp"

bool Teacher::SignUp()
{
    string name, id;
    string email, passw;

    cin.ignore();

    cout << " ---- DADOS DO PROFESSOR ---- " << endl;
    cout << "Nome: ";
    getline(cin, name);

    cout << "ID: ";
    getline(cin, id);

    cout << "E-mail: ";
    getline(cin, email);

    cout << "Senha: ";
    getline(cin, passw);

    Teacher tc(id, passw);
    SaveTeacher(tc);

    return true;
}

bool Teacher::LogIn()
{
    std::ifstream filereader("profs.txt");

    if(!filereader.is_open()) return false;

    std::vector< string > ListInfo;

    string line;
    while(getline(filereader, line))
    {
        ListInfo.push_back(line);
    }

    string id;
    string pssw;

    cout << "ID: ";
    cin >> id;

    cout << "Senha: ";
    cin>> pssw;

    Teacher tc;

    for(size_t i=0; i < ListInfo.size(); i++)
    {
        if((ListInfo.at(i) == id))
        {
            if((ListInfo.at(i+1) == pssw))
            {
                MenuTeacher();
            }
            else
            {
                cout << "Erro. Tente novamente." << endl;
                return false;
            }
        }
    }

    filereader.close();
    return true;
}

bool MenuTeacher()
{
    Teacher tc;
    char op;

    while(true)
    {
        cout << "---------- ESCOLHA UMA ACAO ----------" << endl;
        cout << " 1 - ADICIONAR NOTA " << endl;
        cout << " 2 - REMOVER NOTA " << endl;
        cout << " 3 - SAIR " << endl;
        cout << " OP: ";
        cin >> op;

        if(op == '1')
        {
            tc.AddGrade();
            continue;
        }
        else if(op == '2')
        {
            tc.RemoveGrade();
            continue;
        }
        else if(op == '3') break;
        else
        {
            cout << "Codigo Invalido." << endl;
            continue;
        }
    }

    return true;
}

bool Teacher::AddGrade()
{
    std::vector< string > mat;
    string aux;
    std::ofstream filewriter("grades.txt", std::ios::app);

    if(!filewriter.is_open()) return false;

    char cont;
    float n1, n2;

    std::vector< std::pair<float, float> > MedList;

    do {
        cout << "Matricula do aluno: ";
        cin >> aux;
        mat.push_back(aux);

        cout << "Digite as notas: ";
        cin >> n1 >> n2;

        MedList.push_back(std::make_pair(n1, n2));

        cout << "Continuar? (y/n): ";
        cin >> cont;
    }
    while(cont == 'y');

    std::vector< float > med;

    for(size_t i=0; i<MedList.size(); i++)
    {
        float a = MedList.at(i).first;
        float b = MedList.at(i).second;
        med.push_back((a+b) / 2);
    }

    for(size_t i=0; i<med.size(); i++)
    {
        filewriter << mat.at(i) << endl;
        filewriter << med.at(i) << endl;
    }

    filewriter.close();
    return true;
}

bool Teacher::RemoveGrade()
{
    std::ifstream filereader("grades.txt");

    if(!filereader.is_open()) return false;

    std::vector< string > StdInfo;

    string line;
    while(getline(filereader, line))
    {
        StdInfo.push_back(line);
    }

    char op;

    cout << "Remover por:\n 1 - Matricula \n 2 - Posicao" << endl;
    cin >> op;

    if(op == '1')
    {
        string mat;
        cout << "Matricula: ";
        cin >> mat;

        for(size_t i=0; i<StdInfo.size(); i++)
        {
            if(mat == StdInfo.at(i))
            {
                StdInfo.erase(StdInfo.begin()+i);
                StdInfo.erase(StdInfo.begin()+i);
            }
        }

        for(size_t i=0; i<StdInfo.size(); i++)
        {
            cout << StdInfo.at(i) << endl;
        }
    }
    if(op == '2')
    {
        size_t pos;

        for(size_t i=0; i<StdInfo.size(); i++)
        {
            if(i % 2 == 0)
                cout << i << ": " << StdInfo.at(i) << endl;
            else
                cout << StdInfo.at(i) << endl;
        }

        cout << "Escolha: ";
        cin >> pos;

        StdInfo.erase(StdInfo.begin()+pos);
        StdInfo.erase(StdInfo.begin()+pos);

        for(size_t i=0; i<StdInfo.size(); i++)
        {
            cout << StdInfo.at(i) << endl;
        }
    }

    filereader.close();
    return true;
}

bool SaveTeacher(Teacher tc)
{
    std::ofstream filewriter("profs.txt", std::ios::app);

    if(!filewriter.is_open()) return false;

    filewriter << tc.GetId() << endl;
    filewriter << tc.GetPassw() << endl;

    filewriter.close();
    return true;
}