/* Sa se genereze toate partiile unei multimi
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("part_mult.in");
ofstream os("part_mult.out");

int x[50], n; // x[k] = i elem k se plaseaza in
              // submultimea i a partitiei curente
int nrsol;

void PartMult(int k, int Max);
void Write(int k, int Max);
int Max(int k);

int main()
{
    is >> n;
    PartMult(1, 0);
    os << nrsol << " solutii !!";
    is.close();
    os.close();
}

void PartMult(int k, int Max)
{
    if ( k > n )
    {
        Write(k - 1, Max);
        return;
    }

    for (int i = 1; i <= Max + 1; ++i)
    {
        x[k] = i;
        PartMult(k + 1, max(Max, i));
    }
}

int Max(int k)
{
    int maxim = 0;
    for (int i = 1; i <= k; ++i)
        maxim = max(maxim, x[i]);
    return maxim;
}

void Write(int k, int Max)
{
    nrsol++;

    for (int s = 1; s <= Max; ++s)
    {
        os << "{ ";
        for (int i = 1; i <= k; ++i)
            if ( x[i] == s)
                os << i << " ";
        os << "} ";
    }
    os << '\n';
}




