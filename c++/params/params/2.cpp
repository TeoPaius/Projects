#include <fstream>
using namespace std;

ifstream is("sir.in");
ofstream os("sir.out");

void Read(int a[100], int& n);
void Write(int* a, int n);
void Sort(int a[], int n);

int main()
{
    int a[100], n; // var var locale
 //   os << a << '\n';;
    Read(a, n);
    Write(a, n);
    Sort(a, n);
    Write(a, n);

    is.close();
    os.close();
    return 0;
}

void Read(int b[100], int& n)
{
    is >> n;
    for (int i = 0; i < n; ++i )
        is >> b[i];
}

void Write(int* a, int n)
{
    for ( int i = 0; i < n; ++i )
        os << a[i] << ' ';
    os << '\n';
}

void Sort(int a[], int n)
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
