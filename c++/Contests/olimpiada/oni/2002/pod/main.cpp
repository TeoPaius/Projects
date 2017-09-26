#include <iostream>
using namespace std;
ifstream is("pod.in");
ofstream os("pod.out");

int n;
int a[301];
int lip;
int det;
int nr;

int main()
{
    is >> n;
    is >> lip;
    for(int i = 1; i <= lip; ++i)
    {
        is >> nr;
        a[nr] = 1;
    }
    is >> det;
    for(int i = i; i <= det; ++i)
    {
        is >> nr;
        a[nr] = 2;
    }
    int cnt = 0;




}
