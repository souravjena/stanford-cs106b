/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Sourav Jena
 * Section: Toby Flanderson
 * This file is the starter project for the recursive combinations problem.
 *
 * A simple program to calculate combinations and print Pascal's Triangle
 */

#include <iostream>
#include <iomanip> //setw()
#include "console.h"
#include "simpio.h"
using namespace std;

float combinationFormula(float n, float k); // Function to calculate combinations using the mathematical formula
int combinationPascal(int n, int k);        // Fucntion to calculate combinations using Pascal's Triangle
void printPascal(int n);                    // Fucntion to print Pascal's Triangle

int main() {

   unsigned int n = getInteger("Enter n = ");
   unsigned int k = getInteger("Enter k = ");

   cout << "c(" << n << "," << k << ") = " << combinationPascal(n, k) << endl;

//   printPascal(n);

   return 0;
}

float combinationFormula(float n, float k){

    float num = 1;
    float deno1 = 1;
    float deno2 = 1;

    // n!
    for(int i = n; i > 0; i--){
        num = num * i;
    }
    //cout << "n! = " << num << endl;

    // k!
    for(int j = k; j > 0; j--){
        deno1 = deno1 * j;
    }
    //cout << "k! = " << deno1 << endl;

    // (n-k)!
    for(int x = (n - k); x > 0; x--){
        deno2 = deno2 * x;
    }
    //cout << "(n-k)! = " << deno2 << endl;


    return ( (num) / (deno1 * deno2) );

}


int combinationPascal(int n, int k){

    // Combinations using Pascal Triangle

    /*
     * From Pascal's Triangle we can see that,
     *
     * c(2,1) = c(1,1) + c(1,0)
     * c(3,1) = c(2,1) + c(2,0)
     * c(3,2) = c(2,2) + c(2,1)
     * c(5,3) = c(4,3) + c(4,2)
     *
     * c(n,k) = c(n-1, k) + c(n-1, k-1)
     *
     * both the ends are 1 in every row
     * c(n,0) = c(n,k=n) = 1
     *
     */

    if( k == 0 || k == n){
        return 1;

    } else {

        return ( combinationPascal(n-1, k-1) + combinationPascal(n-1, k) );

    }


}

void printPascal(int height){


        if(height > 10){ // to display only 1st 10 rows of Pascal Triangles
            height = 10;
        }


        for (int i = 0; i <= height; i++){

             cout << setw( (height-i) + 2 ) << endl;

            for(int j = 0; j <= i; j++){
                cout << combinationFormula(i, j) << " "; // combination function used here
            }

        }

}
