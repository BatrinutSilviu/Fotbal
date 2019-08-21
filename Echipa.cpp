/*
 * Echipa.cpp
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#include "Echipa.h"
#include <iostream>
Echipa::Echipa()
{

}
Echipa::Echipa(const Echipa &ech)
{
	nume=ech.nume;
	coeficient=ech.coeficient;
}
Echipa::Echipa(string nume, double coeficient, short puncte)
{
	this->nume=nume;
	this->coeficient=coeficient;
	this->puncte=puncte;
}

Echipa::Echipa(string nume)
{
	this->nume=nume;
	this->coeficient=0;
	this->puncte=0;
}

string Echipa::getNume()
{
	return nume;
}

double Echipa::getCoef()
{
	return coeficient;
}
short Echipa::getPuncte()
{
	return puncte;
}
void Echipa::setCoef(double coeficient)
{
	this->coeficient+=coeficient;
}
void Echipa::setPuncte(short puncte)
{
	this->puncte+=puncte;
}


