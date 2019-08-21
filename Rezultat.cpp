/*
 * Rezultat.cpp
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#include "Rezultat.h"
Rezultat::Rezultat()
{

}

Rezultat::Rezultat(short goluriAcasa,short goluriDeplasare)
{
	this->goluriAcasa=goluriAcasa;
	this->goluriDeplasare=goluriDeplasare;
}

short Rezultat::getGolAcasa()
{
	return goluriAcasa;
}

short Rezultat::getGolDeplasare()
{
	return goluriDeplasare;
}


