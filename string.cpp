#include "String.h"

#pragma region PROTOTYPES
int StrSize(char *str);
int StrSize(const char *str);
#pragma endregion
#pragma region CONSTRUCTORS AND DESTRUCTORS
String::String()
{
    this->s = nullptr;
}
String::String(const char *str)
{
    int length = StrSize(str);
    s = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        s[i] = str[i];
    }
    s[length] = '\0';
}
String::~String()
{
    delete[] s;
}
#pragma endregion
#pragma region FUNCTIONS
int String::Size()
{
    return StrSize(s);
}
void String::Print()
{
    std::cout << *this;
}
void String::PrintL()
{
    std::cout << *this << "\n";
}
#pragma region OPERATORS
std::ostream &operator<<(std::ostream &out, String &str)
{
    out << str.s;
    return out;
}
String &String::operator=(const String &str)
{
    if (this->s != nullptr)
    {
        delete[] this->s;
    }
    int length = StrSize(str.s);
    this->s = new char[length];
    for (int i = 0; i < length; i++)
        this->s[i] = str.s[i];
    this->s[length] = '\0';
    return *this;
}
#pragma endregion
#pragma region STRSIZE
int StrSize(char *str)
{
    if (str == nullptr)
    {
        return 0;
    }
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}
int StrSize(const char *str)
{
    if (str == nullptr)
    {
        return 0;
    }
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}
#pragma endregion
#pragma endregion