// MECANISMUL de Transfer "Prin REFERINTA"
#include <iostream>
using namespace std;

void Read(int& a);
void Write(int a);

int main()
{
    int x;    // x = 10

    Read(x);  // Apel prin REFERINTA
    Write(x); // Apel prin VALOARE
    return 0;
}

// a = referinta la argumentul x
// de fapt, a este un ALIAS (alt nume) pentru x
void Read(int& a)
{
    cin >> a;
}

void Write(int a)
{
    cout << a;

}
