#include <fstream>
using namespace std;

ifstream is("part_nr.in");
ofstream os("part_nr.out");

int x[50], n;
int nrsol;

void PartNr(int k, int sp); // sp - suma partiala pana la poz k - 1
void Write(int k);

int main()
{
    is >> n;
    x[0] = 1;
    PartNr(1, 0);
    os << nrsol << " solutii !!";
    is.close();
    os.close();
}

void PartNr(int k, int sp)
{
    if ( sp == n )
    {
        Write(k - 1);
        return;
    }
    if ( k > n )
        return;

    for (int i = x[k - 1]; sp + i <= n; ++i)
    {
        x[k] = i;
        PartNr(k + 1, sp + i);
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




