#include <stdio.h> 

#define MAX 60002 

int a[MAX], n, s, ultpoz;

void Read(); 
void Write(); 
void Solve(); 

int main()
{  
    Read();  
    Solve();
    Write(); 
    
    return 0;
}     

void Read()
{  
    int aux;
    FILE *fin = fopen("masina.in", "r"); 
    fscanf(fin, "%d", &n); 
    for (int i = 1; i <= n; ++i) 
        fscanf(fin, "%d", &a[i*2-1]); 
    for (int i = 1; i <= n; ++i) 
    {
        fscanf(fin, "%d", &aux); 
        a[i*2] = -aux;
    }    
    fclose(fin);
}    

void Solve()
{  
    for (int i = 1; i <= 2*n; i += 2)
    { 
        s = a[i]; 
        for (int j = i + 1; j <= 2*n; ++j) 
        {  
            s += a[j];  
            ultpoz = j; 
            if (s < 0)  
                break;      
        }  
        if (ultpoz == 2*n)
        { 
            for (int j = 1; j < i; ++j) 
            {               
                s += a[j]; 
                ultpoz = j; 
                if (s < 0) 
                    break;
            }      
            return;
        }    
    }    
}    

void Write()
{  
    FILE *fout = fopen("masina.out", "w"); 
    fprintf(fout, "%d", (ultpoz + 2) / 2); 
    fclose(fout);
}    
