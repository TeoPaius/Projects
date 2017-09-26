// Single inheritance (Mostenire simpla)
#include <iostream>

class B {
private:
    std::string s;
    void H() const
    {
    }
public:
    void F() const
    {
        H(); //  OK !!
        std::cout << "F()\n";
    }
protected:
    void Func() const
    {
        std::cout << "Func()\n";
    }
};

class D : public B {
public:
    void G() const
    {
        F();       // OK !!
     //   H();     // NO !!!
     //  s = "Ionel"; // NO !!!
        std::cout << "G()\n";
        Func();       // OK !!!!
    }
};

int main()
{
    D ob;
 // ob.F();     // OK
 // ob.G();     // OK
 // ob.Func();  // NO !!!

    B b;
//  b.Func();   // NO !!!

    return 0;
}
