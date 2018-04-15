#include <iostream>
#include "console.h"
#include "simpio.h"
#include "map.h"

using namespace std;

void printStars(int n); // Fuction to print stars without using for loop
int power(int base, int exponent); // Function to calculate power
bool isPalindrome(string s); // Function to check whether the string passed is a palindrome or not
void printBinary(int n); // Prints Binary of int

int main() {


//    printStars(5);
//    cout << power(-1,2);
    // cout << isPalindrome("gog");
    printBinary(-32);

    return 0;
}


// -------------------------------------------------
void printStars(int n){

    if(n == 1){
        // Base Case
       cout << "*";

    } else {
        // Recursive Case
        cout << "*";
        printStars(n-1);
    }


}

// -------------------------------------------------
int power(int base, int exponent){

    if(exponent == 0){
        // Base Case
        return 1;
    } else {
        // Recursive Case
        return (base * power(base, exponent-1));
    }
}

// -------------------------------------------------
bool isPalindrome(string s){

    string middle_str;
    s = toLowerCase(s); // so that the upper case and lower case characters are considered same

    if(s.length() <= 1){
        // Base Case
        return true;

    } else {
        // Recursive Case
        char first = s[0];
        char last = s[s.length() - 1];

        if(first == last){

            middle_str = s.substr(1, s.length() - 2);
            return isPalindrome(middle_str);

        } else {
            return false;
        }
    }
}



// -------------------------------------------------
void printBinary(int n){

    /*

    7 = 0111
    6 + 1 = 011 | 1
            011 = 3 = 7/2 ---> 3 = 011
            1   = 1 = 7%2      2+1 = 01 | 1  
                                01 = 1 = 3/2
                                1  = 1 = 3 % 2
    */

   if(n < 0){
     cout << "-";
     n = -n;
   }

   if( n == 0){
       // base case
       cout << "0";
   
   } else if ( n == 1) {
       // base case
       cout << "1";

   } else {

        int first = n / 2;
        int last = n % 2;

        printBinary(first);
        cout << last;
   }
   
}




