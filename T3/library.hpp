#ifndef LIBRARY_HPP
#define LIBRARY_HPP 

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <locale.h>
#include <time.h> 

using std::string;
using std::cout;
using std::cin;
using std::getline;

class User {
protected:
    string Name;
    string Addr;
    string Email;

public:
    User() : Name(""), Addr(""), Email("") {};
    User(string name, string addr, string email) : Name(name), Addr(addr), Email(email) {};
    ~User() {};

    // Getters and Setters
    void setName(string name) {Name = name; };
    string getName() { return Name; };

    void setAddr(string addr) {Addr = addr; };
    string getAddr() { return Addr; };

    void setEmail(string email) { Email = email; };
    string getEmail() { return Email; };
};

class EmUser : public User {
private:
    int NumMat;
    string Curso;

public:
    EmUser() : NumMat(0), Curso("") {};
    EmUser(User* u, int mat, string curso) : User("", "", ""), NumMat(mat), Curso(curso) {};
    ~EmUser() {};

    int getMat() { return NumMat; };
    void setMat(int mat) { NumMat = mat; };

    string getCurso() { return Curso; };
    void setCurso(string curso) { Curso = curso; };
};

class DoaUser : public User {
private:
    string CPF;
    string Phone;
    
public:
    DoaUser() : CPF(0), Phone("") {};
    DoaUser(User* u, string cpf, string phone) : User("", "", ""), CPF(cpf), Phone(phone) {};
    ~DoaUser() {};

    string getCPF() { return CPF; };
    void setCPF(string cpf) { CPF = cpf; };

    string getPhone() { return Phone; };
    void setPhone(string phone) { Phone = phone; };
};

class Book {
private:
    string Title;
    string Author;
    size_t Year;

public:
    Book() : Title(""), Author(""), Year(0) {};
    Book(string ttl, string auth, size_t year) : Title(ttl), Author(auth), Year(year) {};
    ~Book() {};

    // Getters and Setters
    void setTitle(string ttl) { Title = ttl; };
    string getTitle() { return Title; };

    void setAuthor(string auth) { Author = auth; };
    string getAuthor() { return Author; };

    void setYear(size_t year) { Year = year; };
    size_t getYear() { return Year; };
};

class Ficha {
private:
    User* m_user;
    Book* m_book;

public:
    bool NewFicha1(User* u);
    bool NewFicha2(User* u);

    Ficha() : m_user(NULL), m_book(NULL) {};
    Ficha(User* user, Book* book) : m_user(user), m_book(book) {};
    ~Ficha() { delete m_user; delete m_book; };

    string getName() { return m_user->getName(); };
    string getAddr() { return m_user->getAddr(); };
    string getEmail() { return m_user->getEmail(); };

    string getTitle() { return m_book->getTitle(); };
    string getAuthor() { return m_book->getAuthor(); };
    size_t getYear() { return m_book->getYear(); };
};

bool SaveEmp(string filename, Ficha* ficha, EmUser* emu); 
bool SaveDoa(string filename, Ficha* ficha, DoaUser* duser); 
int CheckMat(int mat);
bool Devolucao();
bool Inicio();

#endif