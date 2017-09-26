#include <string>
#include <iostream>
using namespace std;

template <class T1, class T2>
struct pair {
	T1 first;
	T2 second;
	pair() : first(T1()), second(T2())  { }
	pair(const T1& x, const T2& y) : 
		first(x), second(y)  { }
	bool operator < (const pair& p) const
	{
		return first < p.first ||
			   (first == p.first && second < p.second);
	}
};

template <class T1, class T2>
::pair<T1, T2> make_pair(T1 t1, T2 t2)
{
	return ::pair<T1, T2>(t1, t2);
}

int main()
{
	::pair<string, int> p("Ionel", 12);
	cout << p.first << ' ' << p.second;
	set<::pair<int, int> > s;
	
}
