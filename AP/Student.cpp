#include "system.hpp"

bool Student::SignUp ()
{
    string name, mat;
    string email, passw;

    cin.ignore();

    cout << " ---- DADOS DO ESTUDANTE ---- " << endl;
    cout << "Nome: ";
    getline(cin, name);

    cout << "Matricula: ";
    getline(cin, mat);

    cout << "E-mail: ";
    getline(cin, email);

    cout << "Senha: ";
    getline(cin, passw);

    Student st(mat, passw);
    SaveStudent(st);
    return true;
}

bool SaveStudent(Student st)
{
    std::ofstream filewriter("alunos.txt", std::ios::app);

    if(!filewriter.is_open()) return false;

    filewriter << st.GetMat() << endl;
    filewriter << st.GetPassw() << endl;

    filewriter.close();

    return true;
}

bool Student::LogIn()
{
    std::ifstream filereader("alunos.txt");

    if(!filereader.is_open()) return false;

    std::vector< string > ListInfo;

    string line;
    while(getline(filereader, line))
    {
        ListInfo.push_back(line);
    }

    string mat;
    string pssw;

    cout << "Matricula: ";
    cin >> mat;

    cout << "Senha: ";
    cin>> pssw;

    Student st;

    for(size_t i=0; i < ListInfo.size(); i++)
    {
        if((ListInfo.at(i) == mat))
        {
            if((ListInfo.at(i+1) == pssw))
            {
                st.CheckGrade(mat);
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

bool Student::CheckGrade(string mat)
{
    std::ifstream filereader("grades.txt");

    if(!filereader.is_open()) return false;

    std::vector< string > StdInfo;

    string line;
    while(getline(filereader, line))
    {
        StdInfo.push_back(line);
    }

    for(size_t i=0; i<StdInfo.size(); i++)
    {
        if(mat == StdInfo.at(i))
        {
            cout << " MEDIA -- " << StdInfo.at(i) << endl;
            cout << StdInfo.at(i+1) << endl;
        }
    }

    filereader.close();
    return true;
}
