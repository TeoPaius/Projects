#include <iostream>
using namespace std;

class Shape {
public:
    void Draw()
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
    // LEGARE STATICA
    // STATIC BINDING (EARLY BINDING)
    // Decizia asocierii intre APELUL unei functii
    // si CODUL care va fi executat SE IA COMPILE_TIME
    // in functie de TIPUL POINTERULUI
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

    p = new Circle();
    p->Draw();
    delete p;


    return 0;
}

