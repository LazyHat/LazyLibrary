#include <Windows.h>
#include "LazyLib.cpp"
using namespace std;
int main()
{
    SetCPConsole(1251);
    String k("Hello");
    String s("He3lo");
    String p("nullptr");
    k = s;
    k = "sdfgsdg";
    k = p;
    return 0;
}