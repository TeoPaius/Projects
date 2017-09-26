# include <fstream.h>
# include <math.h>

ifstream f("pesti.in");
ofstream g("pesti.out");

unsigned long n,x,a,b,c,z,u,p,zi=1;
long double r;

int main()
{  f>>n>>x;
  //cerinta a
   r=logl(n)/logl(2);
   if (r==floorl(r)) z=r-1;
     else z=r;
   
  //cerintele b si c
   a=1;b=n;u=0;
   do
    {
      p=x;
      if((x-a)%2==0) // grupa din stanga
       { b=(a+b)/2;
	     x=a+(x-a)/2;
	}
       else
	   { c=(a+b)/2;    //grupa din dreapta
	     x=c+(x-a+1)/2;
	     a=c+1;
	   }
     u++;
	 if(x!=p) zi=u;
	// g<<" in ziua "<<u<<" pozitia "<<x<<'\n';
   } while (b-a>1);
     //g<<" la final "<<z<<' '<<x<<' '<<zi<<'\n';
   g<<z<<' '<<x<<' '<<zi<<'\n';
f.close();g.close();
return 0;
}