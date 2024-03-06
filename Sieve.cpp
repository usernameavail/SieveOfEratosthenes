//
// Created by Shawn Plain on 2/11/24.
//
// ********************************************************
// * Sieve Source File                                    *
// * Description: Defines the functions and necessary     *
// *    data within the header file for the Sieve class.  *
// *    value.  Created for the COP330 course as an       *
// *    This file handles all member functions and        *
// *     constructors to  be used for the sieve class     *
// *     within the main file.                            *
// * Date: February 15, 2024                              *
// * Author: Shawn Plain                                  *
// ********************************************************
//




#ifndef SIEVE_SIEVE_CPP
#define SIEVE_SIEVE_CPP

#include "sieve.h"
#include <cstring>

Sieve::Sieve()
{
    lastnumber = DEFAULTMAXPRIME;
    bvect = new bool[lastnumber + 1];
    GeneratePrimes() ;
}

Sieve::Sieve(const int s)
{
    if(s<2) {lastnumber = DEFAULTMAXPRIME;}
    else {lastnumber = s;}
    bvect = new bool[lastnumber + 1];
    GeneratePrimes();
}

Sieve::~Sieve()
{
    if(bvect != nullptr)
    {
        delete[] bvect;
        bvect = nullptr;
    }

}


void Sieve::GeneratePrimes()
{
    //use bvect here with lastnumber and Sieve Alg to make the list.

    memset(bvect, true, sizeof(bool) * (lastnumber + 1));

    bvect[0] = false;
    bvect[1] = false;

    for (int i = 2; i * i <= lastnumber; i++)
    {
        if (bvect[i])
        {
            for(int j = i * i; j <= lastnumber; j += i)
            {
                bvect[j] = false;
            }
        }
    }
}

void Sieve::ReSet(const int s)
{
    if(bvect != nullptr)
    {
        delete[] bvect;
        bvect = nullptr;
    }
    if(s<2)
    {
        lastnumber = DEFAULTMAXPRIME;
        bvect = new bool[lastnumber +1];
        GeneratePrimes();
    }
    else
    {
        lastnumber = s;
        bvect = new bool[lastnumber +1];
        GeneratePrimes();
    }


}

bool Sieve::IsPrime(const int s)
{
    if (s < 2) {
        return false;
    }
    for(int i=2;i<=(sqrt(s));i++)
    {
        if(s % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Sieve::Print(std::ostream& os)
{
    os << "Prime numbers up to " << lastnumber << " are:\n";
    for (int i = 2; i <= lastnumber; ++i) {
        if (bvect[i]) {
            os << i << " \n";
        }
    }
    os << std::endl;
}

std::ostream& operator<<(std::ostream& os, Sieve& sieve) {
    sieve.Print(os);
    return os;
}

#endif
