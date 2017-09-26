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

void PartMult(int k);
void Write(int k);
int Max(int k);

int main()
{
    is >> n;
    PartMult(1);
    os << nrsol << " solutii !!";
    is.close();
    os.close();
}

void PartMult(int k)
{
    if ( k > n )
    {
        Write(k - 1);
        return;
    }

    for (int i = 1; i <= Max(k - 1) + 1; ++i)
    {
        x[k] = i;
        PartMult(k + 1);
    }
}

int Max(int k)
{
    int maxim = 0;
    for (int i = 1; i <= k; ++i)
        maxim = max(maxim, x[i]);
    return maxim;
}

void Write(int k)
{
    nrsol++;
    int nr_subm = Max(k);
    for (int s = 1; s <= nr_subm; ++s)
    {
        os << "{ ";
        for (int i = 1; i <= k; ++i)
            if ( x[i] == s)
                os << i << " ";
        os << "} ";
    }
    os << '\n';
}




