// LIBRARY FOR CPP PROJECTS
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

class String
{
private:
    char *s;

public:
    String();
    String(const char *str);
    ~String();
    int Size();
    void Print();
    void PrintL();
    friend std::ostream &operator<<(std::ostream &out, String &str);
    String &operator=(const String &str);
};
