#include <fstream>

using namespace std;
ifstream is("taxe.in");
ofstream os("taxe.out");

int n;
int s;
int a[101][101];
int c[101][101];


int main()
{
    is >> s;
    is >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            is >> a[i][j];
        }

    is.close();
    os.close();
    return 0;
}
