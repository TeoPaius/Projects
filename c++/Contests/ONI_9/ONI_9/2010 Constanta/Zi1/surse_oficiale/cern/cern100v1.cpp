// Sursa 100 puncte numai cu if-uri prof. Cristina Sichim - Bacau

# include <fstream.h>
ifstream fi("cern.in");
ofstream fo("cern.out");
long t;
int g,s,cerc;
char p;
int main()
{ fi>>p>>s>>t;
  t=t%1080;
  
  switch(p) 
  { case 'A': if (s==1) if(t<180) fo<<t<<" 1\n", t=0; else t=t-180,cerc=2,p='G';
			      else  if(t<120) fo<<360-t<<" 1\n",t=0; else t=t-120,cerc=3,p='I';
              break;
    case 'B': if (s==1) if(t<120) fo<<t+60<<" 1\n", t=0; else t=t-120,cerc=2,p='G';
			      else  if(t<180) fo<<(360-(t-60))%360<<" 1\n",t=0; else t=t-180,cerc=3,p='I';
              break;
    case 'C':if (s==1) if(t<180) fo<<t+120<<" 2\n", t=0; else t=t-180,cerc=3,p='H';
			      else  if(t<120) fo<<120-t<<" 2\n",t=0; else t=t-120,cerc=1,p='G';
              break;
	case 'D':if (s==1) if(t<120) fo<<t+180<<" 2\n", t=0; else t=t-120,cerc=3,p='H';
			      else  if(t<180) fo<<180-t<<" 2\n",t=0; else t=t-180,cerc=1,p='G';
              break;
	case 'E':if (s==1) if(t<180) fo<<(240+t)%360<<" 3\n", t=0; else t=t-180,cerc=1,p='I';
			      else  if(t<120) fo<<240-t<<" 3\n",t=0; else t=t-120,cerc=2,p='H';
              break;			  
				  
	case 'F':if (s==1) if(t<120) fo<<(300+t)%360<<" 3\n", t=0; else t=t-120,cerc=1,p='I';
			      else  if(t<180) fo<<300-t<<" 3\n",t=0; else t=t-180,cerc=2,p='H';
              break;			  
				  
  }
  
  s=-s;
  
  while(t)
  { switch(p)
  { case 'G': if(s==1) if(cerc==1) if (t>60)t=t-60,p='I'; else  fo<<180+t<<" 1\n",t=0;
							  else if (t>300) t=t-300,p='H'; else fo<<t<<" 2\n",t=0;
                  else if(cerc==1) if(t>300) t=t-300,p='I';else fo<<(540-t)%360<<" 1\n",t=0;
							 else if(t>60) t=t-60,p='H'; else fo<<360-t<<" 2\n",t=0;
			   cerc=3;
							 
			   break;
	case 'H': if(s==1) if(cerc==3)if (t>300)t=t-300,p='I'; else fo<<120+t<<" 3\n",t=0;
                            else if(t>60) t=t-60,p='G'; else fo<<300+t<<" 2\n",t=0;
                  else if(cerc==3) if(t>60) t=t-60,p='I'; else fo<<120-t<<" 3\n",t=0;
							 else if(t>300) t=t-300,p='G'; else fo<<(300-t)%360<<" 2\n",t=0;
			   cerc=1;
			   break;	
			   
	case 'I': if(s==1) if(cerc==1)if(t>300)t=t-300,p='G'; else fo<<(240+t)%360<<" 1\n",t=0;
                            else if(t>60) t=t-60,p='H'; else fo<<60+t<<" 3\n",t=0;
                  else if(cerc==1) if(t>60) t=t-60,p='G'; else fo<<240-t<<" 1\n",t=0;
							 else if(t>300) t=t-300,p='H'; else fo<<(420-t)%360<<" 3\n",t=0;
			   cerc=2;
			   break;	
    }
	  s=-s;
  }
  
  fi.close();fo.close();
return 0;
}