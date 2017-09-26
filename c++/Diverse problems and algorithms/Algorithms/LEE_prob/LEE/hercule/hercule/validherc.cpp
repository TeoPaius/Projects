#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char  fcomisie[20];
char  fconcurent[] = "gems.out";
const int puncte[] = { 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
char ncomisie[500];
char nconcurent[500];

int main(int argc, char* argv[])
{
	clrscr();
	cout << "TESTUL " << argv[1] << " : " << endl << endl;
//	ofstream fpunc("punctaj.txt"); // deschid si inchid pt golire
//	fpunc.close();

	fstream fpunct("punctaj.txt", ios::app);
	strcpy(fcomisie, argv[1]);     // programul primeste ca parametru numarul testului
	strcat(fcomisie, ".out");

	int nrtest = atoi(argv[1]);

	ifstream fok(fcomisie);
	if (!fok)
	{
		cout << "Fisierul comisiei nu exista!" << endl;
		return 0;
	}

	ifstream fconc(fconcurent);
	if (!fconc)
	{
		cout << "Fisierul gems.out  nu exista!" << endl;
		fpunct << 0 << endl;
		fpunct.close();
		return 0;
	}


	int punctaj = 0;

	if ( !(fconc >> nconcurent) ) punctaj = 0;
	fok >> ncomisie;
	fok.close();
	fconc.close();
	if ( strcmp(nconcurent, ncomisie) ) punctaj = 0;
		else                      punctaj = puncte[nrtest];

	if ( punctaj )
		cout << "อออออออออออออออออออออออออออออออออออ\n" << endl << endl
			 << "CORECT ! ................ "
			 << puncte[nrtest]  << " PUNCTE" << endl <<
			 "อออออออออออออออออออออออออออออออออออ\n" << endl

					 << endl << endl
					 << endl << endl;
	else
		cout << endl
			 << "GRESIT ! .................. 0 PUNCTE " << endl
			 << "ออออออออออออออออออออออออออออออออออออ\n" << endl
			 << endl << endl << endl;

	fpunct << punctaj << endl; // ramane punctajul de la prima parte
	fpunct.close();


	return 0;

}















