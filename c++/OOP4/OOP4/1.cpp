#include <fstream>#include <stack> using namespace std; ifstream is("par.in");ofstream os("par.out"); int n;char a[5001];int cnt;stack<char> q; int main(){    is >> n;    if(n % 2 != 0)        cnt = -1;    else    {        for (int i = 1; i <= n; ++i)        {            is >> a[i];            if(q.empty())            {                if(a[i] == ')')                {                    cnt++;                    q.push('(');                }                if(a[i] == '(')                    q.push('(');            }            else            {                if(a[i] == '(')                    q.push(a[i]);                if(q.top() != a[i])                    q.pop();            }        }        cnt += q.size() / 2;    }    os << cnt;    is.close();    os.close();    return 0;}
