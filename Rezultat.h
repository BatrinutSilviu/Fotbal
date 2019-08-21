/*
 * Rezultat.h
 *
 *  Created on: Jul 18, 2019
 *      Author: batrinuts
 */
#pragma once
class Rezultat
{   short goluriAcasa;
    short goluriDeplasare;

    public:
    Rezultat();
    Rezultat(short goluriAcasa,short goluriDeplasare);
    short getGolAcasa();
    short getGolDeplasare();
};
