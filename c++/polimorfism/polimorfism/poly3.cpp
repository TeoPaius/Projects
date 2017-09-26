// POLIMORFISM
#include <iostream>
using namespace std;
/* Conditii pentru POLIMORFISM
   - sa existe o ierarhie de clase
   - sa avem un pointer la clasa de baza.
   - sa existe cel putin o functie virtuala in clasa de baza
   - functia virtuala  sa fie REDEFINITA in clasele derivate
*/
class Shape {
public:
    virtual void Draw()
    {
        cout << "Draw a shape\n";
    }
};

class Circle : public Shape {
public:
    void Draw()
    {
        cout << "Draw a circle\n";
    }
};

class Rectangle : public Shape {
public:
    void Draw()
    {
        cout << "Draw a rectangle\n";
    }
};

class Square : public Rectangle {
public:
    void Draw()
    {
        cout << "Draw a square\n";
    }
};

// UN pointer la clasa de baza poate
// retine adrese ale obiectelor derivate
int main()
{
    // LEGARE DINAMICA
    // DYNAMIC BINDING (LATE BINDING)
    // Decizia asocierii intre APELUL unei functii
    // si CODUL care va fi executat SE IA RUN-TIME
    // in functie de TIPUL OBIECTULUI indicat de pointer
    Shape* p;

    p = new Shape();
    p->Draw();
    delete p;

    p = new Circle();
    p->Draw();
    delete p;

    p = new Rectangle();
    p->Draw();
    delete p;

    p = new Square();
    p->Draw();
    delete p;


    return 0;
}

