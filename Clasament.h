/*
 * Clasament.h
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#pragma once
#include <list>
#include <iostream>
#include <string>
#include "Echipa.h"
#include "Meci.h"

using namespace std;
class Clasament
{
	list<Echipa> echipe;
	list<Meci> meciuri;
public:
   Clasament();
   Clasament(const Echipa &echipa);
   void addTeam(Echipa echipa);
   void addMatch(Meci meci);
   void calcul();
   void afisareCoef();
   void afisarePuncte();
   void updateCoef(list <Echipa> :: iterator *itrtrE1, double echipaCoef, double compCoef, bool rezultat);
};
