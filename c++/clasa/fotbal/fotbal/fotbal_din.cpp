#include <fstream>
using namespace std;

ifstream fin("fotbal.in");
ofstream fout("fotbal.out");

int a, b;
int nr[100][100]; // nr[i][j] - nr posibilitati ca la golul i
                  // echipa 1 sa aiba j goluri marcate

int main()
{
    fin >> a >> b;
    fin.close();

    for (int i = 0; i <= a; ++i)
        nr[i][i] = 1;

    for (int i = 0; i <= b; ++i)
        nr[i][0] = 1;

    for (int i = 1; i <= a + b; ++i)
        for (int j = 1; j <= i && j <= a; ++j)
            nr[i][j] = nr[i - 1][j] + nr[i - 1][j - 1];

    fout << nr[a + b][a];

    fout.close();
    return 0;
}
