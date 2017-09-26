#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int Sigma = 26;

struct Trie { // e de fapt un nod din Trie
    Trie()
    {
        nr_cuv = nr_sons = 0;
        memset ( son, 0, sizeof ( son ) );
    }

    int nr_cuv, nr_sons;       // nr_cuv ( nr de cuvinte care se termina pe acest nod)
    Trie* son[Sigma];
};

Trie *T = new Trie;
char sir[Sigma];
int tip;

void Insert( Trie *nod, char *s )
{
    if ( *s == '\0' )
    {
        nod->nr_cuv++;
        return;
    }

    if ( nod->son[*s - 'a'] == 0 )
    {
        nod->son[*s - 'a'] = new Trie;
        nod->nr_sons++;
    }

    Insert( nod->son[*s - 'a'], s + 1 );
}

bool Del( Trie *nod, char *s )
{
    if ( *s == '\0' )
        nod->nr_cuv--;
    else
        if ( Del( nod->son[*s - 'a'], s + 1 ) )
        {
            nod->son[*s - 'a'] = 0;
            nod->nr_sons--;
        }

    if ( nod->nr_cuv == 0 && nod->nr_sons == 0 && nod != T )
    {
        delete nod;
        return true;
    }

    return false;
}

int Count( Trie *nod, char *s )
{
    if ( *s == '\0' )
        return nod->nr_cuv;

    if ( nod->son[*s - 'a'] )
            return Count( nod->son[*s - 'a'], s + 1 );
    return 0;
}

int Prefix( Trie *nod, char *s, int k )
{
    if ( *s == '\0' || nod->son[*s - 'a'] == 0 )
        return k;

    return Prefix( nod->son[*s - 'a'], s + 1, k + 1 );
}

int main()
{
    ifstream f("trie.in");
    ofstream g("trie.out");

    while ( f.getline( sir, Sigma ) )
    {
        switch ( sir[0] )
        {
            case '0': Insert( T, sir + 2 );                   break;
            case '1': Del( T, sir + 2 );                     break;
            case '2': g << Count( T, sir + 2    ) << "\n";     break;
            case '3': g << Prefix( T, sir + 2, 0 ) << "\n";     break;

            default: cout << "Eroare!\n";   break;
        }
    }

    f.close();
    g.close();

    return 0;
}
