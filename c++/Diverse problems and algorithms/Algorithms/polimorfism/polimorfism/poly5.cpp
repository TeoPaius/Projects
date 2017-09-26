// POLIMORFISM
#include <iostream>
using namespace std;
/* Conditii pentru POLIMORFISM
   - sa existe o ierarhie de clase
   - sa avem un pointer sau o referinta la clasa de baza.
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

// O referinta la clasa de baza poate
// retine adrese ale obiectelor derivate
int main()
{
    Circle c;
    Shape& r = c;
    r.Draw();
    return 0;
}

