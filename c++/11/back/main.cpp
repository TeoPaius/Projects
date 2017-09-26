#include <fstream>
using namespace std;

ifstream is ("1.in");
ofstream os ("1.out");

int a[100];
int n;
int cnt;

void Back(int pos, int val);
void Write();
bool Ok(int val, int pos);

int main()
{
    is >> n;
    Back(0, 1);
    is.close();
    os.close();
    return 0;
}

void Back(int pos, int val)
{

    if(!Ok(pos, val))
        Back(pos, val + 1);
    a[pos] = val;
    if(pos == n)
        return;
    Back(pos + 1, 1);


}

bool Ok(int val, int pos)
{
    if(val > n)
        return false;
    if(pos > n)
        return false;
    for(int i = 0; i < pos; ++i)
        if(val == a[i])
            return false;
    return true;
}

void Write()
{
    for(int i = 0; i < n; ++i)
        os << a[i] << ' ';
    os << '\n';
}
