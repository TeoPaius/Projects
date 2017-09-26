// Single inheritance (Mostenire simpla)
#include <iostream>

class Animal {
    std::string specia;
public:
    Animal() : specia("mamifer")
    {
    }
    Animal(std::string sp) : specia(sp)
    {
    }
protected:
    std::string Get() const
    {
        return specia;
    }
};

class Caine : public Animal {
    std::string rasa;
    int varsta;
public:
    Caine()
        : rasa("labrador"), varsta(3)
    {
    }
    Caine(std::string sp, std::string r, int v)
        : Animal(sp), rasa(r), varsta(v)
    {
    }
    void Show() const
    {
        std::cout << Get() << ' ' << rasa
                  << ' ' << varsta << '\n';
    }
};

int main()
{
    Caine c1; // Caine()
    c1.Show();

    Caine c2("patruped", "doberman", 5);
    c2.Show();
    return 0;
}
