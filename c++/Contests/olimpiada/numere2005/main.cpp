#include <fstream>
using namespace std;

ifstream is("numere.in");
ofstream os("numere.out");

int a[500][500];
bool b[60000];

int main()
{
    int n;
    is >> n;
    int mic = n * n;
    int mare = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            is >> a[i][j];
            b[a[i][j]] = true;
        }
    for(int i = 0; i < n * n; i++)
    {
        if(b[i] == false)
        {
            if(i > mare)
                mare = i;
            if(i < mic)
                mic = i;
        }
    }
    os << mic << ' ' << mare;
    is.close();
    os.close();
    return 0;
}
