#include <fstream>
#include <cstring>
#include <cctype>//header pt functia tolower , toupper

using namespace std;
ifstream fin ("cuvinte3.in");
ofstream fout ("cuvinte3.out");
char s[256], v[101][256], sep[]=" .,:;-?!";
int n;
bool apare ( char *s , char*t)
{
    char cs[256] , ct[256];
    strcpy(cs, s);
    strcpy(ct, t);
    for(int i = 0 ; i < strlen(cs) ; i++)
    {
        if(cs[i] >= 'A' && cs[i] <= 'Z')
            cs[i] += 32;
    }
    for(int i = 0; ct[i]!= '\0'; i++)
        ct[i] = tolower(ct[i]);
    if(strstr( cs, ct) != '\0')
        return true;
    return false;
}
int stricmp (char *s , char *t)
{
    char cs[256] , ct[256];
    strcpy(cs, s);
    strcpy(ct, t);
    for(int i = 0; i < strlen(cs); i++)
        cs[i]  = tolower(cs[i]);
    for(int i = 0 ; i < strlen(ct); i++)
          ct[i]  = tolower(ct[i]);
    return strcmp(cs,ct);
}
bool invector(char *s)
{
    for(int i = 1; i <= n; i++)
        if(stricmp( v[i], s) == 0)
            return true;
    return false;
}
int main()
{
    n = 0;
    while( fin.getline(s,256) )
    {
        char *p  = strtok(s, sep);
         while (p != NULL )
         {
            if(apare( p, "ate"))
                if( !invector( p ) )
                {
                    n++;
                    strcpy(v[n], p);
            }
            p = strtok (NULL, sep);
         }
    }
    for(int i =  1; i <= n; i++)
        fout << v[i] << '\n';
    fin.close();
    fout.close();
    return 0;
}
