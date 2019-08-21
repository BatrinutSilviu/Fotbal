/*
 * Echipa.h
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#pragma once
#include <string>
using namespace std;

class Echipa
{
	string nume;
	double coeficient;
	short puncte;

	public:
	Echipa();
	Echipa(const Echipa &ech);
	Echipa(string nume, double coeficient, short puncte);
	Echipa (string nume);
	string getNume();
	double getCoef();
	short getPuncte();
	void setCoef(double coeficient);
	void setPuncte(short puncte);
};
