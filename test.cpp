#include "Clasament.h"
#include "Echipa.h"
#include "Competitie.h"
#include "Rezultat.h"
#include "Meci.h"
#include <fstream>
using namespace std;

int main()
{
	Clasament clasament;
	Competitie competitie;
	ifstream echipeFile("echipe.txt");
	ifstream meciuriFile("meciuri.txt");
	string line;
	if( echipeFile.is_open() )
	{
		while( getline( echipeFile, line ) )
		{
			Echipa echipa(line, 0, 0);
			clasament.addTeam(echipa);
		}
		echipeFile.close();
	}
	string nume1, nume2;
	short rez1, rez2;
	if( meciuriFile.is_open() )
	{
		while( getline( meciuriFile, line ) )
		{
			nume1=line.substr(0, 3);
			nume2=line.substr(4, 3);
			rez1= (short)stoi( line.substr(8, 1) );
			rez2= (short)stoi( line.substr(10, 1) );
			Echipa ech1(nume1);
			Echipa ech2(nume2);
			Rezultat rezultat(rez1, rez2);
			Meci meci(ech1, ech2, competitie, rezultat);
			clasament.addMatch(meci);
		}
		meciuriFile.close();
	}
    clasament.calcul();
    short opt;
    do{
    	cout<<"1.Afisare coeficient\n";
    	cout<<"2.Afisare punctaj\n";
    	cin>>opt;
    	switch(opt)
    	{
    	case 1:
    		clasament.afisareCoef();
    		break;
    	case 2:
    		clasament.afisarePuncte();
    		break;
    	}
    }while(opt!=0);
	return 0;
}
