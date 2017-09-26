#include "copaci.h"
#include <iostream>
using namespace std;

Copac :: Copac(string t = " ", string z = " ") : tip(t), zona(z)
{
}

Copac :: Copac(const Copac& c) : tip(c.tip), zona(c.zona)
{
}

Copac :: GetTip()
{
    return tip;
}
