#include <fstream>
#include <string>
using namespace std;

ifstream is("copii.in");
ofstream os("copii.out");

class Copil {
    string nume;
    int clasa;
public:
    Copil(string , int );
    Copil();
    void Print() const;
    void SetName(string);
    void SetCls(int);
};

Copil::Copil(string num, int cls) : nume(num), clasa(cls)
{
}
Copil::Copil() : nume(""), clasa(0)
{
}
void Copil::Print() const
{
    os << nume << ' ' << clasa << '\n';
}
void Copil::SetName(string num)
{
    nume = num;
}
void Copil::SetCls(int cls)
{
    clasa = cls;
}

int main()
{
    int n;
    Copil* c;
    is >> n;
    c = new Copil[n];
    string nume;
    int clasa;
    for(int i = 0; i < n; ++i)
    {
        is >> nume >> clasa;
        c[i].SetName(nume);
        c[i].SetCls(clasa);
    }

    for(int i = 0; i < n; ++i)
        c[i].Print();
    delete [] c;
    is.close();
    os.close();
    return 0;
}


