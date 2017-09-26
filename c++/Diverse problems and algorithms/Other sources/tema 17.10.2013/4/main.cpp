#include <fstream>
using namespace std;
ifstream is("4.in");
ofstream os("4.out");

int NR[100];
int Baza(int x, int b);
void Det(int n, int b);
void Scrie(int n);

int main()
{
    int N;
    int B;
    is >> N >> B;
    Det(N, B);
    Scrie(N);
    is.close();
    os.close();
    return 0;
}

int Baza(int x, int b)
{
    int ok = 1;
    while(x != 0)
    {
        if(x % b != 0 && x % b != 1)
            ok = 0;
        x /= b;
    }
    return ok;
}

void Det(int n, int b)
{
    int cnt = 0;
    for(int i = 0; cnt < n; ++i)
    {
        if(Baza(i, b) == 1)
        {
            NR[cnt]= i;
            cnt++;
        }
    }
}

void Scrie(int n)
{
    for(int i = 0; i < n; ++i)
        os << NR[i] << '\n';
}
