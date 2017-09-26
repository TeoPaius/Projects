#include <iostream>

// B -- clasa de baza (C++, C#)
// B -- superclasa (Java)
class B {
};

// "clasa D mosteneste public clasa B"
// D -- clasa derivata (C++, C#)
// D -- subclasa
class D : public B {
};


int main()
{
    D ob;

    return 0;
}
