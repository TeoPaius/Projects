// ok infoarena
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
 
using namespace std;
 
const char infile[] = "ciclueuler.in";
const char outfile[] = "ciclueuler.out";
 
ifstream fin(infile);
ofstream fout(outfile);
 
const int MAXN = 100005;
const int oo = 0x3f3f3f3f;
 
typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;
 
const int lim = (1 << 20);
char buff[lim];
int pos;
 
inline void get(int &x) {
    while(!('0' <= buff[pos] && buff[pos] <= '9'))
        if(++ pos == lim) {
            pos = 0;
            fread(buff, 1, lim, stdin);
        }
    x = 0;
    while('0' <= buff[pos] && buff[pos] <= '9') {
        x = x * 10 + buff[pos] - '0';
        if(++ pos == lim) {
            pos = 0;
            fread(buff, 1, lim, stdin);
        }
    }
}
 
Graph G;
int N, M;
stack <int> st;
 
inline void Euler(int x) 
{
    st.push(x);
    vector <int> Ans;
    while(!st.empty()) {
        int Node = st.top();
        if(G[Node].size()) {
            int newNode = G[Node].back();
            G[Node].pop_back();
            G[newNode].erase(find(G[newNode].begin(), G[newNode].end(), Node));
            st.push(newNode);
        } else {
            st.pop();
            if(!st.empty())
                Ans.push_back(Node);
        }
    }
    for(It it = Ans.begin(), fin = Ans.end(); it != fin ; ++ it)
        fout << *it << ' ';
    fout << '\n';
}
 
inline bool checkEulerProperty(void) {
    for(int i = 1 ; i <= N ; ++ i)
        if(!G[i].size() || G[i].size() & 1)
            return false;
    return true;
}
 
int main() {
    freopen(infile, "r", stdin);
    get(N);
    get(M);
	int x, y;
    for(int i = 1 ; i <= M ; ++ i) {
        get(x); get(y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if(!checkEulerProperty())
        fout << "-1\n";
    else Euler(1);
    fin.close();
    fout.close();
    return 0;
}
