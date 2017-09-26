#include <iostream>
#include <string>
using namespace std;

int main()
{
    string v = "aeoiu";
    string s = "aseara";
    if(v.find(s[1]) == string::npos)
        cout << s[1];
    return 0;
}
