#ifndef COPACI_H
#define COPACI_H
using namespace std;
#include <string>

class Copac{
    string tip;
    string zona;
public:
    Copac(string t , string z);
    Copac(const Copac& c);
protected:
    void GetTip();



};

class Brad : public Copac{
    int height;
    string culoare;
public :
    Brad(int h, string culoare);

};


#endif // COPACI_H
