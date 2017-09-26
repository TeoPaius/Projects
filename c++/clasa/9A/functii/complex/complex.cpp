#include<cmath>
#include"complex.h"


double complex::modul(){
    return sqrt(a*a+b*b);

}void complex::setA(double re){
a=re;
}
void complex ::setB(double im){
b=im;
}
