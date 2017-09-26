#include <fstream>
using namespace std;

ifstream is ("disjoint.in");
ofstream os ("disjoint.out");

int n, m;
int t[100000], h[100000];
int op;
int a, b;

int Find(int x);
void Union(int x, int y);

int main()
{
    is >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        t[i] = i;
        h[i] = 1;
    }
    for(int i = 1; i <= m; ++i)
    {
        is >> op >> a >> b;
        if(op == 2)
        {
            if (Find(a) == Find(b))
                os << "DA" <<'\n';
            else
                os << "NU" << '\n';
        }
        if(op == 1)
        {
            int aux1 = Find(a);
            int aux2 = Find(b);
            Union(aux1, aux2);
        }
    }
    is.close();
    os.close();
    return 0;
}

int Find(int x)
{
    if (x == t[x])
        return x;
    return t[x] = Find(t[x]);
}

void Union(int x, int y)
{
    if(h[x] > h[y])
    {
        h[y] = 0;
        t[y] = x;
        return;
    }
    if(h[x] < h[y])
    {
        h[x] = 0;
        t[x] = y;
        return;
    }
    if(h[x] == h[y])
    {
        h[y] = 0;
        t[y] = x;
        h[x]++;
        return;
    }
}
