#include <fstream>
using namespace std;

ifstream is ("trafic.in");
ofstream os ("trafic.out");

int n;
int ore[24];
int inceput;
int sfarsit;
int maxim = -1;

int main()
{
    is >> n;
    for(int i = 0; i < n; ++i)
    {
        is >> inceput;
        is >> sfarsit;
        while(inceput < sfarsit)
        {
            ore[inceput]++;
            inceput++;
        }
    }
    for(int i = 1; i < 24; ++i)
        if(ore[i] > maxim)
                maxim = ore[i];

    for(int i = 1; i < 24; ++i)
    {
        if (ore[i] == maxim)
        {
            os << i << ' ';
            while(ore[i] == maxim)
                ++i;
            os << i << '\n';
        }
    }

    is.close();
    os.close();
    return 0;
}
