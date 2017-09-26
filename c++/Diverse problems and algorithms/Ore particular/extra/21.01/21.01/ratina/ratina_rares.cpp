#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void FindEuler(int x, int niv);

int N, M;
vector<pair<char*, int> > V;
vector<int> Graph[200002];
int whereSort[10002], wordEndsIn[10002];
int inEuler[200002], level[400002];
int nodeNow, inFor, indEuler;
int RMQ[400002][19]; // RMQ[i][j] = RMQ(i, i + (1 << j) - 1);
int logN[400002];
char aux[10005][2005];

struct Trie
{
    int node;
    Trie* son[26];

    Trie()
    {
        node = 0;
        memset(son, 0, sizeof(son));
    }
};
Trie* T = new Trie;

void Tinsert(Trie* nod, char* S)
{
    if (*S == '\0')
    {
        wordEndsIn[inFor] = nod->node;
        return;
    }
    if (nod->son[*S - 'a'] == 0)
    {
        Trie* noda = new Trie;
        noda->node = ++nodeNow;
        nod->son[*S - 'a'] = noda;

        Graph[nod->node].push_back(noda->node);
    }
    Tinsert(nod->son[*S - 'a'], S + 1);
}

bool compare(const pair<char*, int>& p1, const pair<char*, int>& p2)
{
    int aux = strcmp(p1.first, p2.first);
    return (aux < 0);
}

int main()
{
    ifstream fin("ratina.in");
    ofstream fout("ratina.out");

    fin >> N >> M;

    fin.getline(aux[0], 2005);
    for (int i = 1; i <= N; ++i)
    {
        inFor = i;

        fin.getline(aux[i], 2005);
        Tinsert(T, aux[i]);
        V.push_back(make_pair(aux[i], i));
    }
    sort(V.begin(), V.end(), compare);

    for (int i = 1; i <= N; ++i)
        whereSort[V[i - 1].second] = i - 1;

    FindEuler(0, 0);

    for (int i = 2; i <= indEuler; ++i)
        logN[i] = logN[i >> 1] + 1;
    for (int j = 1; j <= indEuler; ++j)
        RMQ[j][0] = level[j];
    for (int i = 1; i <= logN[indEuler]; ++i)
        for (int j = 1; j <= indEuler; ++j)
        {
            RMQ[j][i] = RMQ[j][i - 1];
            if (j + (1 << (i - 1)) <= indEuler)
                RMQ[j][i] = min(RMQ[j][i], RMQ[j + (1 << (i - 1))][i - 1]);
        }

    int minN, maxN;
    for (int i = 1, T; i <= M; ++i)
    {
        minN = 1 << 30, maxN = -1;
        fin >> T;

        for (int j = 1, act; j <= T; ++j)
        {
            fin >> act;
            minN = min(whereSort[act], minN);
            maxN = max(whereSort[act], maxN);
        }

        int pos1 = min(inEuler[wordEndsIn[V[minN].second]], inEuler[wordEndsIn[V[maxN].second]]);
        int pos2 = max(inEuler[wordEndsIn[V[minN].second]], inEuler[wordEndsIn[V[maxN].second]]);

        int K = logN[pos2 - pos1 + 1];
        fout << min(RMQ[pos1][K], RMQ[pos2 - (1 << K) + 1][K]) << '\n';
    }

    fin.close();
    fout.close();
}

void FindEuler(int x, int niv)
{
    inEuler[x] = ++indEuler;
    level[indEuler] = niv;

    for (vector<int>::iterator it = Graph[x].begin(); it != Graph[x].end(); ++it)
    {
        FindEuler(*it, niv + 1);
        level[++indEuler] = niv;
    }
}
