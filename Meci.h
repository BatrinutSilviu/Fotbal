/*
 * Meci.h
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#pragma once
#include "Echipa.h"
#include "Competitie.h"
#include "Rezultat.h"
class Meci
{
	Echipa echipa1;
	Echipa echipa2;
	Competitie competitie;
	Rezultat rezultat;

    public:
    Meci(Echipa echipa1, Echipa echipa2, Competitie competitie, Rezultat rezultat);
    Rezultat getRezultat();
    Echipa getEchipa1();
    Echipa getEchipa2();
    Competitie getCompetitie();
};
