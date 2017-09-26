#include <iostream>
#include <cmath>
using namespace std;

#define eps 0.0001

struct Punct {
    double x,y;
} A, B, C, D;

double aa, bb, cc; // Coeficientii dreptei
Punct p[10];       // Punctele poligonului
int n;             // Nr de Puncte ale poligonului

double Panta(Punct A, Punct B);      // Tangenta unghiului dintre dreapta care trece prin punctele A si B, si axa Ox
bool Vertical(Punct A, Punct B);      // Verticalitatea dreptei care trece prin punctele  A si B
bool Paralele(Punct A, Punct B, Punct C, Punct D);   // Returneza true daca dreapta care trece prin punctele A si B
                                                          // e paralela cu cea care trece prin C si D
bool Perpendiculare(Punct A, Punct B, Punct C, Punct D);   // Returneza true daca dreapta care trece prin punctele A si B
                                                           // e perpendiculara cu cea care trece prin C si D
void Coeficienti(Punct A, Punct B);       // aa bb cc coef dreptei care trece prin punctele A si B (aa*x + bb*y + cc = 0 ) Intersec(Punct A, Punct B, Punct C, Punct D);   // Returneaza 1, daca segmentele [A,B] si [C,D] se intersecteaza
double Dist(Punct A, double a, double b, double c); // Distanta de la un punct A la o dreapta a*x + b*y + c = 0
bool Coliniare(Punct A, Punct B, Punct C);          // Returneaza true, daca punctele A, B, C sunt coliniare
double AriaTriunghi(Punct A, Punct B, Punct C);     // Aria triunghiului determinat de punctele A, B si C
double AriaPoligon(int n, Punct p[]);     // Aria poligonului (convex sau neconvex !) care trece prin punctele p[1], ... p[n]
bool PeCerc(double x0, double y0, double r, double x, double y);       // Returneaza tru daca punctul P(x, y) este pe cercul de raza r si centru (x0, y0)
int PozDreaptaCerc(Punct O,  double r, double a, double b, double c); // Pozitia unei drepte fata de un cerc
                                                                            // de centru O si raza r: exterioara, tangenta, secanta
bool PeTanCerc(Punct O, double r, Punct M, Punct P); // Determina daca punctul P apartine tangentei in M la cercul de centru O si raza r

int main()
{
    return 0;
}

double Panta(Punct A, Punct B)
{
    return (B.y - A.y) / (B.x - A.x);
}

bool Vertical(Punct A, Punct B)
{
    return fabs(A.x - B.x) < eps;
}

bool Paralele(Punct A, Punct B, Punct C, Punct D)
{
    if ( Vertical(A, B) || Vertical(C, D))
        if ( Vertical(A, B) && Vertical(C, D) ) return true;
        else return false;                                           // ATENTIE!
    if ( fabs(Panta(A, B) - Panta(C, D)) < eps )  return true;       // Doua numere reale nu se compara niciodata cu operatorul de egalitate == , datorita impreciziei de memorare!
    return false;                                                    // Se compara intotdeauna diferenta lor, cu o valoare foarte mica (eps) pe care o definiti voi
}

bool Perpendiculare(Punct A, Punct B, Punct C, Punct D) // dreptele det de segm [AB] si [CD]
{
    if ( Vertical(A, B) )                           // [A,B] vertical
        if ( fabs(C.y - D.y) < eps ) return true;   // [C,D] oriz
        else return false;

    if ( Vertical(C, D) )
        if (fabs (A.y - B.y) < eps ) return true;
        else return false;

    return  fabs ( Panta(A, B) * Panta(C, D) + 1 )  < eps;   // m1 * m2 = -1;
}

void Coeficienti(Punct A, Punct B)
{
    aa = A.y - B.y;
    bb = B.x - A.x;
    cc = A.x*B.y - B.x*A.y;
}

bool Intersec(Punct A, Punct B, Punct C, Punct D)
{
    Coeficienti(A, B);
    if ( (aa*C.x + bb*C.y + cc) * (aa*D.x + bb*D.y + cc) > 0 )   // C si D sunt in acelasi semiplan fata de dreapta
        return false;                                                        // care trece prin segmentul punctele A si B
    Coeficienti(C,D);
    if ((aa*A.x + bb*A.y + cc) * (aa*B.x + bb*B .y+cc) > 0 )   // A si B sunt in acelasi semiplan fata de dreapta
        return false;                                                        // care terce prin punctele C si D
    return true;
}

double Dist(Punct A, double a, double b, double c)  // Distanta de la punctul A la dreapta de coeficienti a, b, c (formula)
{
    return fabs( a*A.x + b*A.y + c ) / sqrt(a*a + b*b);
}

int PozDreaptaCerc(Punct O, double r, double a, double b, double c) // Pozitia unei drepte de coeficienti a, b, c
{                                                                   // fata de un cerc de centru O si raza r: exterioara, tangenta, secanta
    double dist = Dist(O, a, b, c);
    if ( dist - r > eps ) return 1;        // exterioara
    if ( fabs(dist - r ) < eps ) return 2; // tangenta
    return 3;                              // secanta
}

bool PeCerc(double x0, double y0, double r, double x, double y)  // centrul O(x0, y0), verif daca punctul (x, y) e pe cerc
{
    return fabs( (x-x0)*(x-x0) + (y-y0)*(y-y0) - r*r ) < eps;
}

bool Coliniare(Punct A, Punct B, Punct C)
{
    return fabs(A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x) < eps;
    //determinantul de coliniaritate e nul
}

double AriaTriunghi(Punct A, Punct B, Punct C)
{
    return fabs(A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x) / 2 ;
}

double AriaPoligon(int n, Punct p[])
{
    p[n+1] = p[1];
    int i;
    double s = 0;
    for (i = 1; i <= n; i++)
        s += p[i].x * p[i+1].y - p[i].y * p[i+1].x;
    return fabs(s/2);
}

// Ec tangentei in (x1, y1) la cerc:    (x - x0)*(x1-x0) + (y - y0)*(y1 - y0) = r^2;
bool PeTanCerc(Punct O, double r, Punct M, Punct P) // Determina daca punctul P apartine tangentei in M la cercul de centru O
{
    return fabs( (P.x - O.x)*( M.x - O.x) + (P.y - O.y)*(M.y - O.y) - r * r ) < eps;
}


