#include "coder.hpp"

bool Encode()
{
    string filename;

    cout << "Enter your file name to encode: ";
    cin >> filename;

    char ch;
    stringstream sst;

    ifstream filereader(filename);

    if(!filereader.is_open()) return false;

    while(filereader.get(ch))
    {
        sst << ch;
    }

    vector< pair< unsigned char, size_t > > table;

    string text = sst.str();
    for(size_t i = 0; i < text.size(); i++)
    {
        char charct = text.at(i);
        pair< unsigned char, size_t > p(charct, charct);
        table.push_back(p);
    }

    // y = x + 20 para % 2 == 0 (divis�vel por 2 e n�o por 5)
    // y = x + 30 para % 5 == 0 (divis�vel por 5 e n�o por 2)
    // y = x + 10 para 2 e 5 (divis�vel por 2 e 5)
    // y = x - 10 para os que n�o s�o divis�veis por nenhum dos dois

    for(size_t i = 0; i < table.size(); i++)
    {
        if(table.at(i).second % 2 == 0 && table.at(i).second % 5 != 0)
        {
            table.at(i).second += 20;
        }
        else if(table.at(i).second % 5 == 0 && table.at(i).second % 2 != 0)
        {
            table.at(i).second += 30;
        }
        else if(table.at(i).second % 2 == 0 && table.at(i).second % 5 == 0)
        {
            table.at(i).second += 10;
        }
        else
        {
            table.at(i).second -= 10;
        }
    }

    cout << "\n\n";

    for(int i = table.size() -1 ; i >= 0 ; i--)
    {
        cout << (char)table.at(i).second;
    }

    cout << "\n\n";

    SaveDecod("encode.txt", table);
    filereader.close();
    return true;
}

bool Decode()
{
    string filename;

    cout << "Enter your file name to decode: ";
    cin >> filename;

    char ch;
    stringstream sst;

    ifstream filereader(filename);

    if(!filereader.is_open()) return false;

    while(filereader.get(ch))
    {
        sst << ch;
    }

    vector< pair< unsigned char, size_t > > table;

    string text = sst.str();
    for(size_t i = 0; i < text.size(); i++)
    {
        char charct = text.at(i);
        pair< unsigned char, size_t > p(charct, charct);
        table.push_back(p);
    }

    // y = x - 20 para % 2 == 0 (divis�vel por 2 e não por 5)
    // y = x - 30 para % 5 == 0 (divis�vel por 5 e não por 2)
    // y = x - 10 para 2 e 5 (divis�vel por 2 e 5)
    // y = x + 10 para os que n�o s�o divis�veis por nenhum dos dois

    for(size_t i = 0; i < table.size(); i++)
    {
        if(table.at(i).second % 2 == 0 && table.at(i).second % 5 != 0)
        {
            table.at(i).second -= 20;
        }
        else if(table.at(i).second % 5 == 0 && table.at(i).second % 2 != 0)
        {
            table.at(i).second -= 30;
        }
        else if(table.at(i).second % 2 == 0 && table.at(i).second % 5 == 0)
        {
            table.at(i).second -= 10;
        }
        else
        {
            table.at(i).second += 10;
        }
    }

    cout << "\n\n";

    for(int i = table.size() -1 ; i >= 0 ; i--)
    {
        cout << (char)table.at(i).second;
    }

    cout << "\n\n";

    SaveDecod("decode.txt", table); 
    return true;
}

bool SaveDecod(string filename, vector< pair <unsigned char, size_t > > &table)
{
    ofstream filewriter(filename);
    if(!filewriter.is_open()) return false;

    for(int i = table.size() -1 ; i >= 0 ; i--)
    {
        filewriter << (char)table.at(i).second;
    }

    filewriter.close();
    return true;
}