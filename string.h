// LIBRARY FOR CPP PROJECTS
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

class string
{
private:
    char *s;
    int size;

public:
    string();
    string(const char *str);
    ~string();
    int Size();
    friend std::ostream &operator<<(std::ostream &out, string &str);
};
