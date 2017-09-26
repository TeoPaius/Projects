#include <fstream>
using namespace std;

ifstream is ("roata.in");
ofstream os ("roata.out");

struct Urcari{
    int urc;
    int nr;
};

void Rotire();
int Gasire();
bool Rotire_f();

bool ok;
int cabine;
Urcari u[10000];
int clienti;
int s = 0;
Urcari roata[1000];
bool este = true;
int clienti_ramasi;
int cab;

int main()
{
    is >> cabine;
    is >> clienti;
    for(int i = 1; i <= clienti; ++i)
    {
        is >> u[i].urc;
        u[i].nr = i;
        s += u[i].urc;
    }
    clienti_ramasi = clienti;
    os << s << '\n';

    int client_curent = 1;
    for(int i = 1; i <= cabine; ++i)
    {
        roata[i] = u[client_curent];
        client_curent++;
        clienti_ramasi--;
    }
    while(client_curent <= clienti)
    {
        ok = false;
        Rotire();
        if(ok)
            for(int i = 1; i <= cabine; ++i)
            {
                if(roata[i].urc == 0)
                {
                    roata[i] = u[client_curent];
                    client_curent++;
                }
            }
    }
    while(este)
    {
        Rotire_f();
    }
    os << '\n' << cab;

    is.close();
    os.close();
    return 0;
}

void Rotire()
{
    for(int i = 1; i <= cabine; ++i)
    {
        roata[i].urc--;
        if(roata[i].urc == 0)
        {
            os << roata[i].nr << ' ';
            ok = true;
        }
    }
}

bool Rotire_f()
{
    este = false;
    for(int i = 1; i <= cabine; ++i)
    {
        if(roata[i].urc > 0)
        {
            roata[i].urc--;
            if(clienti_ramasi == 0)
                cab = i;
            if(roata[i].urc == 0)
            {
                os << roata[i].nr << ' ';
                clienti_ramasi--;
            }
            if(roata[i].urc > 0)
                este = true;
        }
    }
}

