#include <iostream>
using namespace std;

struct Interval {
    int x, y;
    void Scrie() const
    {
        cout << x << ' ' << y << '\n';
    }
};
int main()
{
    Interval a;
    a.x = 10;
    a.y = 20;
    a.Scrie();

    Interval* p = &a;
    p->x = 100;
    p->y = 200;
    p->Scrie();

    p = new Interval();
    p->x = -100;
    p->y = -200;
    p->Scrie();

    delete p;

    return 0;
}


