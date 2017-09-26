#include <fstream>
#include <cstring>
using namespace std;
ifstream is("cuvant.in");
ofstream os("cuvant.out");

string n;
string s;
char v[] = "aeiouAEIOU";
bool ok[100];
char aux1, aux2;

void Back(int k);
void Write();

int main()
{
    is >> n;

    Back(1);
    is.close();
    os.close();
    return 0;
}

void Back(int k)
{
    if(k > n.size())
    {
        Write();
        return;
    }
    for(int i = 0; i < n.size(); ++i)
    {
        aux1 = n[i];
        aux2 = s[k-1];
        if(strchr(v, aux1))
        {
            if(strchr(v, aux2) && aux2 != 0)
            {
                continue;
            }
        }
        if(!ok[i])
        {
            s[k] = n[i];
            ok[i] = true;
            Back(k+1);
            ok[i] = false;
        }


    }
}

void Write()
{
    for(int i = 1; i <= n.size(); ++i)
        os << s[i];
    os << '\n';
}
