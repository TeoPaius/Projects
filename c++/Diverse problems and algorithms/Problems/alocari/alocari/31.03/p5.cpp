
#include <iostream>
using namespace std;

struct Interval {
    int x, y;
public:
    Interval( int a, int b ) : x(a), y(b)
    {
    }
    Interval() : x(0), y(0)
    {
    }
    void Scrie() const
    {
        cout << x << ' ' << y << '\n';
    }
    Interval* GetInter( int a, int b )
    {
        return new Interval(a, b);
    }
};
int main()
{
    Interval a, *p;
    p = a.GetInterv(100, 200);
    p->Scrie();
    delete p;

    return 0;
}


