#include <fstream>
using namespace std;
ifstream is ("maxsir.in");
ofstream os ("maxsir.out");


int main()
{
    int a, ap , maxim = 0;
    is >> a;
    int n[a];
    for(int i = 0; i < a; ++i)
    {
        is >> n[i];
        if(n[i] > maxim)
        {
            maxim = n[i];
            ap = 1;
        }
        else if(n[i] == maxim)
            ap ++;
    }
    os << "maximul este " << maxim << " si apare de " << ap << " ori";


    is.close();
    os.close();
    return 0;

}

