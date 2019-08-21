/*
 * Meci.cpp
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#include "Meci.h"
Meci::Meci(Echipa echipa1, Echipa echipa2, Competitie competitie, Rezultat rezultat)
{
	this->echipa1=echipa1;
	this->echipa2=echipa2;
	this->competitie=competitie;
	this->rezultat=rezultat;
}

Rezultat Meci::getRezultat()
{
	return rezultat;
}

Echipa Meci::getEchipa1()
{
	return echipa1;
}

Echipa Meci::getEchipa2()
{
	return echipa2;
}

Competitie Meci::getCompetitie()
{
	return competitie;
}

