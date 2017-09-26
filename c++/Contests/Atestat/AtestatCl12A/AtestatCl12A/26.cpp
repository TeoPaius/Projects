#include<iostream>
using namespace std;

int main()
{
    int n=0;
    for(int i=1;i<=5;i++)
        for(int j=i+1;j<=6;j++)
            for(int k=j+1;k<=7;k++)
                for(int h=k+1;h<=8;h++)
                    for(int g=h+1;g<=9;g++)
                        {
                            cout << i << j << k << h << g << h << k << j << i << '\n';
                            n++;
                        }
     cout << '\n' << n;
     return 0;
}
