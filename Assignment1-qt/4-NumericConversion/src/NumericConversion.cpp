/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: Sourav Jena
 * Section: Kelly Kapoor
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 *
 * Implementation of integerToString() and stringToInteger() using recursion.
 */

#include <iostream>
#include <string>
#include "console.h"
#include <cmath> //pow()
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {

   cout << "This is a string " + intToString(1234567890) << endl;
   cout << "This is a string " + intToString(-1234567890) << endl;

   cout << stringToInt("1234567890")  + 1 << endl;
   cout << stringToInt("-1234567890") - 1 << endl;

   return 0;
}


string intToString(int n){

    int lastDigit;
    int restDigits;
    char c[2];
    char d[2];
    int originalNum = n;

    if(n < 0){
        n = -n; // get absolute value of n
    }

    lastDigit = n % 10;
    restDigits = n / 10;

    if(restDigits < 10){
        // Base Case

        c[0] = restDigits + '0';
        d[0] = lastDigit + '0';

        c[1] = '\0';
        d[1] = '\0';

        return ( string(c) + string(d) );

    } else {
        // Recursive Case

        c[0] = lastDigit + '0';
        c[1] = '\0';
        
        if(originalNum < 0){
            return ( '-' + intToString(restDigits) + string(c) );
        } else {
            return ( intToString(restDigits) + string(c) );
        }
        
    }



}


int stringToInt(string str){
    
    int length = str.length();
    bool negFlag = false;
    unsigned char c;
    unsigned char offset = 0;

    if(str[0] == '-'){ //In case of negative number string
        negFlag = true;
        offset = 1;
    }

    string lastDigit = str.substr(length-1, 1);
    string restDigits = str.substr(offset, length-1-offset);
    
    if(restDigits.length() == 0){
        // Base Case

        c = lastDigit[0] - '0';
        return ( (int)c );

    } else {
        // Recursive Case

        c = lastDigit[0] - '0';

        if(negFlag == true){
            return ( -1 * ( (stringToInt(restDigits) * 10) +  ( (int)c ) ) );
        } else {
            return ( (stringToInt(restDigits) * 10) +  ( (int)c ) );
        }


    }

}
