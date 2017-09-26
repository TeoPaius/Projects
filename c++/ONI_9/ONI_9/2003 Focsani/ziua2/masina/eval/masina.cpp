#include <fstream.h>

int main()
{
    int x;
    ifstream fin("masina.in");
    fin >> x;
    fin.close();
    ofstream fout("masina.out");
    fout << x;
    fout.close();
    
    return 0;
}
