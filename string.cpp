#include "string.h"

string::string()
{
    s = nullptr;
    size = 0;
}
string::string(const char *str)
{
    int sizestr = 0;
    while (str[sizestr] != '\0')
        sizestr++;
    s = (char *)malloc(sizestr);
    for (int i = 0; i < sizestr; i++)
    {
        *(s + i) = *(str + i);
    }
}
int string::Size()
{
    return size;
}
string::~string()
{
    delete[] s;
}
std::ostream &operator<<(std::ostream &out, string &str)
{
    out << str.s;
    return out;
}