#include <Windows.h>
#include "string.cpp"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string k = string("sdggds");
    std::cout << k << std::endl;
    std::cout << k.Size();
    return 0;
}