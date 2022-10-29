#include <Windows.h>
#include "LazyLib.cpp"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    String k = "stfgsdfsd";
    String z = "sedgsd";
    k = z;
    k.PrintL();
    std::cout << k.Size();
    return 0;
}