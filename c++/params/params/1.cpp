#include <fstream>
using namespace std;

ifstream is("sir.in");
ofstream os("sir.out");

int a[100], n; // var globale

void Read();
void Write();
void Sort();

int main()
{
    Read();
    Write();
    Sort();
    Write();
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n;
    for (int i = 0; i < n; ++i )
        is >> a[i];
}

void Write()
{
    for ( int i = 0; i < n; ++i )
        os << a[i] << ' ';
    os << '\n';
}

void Sort()
{
    bool sortat;
    do
    {
        sortat = true;
        for ( int i = 0; i < n - 1; ++i )
            if ( a[i] > a[i + 1])
            {
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                sortat = false;
            }
    } while ( !sortat );
}
