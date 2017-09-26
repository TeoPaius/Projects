// OK
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

const int TESTE = 100;

/*
Fisierele sursa.exe, brut.exe si evaluator.exe trebuie sa se afle in acelasi folder in momentul rularii!
*/

int main()
{
    srand(time(0));

    for (int test = 1; test <= TESTE; ++test)
    {

        system("./gen_arb");

        int res1; // rezultatul dat de suras
        int res2; // rezultatul dat de brut

        // rulez prima sursa
        system("./nr_lanturi"); // pe windows
        // pe linux e: system("./sursa");

        ifstream in1("arb.out");
        in1 >> res1;
        in1.close();

        // rulez brut-ul
        system("./brut");

        ifstream in2("arb.out");
        in2 >> res2;
        in2.close();

        if (res1 == res2)
        {
            cerr << "OK!\n"; // afisare la standard error (ca sa apara sigur in terminal)
        }
        else
        {
            cerr << "WRONG! " << res1 << ' ' << res2 << '\n'; // e gresit, deci eval-ul se opreste (break) si afiseaza cele doua rezultate
            break;
        }
    }

//   system("pause"); // doar pe windows, pentru a apuca sa citesti mesajele afisate
}
