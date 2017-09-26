// Single inheritance (Mostenire simpla)
#include <iostream>

class B {
public:
    void F() const
    {
        std::cout << "F()\n";
    }
};

class D : public B {
public:
    void G() const
    {
        F();
        std::cout << "G()\n";
    }
};

int main()
{
    D ob;
    ob.F();
    ob.G();

    return 0;
}
