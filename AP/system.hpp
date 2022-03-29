#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class User {
protected:
    string m_name;
    string m_email;
    string m_passw;

public:
    User() : m_name(""), m_email(""), m_passw("") {};
    User(string name, string email, string passw) : m_name(name), m_email(email), m_passw(passw) {};
    User(string email, string passw) : m_email(email), m_passw(passw) {};
    User(string passw) : m_passw(passw) {};

    // Getters and Setters
    string GetName() { return m_name; };
    string GetEmail() { return m_email; };
    string GetPassw() { return m_passw; };

    void SetName(string name) { m_name = name; };
    void SetEmail(string email) { m_email = email; };
    void SetPassw(string passw) { m_passw = passw; };
};

class Student : public User {
private:
    string m_mat;
    //float med;

public:
    bool SignUp();
    bool LogIn();
    bool CheckGrade(string mat);

    Student() : m_mat("") {};
    Student(string name, string email, string passw, string mat) : User(name, email, passw), m_mat(mat) {};
    Student(string mat, string passw) : m_mat(mat), User(passw) {};

    // Getters and Setters
    string GetMat() { return m_mat; };
    void SetMat(string mat) { m_mat = mat; };
};

class Teacher : public User {
private:
    string m_id;

public:
    bool SignUp();
    bool LogIn();

    bool AddGrade();
    bool RemoveGrade();

    Teacher() : m_id("") {};
    Teacher(string name, string email, string passw, string id) : User(name, email, passw), m_id(id) {};
    Teacher(string id, string passw) : m_id(id), User(passw) {};

    // Getters and Setters
    string GetId() { return m_id; };
    void SetId(string id) { m_id = id; };
};

bool Menu();
bool SaveStudent(Student st);
bool SaveTeacher(Teacher tc);
bool MenuTeacher();