#include "Clasament.h"

Clasament::Clasament()
{

}
Clasament::Clasament(const Echipa &echipa)
{
	echipe.push_back(echipa);
}
void Clasament::addTeam(Echipa echipa)
{
    echipe.push_back(echipa);
}
void Clasament::addMatch(Meci meci)
{
    meciuri.push_back(meci);
}
void Clasament::updateCoef(list <Echipa> :: iterator *itrtrE, double echipaCoef, double compCoef, bool rezultat)
{
	double index = (*itrtrE)->getCoef() - echipaCoef;
	double add=0;
	if( (*itrtrE)->getCoef() !=0 && echipaCoef !=0 )
	{
		add=1000-index;
		if(add < 0)
		{
			add=5;
		}
	}
	if(rezultat == false)	//victorie
	{
		if( compCoef == 1 )
		{
			(*itrtrE)->setCoef(1000+add);
		}
		if( compCoef == 2 )
		{
			(*itrtrE)->setCoef(1500+add);
		}
		if( compCoef == 3 )
		{
			(*itrtrE)->setCoef(2000+add);
		}
		(*itrtrE)->setPuncte(3);
	}
	else	//egal
	{
		if( compCoef == 1 )
		{
			(*itrtrE)->setCoef(500+add);
		}
		if( compCoef == 2 )
		{
			(*itrtrE)->setCoef(750+add);
		}
		if( compCoef == 3 )
		{
			(*itrtrE)->setCoef(1000+add);
		}
		(*itrtrE)->setPuncte(1);
	}
}
bool compCoef( Echipa a,  Echipa b)
{
	if( a.getCoef() > b.getCoef() )
	{
		return true;
	}
	else
		return false;
}
bool compPuncte( Echipa a,  Echipa b)
{
	if( a.getPuncte() > b.getPuncte() )
	{
		return true;
	}
	else
		return false;
}
void Clasament::calcul()
{
	list <Meci> :: iterator itrtrM;
	list <Echipa> :: iterator itrtrE;
	for(itrtrM = meciuri.begin(); itrtrM != meciuri.end(); ++itrtrM)
	{
		if( (*itrtrM).getRezultat().getGolAcasa() > (*itrtrM).getRezultat().getGolDeplasare() )
		{
			for( itrtrE= echipe.begin(); itrtrE != echipe.end(); ++itrtrE )
			{
				if( (*itrtrE).getNume() == (*itrtrM).getEchipa1().getNume() )
				{
					double coef2=0;
					for( list <Echipa> :: iterator itrtrE1= echipe.begin(); itrtrE1 != echipe.end(); ++itrtrE1 )
					{
						if ( (*itrtrE1).getNume() == (*itrtrM).getEchipa2().getNume() )
						{
								coef2=(*itrtrE1).getCoef();
						}
					}
					updateCoef( &itrtrE, coef2, (*itrtrM).getCompetitie().getCoef(), false );
				}
			}
		}
		else
		{
			if( (*itrtrM).getRezultat().getGolAcasa() < (*itrtrM).getRezultat().getGolDeplasare() )
			{
				for( itrtrE= echipe.begin(); itrtrE != echipe.end(); ++itrtrE )
				{
					if( (*itrtrE).getNume() == (*itrtrM).getEchipa2().getNume() )
					{
						double coef2=0;
						for( list <Echipa> :: iterator itrtrE1= echipe.begin(); itrtrE1 != echipe.end(); ++itrtrE1 )
						{
							if ( (*itrtrE1).getNume() == (*itrtrM).getEchipa1().getNume() )
							{
									coef2=(*itrtrE1).getCoef();
							}
						}
						updateCoef( &itrtrE, coef2, (*itrtrM).getCompetitie().getCoef(), false );
					}
				}
			}
			else
			{
				for( itrtrE= echipe.begin(); itrtrE != echipe.end(); ++itrtrE )
				{
					if( (*itrtrE).getNume() == (*itrtrM).getEchipa2().getNume() )
					{
						double coef2=0;
						for( list <Echipa> :: iterator itrtrE1= echipe.begin(); itrtrE1 != echipe.end(); ++itrtrE1 )
						{
							if ( (*itrtrE1).getNume() == (*itrtrM).getEchipa1().getNume() )
							{
									coef2=(*itrtrE1).getCoef();
							}
						}
						updateCoef( &itrtrE, coef2, (*itrtrM).getCompetitie().getCoef(), true );
					}
					if( (*itrtrE).getNume() == (*itrtrM).getEchipa1().getNume() )
					{
						double coef2;
						for( list <Echipa> :: iterator itrtrE1= echipe.begin(); itrtrE1 != echipe.end(); ++itrtrE1 )
						{
							if ( (*itrtrE1).getNume() == (*itrtrM).getEchipa2().getNume() )
							{
									coef2=(*itrtrE1).getCoef();
							}
						}
						updateCoef( &itrtrE, coef2, (*itrtrM).getCompetitie().getCoef(), true );
					}
				}
			}
		}
	}
}
void Clasament::afisareCoef()
{
	echipe.sort(compCoef);
	cout<<'\t'<<"NUME"<<'\t'<<"COEFICIENT"<<"\n";
    list <Echipa> :: iterator it;
    short i;
    for(it = echipe.begin(), i=1; it != echipe.end(); ++it, i++)
        cout <<i<< '\t' << (*it).getNume()<<"\t"<<(*it).getCoef()<<"\n";
    cout << '\n';
}
void Clasament::afisarePuncte()
{
	echipe.sort(compPuncte);
	cout<<'\t'<<"NUME"<<'\t'<<"PUNCTE"<<"\n";
	list <Echipa> :: iterator it;
	short i;
	for(it = echipe.begin(), i=1; it != echipe.end(); ++it, i++)
		cout <<i<< '\t' << (*it).getNume()<<"\t"<<(*it).getPuncte()<<"\n";
	cout << '\n';
}
