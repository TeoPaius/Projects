#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;
ifstream is("twosets.in");
ofstream os("twosets.out");

string a, b;
vector<int> A, B;
set<int> C;
int t;
int nr;
int aux;
int cnt;

long long Convert(long long x, int nrcif);
bool Compare(vector<int> A, vector<int> B);

int main()
{

    is >> t;
    for(int i = 1 ; i <= t; ++i)
    {
        is >> a >> b;
        aux = 0;
        cnt = 0;

        for(int i = 0; i <= a.size(); ++i)
        {
            if(a[i] == 'i')
            {
                i++;
                aux = a[i] - '0';
                nr = nr*10 + aux;
                cnt++;
            }
            if(a[i] == 'd')
            {
                nr /= 10;
                cnt--;
            }
            if(a[i] == 't')
            {
                A.push_back(Convert(nr, cnt));
            }
        }

        aux = 0;
        cnt = 0;

        for(int i = 0; i <= b.size(); ++i)
        {
            if(b[i] == 'i')
            {
                i++;
                aux = b[i] - '0';
                nr = nr*10 + aux;
                cnt++;
            }
            if(b[i] == 'd')
            {
                nr /= 10;
                cnt--;
            }
            if(b[i] == 't')
            {
                B.push_back(nr);
            }
        }
    /*
        for( const auto& i : A)
        {
            os << i << ' ';
        }
        os << '\n';
        for( const auto& i : B)
        {
            os << i << ' ';
        }
        os << '\n';
        */
        if(Compare(A, B))
            os << "1";
        else
            os << "0";

        A.clear();
        B.clear();
        C.clear();
        os << '\n';

    }


    is.close();
    os.close();
    return 0;
}

long long Convert(long long x, int nrcif)
{
    int c = 0;
    long long trans = 0;
    while(x != 0)
    {
        trans += (x%10)<<c;
        c++;
        x/=10;
    }
    return trans;
}

bool Compare(vector<int> A, vector<int> B)
{
    if(A.size() != B.size())
        return false;
    for( const auto& i : A)
    {
        C.insert(i);
    }
    for( const auto& i : B)
    {
        C.insert(i);
    }
    if(C.size() == A.size())
        return true;
    return false;
}
