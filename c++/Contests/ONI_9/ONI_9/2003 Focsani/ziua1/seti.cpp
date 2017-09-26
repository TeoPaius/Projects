#include <stdio.h> 
#include <fstream> 

using namespace std;

#define MAX 200001

struct chestie {
    int val; 
    char sir[5];
} a[MAX], auxus;    

char alpha[11]; 
int q;

void Read(); 
void Write(); 
void QSort(int st, int dr);

int main()
{ 
    Read();
    QSort(1, q);
    Write();
    
    return 0;
}  

void Read()
{  
    char aux[5];
    ifstream fin("1.in");
    fin >> alpha; 
    while (fin >> aux) 
    {  
        q++;
        strcpy(a[q].sir, aux); 
        for (int i = 0; i < 4; ++i) 
            for (int j = 0; j < 10; ++j) 
                if (alpha[j] == aux[i])  
                    switch (i) {
                        case 0 : a[q].val += 1000 * j; break;
                        case 1 : a[q].val += 100 * j; break;
                        case 2 : a[q].val += 10 * j; break;
                        case 3 : a[q].val += j; break; 
                }    
    }    
    fin.close();
}   


void Write()
{ 
    FILE *fout = fopen("seti.out", "w");  
    for (int i = 1; i <= q; ++i) 
        fprintf(fout, "%s\n", a[i].sir);
    fclose(fout);
}  

void QSort(int li, int ls)
{
	int i = li - 1, j = ls + 1, pivot = a[li].val;
	do
  	{
		do { i++; } while ( a[i].val < pivot );
		do { j--; } while ( a[j].val > pivot );
		if (i <= j)
		{
			auxus = a[i];
			a[i] = a[j];
			a[j] = auxus;
		}
	} while (i <= j);
    if (li < j) QSort(li, j);
	if (i < ls) QSort(i, ls);
}          

    
