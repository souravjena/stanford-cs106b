/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: Sourav Jena
 * Section: Kelly Kapoor
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 *
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {

   cout << "Hello World!!" << endl;

   cout << intToString(1234567890);

   return 0;
}


string intToString(int n){

    int lastDigit;
    int restDigits;
    char c, d;
    int originalNum = n;

    if(n < 0){
        n = -n; // get absolute value of n
    }

    lastDigit = n % 10;
    restDigits = n / 10;

    if(restDigits < 10){
        // Base Case
        c = restDigits + '0';
        d = lastDigit + '0';
        
        return ( string(&c)[0] + string(&d) );

    } else {
        // Recursive Case
        c = lastDigit + '0';
        
        if(originalNum < 0){
            return ( '-' + intToString(restDigits) + string(&c)[0] );
        } else {
            return ( intToString(restDigits) + string(&c)[0] );
        }
        
    }



}


int stringToInt(string str){

return 0;

}
