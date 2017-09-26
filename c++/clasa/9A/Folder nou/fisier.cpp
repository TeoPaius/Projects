#include <fstream>
using namespace std;

int main()
{
    ifstream is ("suma.in"); // "deschidem" fisierul de intrare
    int x , y ;
    is >> x;
    is >> y;
    is.close();

    ofstream os ("suma.out"); // "deschidem" fisierul de iesire
    os << x + y;
    os.close();
    return 0;


}
