#include <fstream>
using namespace std;

ifstream fin("fotbal.in");
ofstream fout("fotbal.out");

void Back(int k);
void Write(int k);
bool Ok(int k);

int x[101], a, b, nrsol;
int s1[101], s2[101];

int main()
{
    fin >> a >> b;
    fin.close();

    Back(1);
    fout << nrsol;

    fout.close();
    return 0;
}

void Back(int k) // k = golul curent
{
    if (s1[k - 1] == a && b == s2[k - 1])
    {
        Write(k - 1);
        return;
    }
    if (k > a + b) return;
    for (int i = 1;  i <= 2; ++i)  // 1 gol echipa 1
    {
        x[k] = i;
        if ( Ok(k) )
            Back(k + 1);
    }
}

bool Ok(int k)
{
    if ( x[k] == 1) // gol echipa 1
    {
        if ( s1[k - 1] + 1 > a )
            return false;
        s1[k] = s1[k - 1] + 1;
        s2[k] = s2[k - 1];
    }
    if ( x[k] == 2 )
    {
        if ( s2[k - 1] + 1 > b )
            return false;
        s2[k] = s2[k - 1] + 1;
        s1[k] = s1[k - 1];
    }
    return true;
}

void Write(int n)
{
    nrsol++;
  /*  fout << "Solutia " << ++nrsol << " : \n";
    fout << "0 0\n";
    for (int i = 1; i <= n; ++i )
     //   if ( x[i] == 1 )
            fout << s1[i] << ' ' << s2[i] << '\n';
    fout << '\n';
*/
}
