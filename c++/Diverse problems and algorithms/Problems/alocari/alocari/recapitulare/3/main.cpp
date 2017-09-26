/*a)Scrieti o functie recursiva cifra cu parametrii n nr natural si c cifra care
returneaza de cate ori apare cifra c in numarul n
b)Scrieti o functie recursiva cifre cu 3 parametrii a un vector cu cel mult 100 nr nat
n nr efectiv de element din a, c cifra si returneaza de cate ori apare in total cifra c in a
c)Se citeste un nr n si un vector a cu n element, afisati cifrele care apar de cele mai multe ori
in elementele vectorului
*/
#include <fstream>
using namespace std;

ifstream is("1.in");
ofstream os("1.out");

int Cifra(int c, int n);
void Cifre(int a[], int n, int c, int i, int& cnt);

int main()
{
    int a[100];
    int x;
    int cnt1[10];
    is >> x;
    for ( int i = 0; i < x; ++i )
        is >> a[i];
    int max1 = -1;
    int cnt = 0;
    Cifre(a, x, 2, 0, cnt);
    os << cnt;
    for ( int i = 0; i < 10; ++i )
    {
        cnt = 0;
        Cifre(a, x, i, 0, cnt);
        cnt1[i] = cnt;
        max1 = max(cnt, max1);
    }
    os << '\n'; b
    for ( int i = 0; i < 10; ++i )
        if ( cnt1[i] == max1 )
            os << i << ' ';
    is.close();
    os.close();
    return 0;
}

int Cifra(int c, int n)
{
    if ( n == 0 )
        return 0;
    return n % 10 == c ? Cifra(c, n / 10) + 1 : Cifra(c, n / 10);
}

void Cifre(int a[], int n, int c, int i, int& cnt)
{
    if ( i == n + 1 )
        return;
    cnt += Cifra(c, a[i]);
    Cifre(a, n, c, i + 1, cnt);
}

