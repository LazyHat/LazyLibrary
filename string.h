// LIBRARY FOR CPP PROJECTS
#include <iostream>
#include <fstream>
#include <windows.h>

class String
{
private:
    char *s;

public:
    String();
    String(const char *str);
    String(const String &obj);
    String(String &&obj);
    ~String();
    int Size();
    void Print();
    void PrintL();
    friend std::ostream &operator<<(std::ostream &out, const String &obj);
    friend std::istream &operator>>(std::istream &in, String &obj);
    friend String ToString(const int &num);
    String &operator=(const String &&obj);
    String operator+(const String &obj);
    String operator+(const char *str);
    String operator+(const int &num);
    String &operator+=(const String &obj);
    char &operator[](const int &index);
    bool operator==(const String &obj);
};
