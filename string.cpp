#pragma once
#include "String.h"

#pragma region PROTOTYPES
int StrSize(const char *str);
#pragma endregion
#pragma region CONSTRUCTORS AND DESTRUCTORS
String::String()
{
    s = new char[1];
    s[0] = '\0';
}
String::String(const char *str)
{
    if (str == nullptr)
        throw StringExeption("Exep: String(const char *str): str is nullptr");
    int length = StrSize(str);
    s = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        s[i] = str[i];
    }
    s[length] = '\0';
}
String::String(const String &obj)
{
    int length = StrSize(obj.s);
    s = new char[length];
    for (int i = 0; i < length; i++)
    {
        s[i] = obj.s[i];
    }
    s[length] = '\0';
}
String::String(String &&obj)
{
    this->s = obj.s;
    obj.s = nullptr;
}
String::~String()
{
    delete[] s;
}
#pragma endregion
#pragma region FUNCTIONS
#pragma region OPERATORS
std::ostream &operator<<(std::ostream &out, const String &obj)
{
    out << obj.s;
    return out;
}
std::istream &operator>>(std::istream &in, String &obj)
{
    in >> obj.s;
    return in;
}
String &String::operator=(String &&obj)
{
    this->s = obj.s;
    obj.s = nullptr;
    return *this;
}
String &String::operator=(const String &obj)
{
    delete[] this->s;
    String newobj;
    int length = StrSize(obj.s);
    this->s = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        this->s[i] = obj.s[i];
    }
    this->s[length] = '\0';
    return *this;
}
String String::operator+(const String &obj)
{
    String sumobj;
    int length1 = this->Size();
    int length2 = StrSize(obj.s);
    sumobj.s = new char[length1 + length2 + 1]; // Plus '\0'
    for (int i = 0; i < length1; i++)
    {
        sumobj.s[i] = s[i];
    }
    for (int i = 0; i < length2; i++)
    {
        sumobj.s[i + length1] = obj.s[i];
    }
    sumobj.s[length1 + length2] = '\0';
    return sumobj;
}
String String::operator+(const char *str)
{
    String sumobj;
    int length1 = this->Size();
    int length2 = StrSize(str);
    sumobj.s = new char[length1 + length2 + 1]; // Plus '\0'
    for (int i = 0; i < length1; i++)
    {
        sumobj.s[i] = s[i];
    }
    for (int i = 0; i < length2; i++)
    {
        sumobj.s[i + length1] = str[i];
    }
    sumobj.s[length1 + length2] = '\0';
    return sumobj;
}
String String::operator+(const int &num)
{
    return *this + ToString(num);
}
String &String::operator+=(const String &obj)
{
    *this = *this + obj;
    return *this;
}
char &String::operator[](const int &index)
{
    if (abs(index) > this->Size())
        throw StringExeption("Exep: operator[const int &index]: index out of range.");
    if (index >= 0)
        return this->s[index];
    else
    {
        return this->s[this->Size() + index];
    }
}
int String::operator[](const char &index)
{
    for (int i = 0; i < this->Size(); i++)
        if (this->s[i] == index)
            return i;
    throw StringExeption("Exep: operator[const char &index]: index out of line.");
}
bool String::operator==(const String &obj)
{
    int thislength = this->Size();
    if (thislength != StrSize(obj.s))
        return 0;
    else
    {
        for (int i = 0; i < thislength; i++)
        {
            if (this->s[i] != obj.s[i])
                return 0;
        }
        return 1;
    }
}
#pragma endregion
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
String ToString(const int &num)
{
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char symbols[] = {'-'};
    String strnum;
    int length = 0;
    for (int i = num; i != 0; i /= 10)
        length++;
    int bnum = num;
    if (num < 0)
    {
        length++;
        strnum.s = new char[length + 1];
        strnum.s[length] = '\0';
        strnum.s[0] = symbols[0];
        bnum = abs(bnum);
        for (int i = length - 1; i >= 1; i--)
        {
            strnum.s[i] = numbers[bnum % 10];
            bnum /= 10;
        }
    }
    else
    {
        strnum.s = new char[length + 1];
        strnum.s[length] = '\0';
        for (int i = length - 1; i >= 0; i--)
        {
            strnum.s[i] = numbers[bnum % 10];
            bnum /= 10;
        }
    }
    return strnum;
}
char *String::ToArray() const
{
    return this->s;
}
int StrSize(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}
void SetCPConsole(int cp)
{
    SetConsoleCP(cp);
    SetConsoleOutputCP(cp);
}
#pragma region FILE_FSTREAM
String GetStrLine(std::ifstream &file)
{
    return String("GetStrLine()");
}
#pragma endregion
#pragma endregion