 #include <fstream>

using namespace std;

ifstream is("date.is");
ofstream os("date.out");

int main()
{
    int s[100], n=0, x, distmax = 0;
    bool a[100] = {false};
    int i = 0;
    while(is>>x)
    {
        ++i;
        if(a[x] == false)
        {
            a[x] = true;
            s[x] = i;
        }
        else
        {
            if(distmax < i -s[x])
                distmax = i - s[x];
        }
    }

    os<<distmax;
    return 0;
}

