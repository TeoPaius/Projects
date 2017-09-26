#include <iostream>
#include <string>
#include "Masina.h"
using namespace std;



int main()
{
    Masina a;

    Masina b = a;

    a.SetPret(20);

    Roata r(20, "gri");
    r.Show();


    return 0;
}
