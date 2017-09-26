#include <fstream>
using namespace std;

ifstream is("part_nr.in");
ofstream os("part_nr.out");

int x[50], n;
int sp[50]; // sp[k] = x[1] + x[2] + .. + x[k]
int nrsol;

void PartNr(int k);
void Write(int k);

int main()
{
    is >> n;
    x[0] = 1;
    PartNr(1);

    is.close();
    os.close();
}

void PartNr(int k)
{
    if ( sp[k - 1] == n )
    {
        Write(k - 1);
        return;
    }
    if ( k > n )
        return;

    for (int i = x[k - 1]; i <= n; ++i)
    {
        x[k] = i;
        if ( sp[k - 1] + i <= n )
        {
            sp[k] = sp[k - 1] + i;
            PartNr(k + 1);
        }

    }
}

void Write(int k)
{
    nrsol++;
    os << n << " = ";
    for (int i = 1; i < k; ++i)
        os << x[i] << " + ";
    os << x[k] << '\n';
}




