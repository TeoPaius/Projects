#include <fstream>
#include <algorithm>
using namespace std;

ifstream is ("multimi.in");
ofstream os ("multimi.out");

int main()
{
    int n, minim1, minim2, maxim1, maxim2;
    is >> n;
    is >> minim1 >> maxim1;
    for (int i = 0; i < n - 1; i++)
    {
        is >> minim2 >> maxim2;
        minim1 = max(minim1, minim2);
        maxim1 = min(maxim1, maxim2);
    }
    if (minim1 > maxim1)
        os << "multimea vida";
    else
    {
        while(minim1 <= maxim1)
        {
            if (minim1 < maxim1)
                os << minim1 << " ";
            else
                os << minim1;
            minim1++;
        }
    }

    return 0;
}
