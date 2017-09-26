// sursa 100p - prof. Carmen Popescu  - implementare folosind set din stl

#include <fstream>
#include <set>
#include <iostream>

using namespace std;

ifstream f("roata.in");
ofstream g("roata.out");

int n,p;
long long s;
int a[100001];

struct nd{
	int cab,cl;
	long long rot;
};


bool comp (nd lhs, nd rhs) {return lhs.rot<rhs.rot || (lhs.rot==rhs.rot && lhs.cab<rhs.cab);}

bool(*p_comp)(nd,nd) = comp;
set<nd,bool(*)(nd,nd)> m(p_comp); 
set<nd,bool(*)(nd,nd)>::iterator it;


int main ()
{
	nd c;
	int i;
	set<nd,bool(*)(nd,nd)>::iterator it;
	
	f>>n>>p;
	s=0;
	for (i=0;i<p;i++) {
		f>>a[i]; s+=a[i];
	}
	g<<s<<"\n";
	if (p<=n) {
		for (i=0;i<p;i++) {
			c.cab=i+1;
			c.cl=i+1;
			c.rot=a[i];
			m.insert(c);
		}
		it=m.begin(); c=*it;
		g<<c.cl;
		it++;
		while (it!=m.end()) {
			c=*it;
			g<<" "<<c.cl;
			it++;
		}
		g<<"\n";
		g<<c.cab<<"\n";
	}
	else {
		for (i=0;i<n;i++) {
			c.cab=i+1;
			c.cl=i+1;
			c.rot=a[i];
			m.insert(c);
		}
		int pr=0;
		for (i=n;i<p;i++) {
			c=*m.begin();
			
			if (pr!=0)
				g<<" ";
			else
				pr=1;
			g<<c.cl;
			
			c.rot+=a[i];
			c.cl=i+1;
			
			m.erase(m.begin());
			m.insert(c);
		}
		for (it=m.begin();it!=m.end();it++) {
			c=*it;
			if (pr!=0)
				g<<" ";
			else
				pr=1;
			g<<" "<<c.cl;
		}
		g<<"\n"<<c.cab<<"\n";
	}
	
	g.close();
}
