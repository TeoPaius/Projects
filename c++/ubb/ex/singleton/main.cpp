#include <iostream>

using namespace std;

class Singleton
{
private:
   Singleton();

public:
   static Singleton instance()
   {
      static Singleton INSTANCE;
      return INSTANCE;
   }
};
int main()
{
    cout << "Hello world!" << endl;
    Singleton s = Singleton::instance();
    return 0;
}
