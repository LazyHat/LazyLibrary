#include <Windows.h>
#include "LazyLib.cpp"
using namespace std;
int main()
{
    SetCPConsole(1251);
    String k("Hello");
    String s("World!");
    String z(k + " " + s);
    String j;
    j = k;
    z.PrintL();
    if (z.Contains("Hellow"))
    {
        cout << "str contains in a z";
    }
    else
    {
        cout << "str not contains in a z";
    }
    cout << endl;
    return 0;
}