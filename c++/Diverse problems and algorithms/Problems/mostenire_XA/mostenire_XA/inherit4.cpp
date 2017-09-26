// Single inheritance (Mostenire simpla)
#include <iostream>

class Animal {
public:
    Animal()
    {
        //std::cout << "S-a nascut un animal\n";
        std::cout << "Construiesc parterul\n";
    }
    ~Animal()
    {
        //std::cout << "A murit un animal\n";
        std::cout << "Daram parterul\n";
    }
};

class Caine : public Animal {
public:
    Caine()
    {
        //std::cout << "S-a nascut un caine\n";
        std::cout << "Construiesc etajul\n";
    }
    ~Caine()
    {
        //std::cout << "A murit un caine\n";
        std::cout << "Daram etajul\n";
    }
};

int main()
{
    Caine c; // Caine()
    return 0;
}
