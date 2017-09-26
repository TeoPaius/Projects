#include <fstream>
using namespace std;
ifstream is ("divsir.in");
ofstream os ("divsir.out");


int main()
{
    int a, div = 0, i = 0;
    //is >> a;
    int n[10];
    a=0;
    //for(int i = 0; i < a; ++i)
    while(!is.eof())
    {
        is >> n[i];
        a++;

    }
    for (i = 0; i < a - 1; ++i)
    {
        if(n[i] % n[a])
            div++;
    }
    os << "sunt " << div << " elemente";



    is.close();
    os.close();
    return 0;

}


