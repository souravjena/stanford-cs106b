/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: Sourav Jena
 * Section: Dwight Schrute
 * This file is the starter project for the coin-flipping problem.
 *
 * A program that simulates flipping a coin repeatedly and continues
 * until three consecutive heads are tossed.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {

    int headCount = 0;
    int flips = 0;
    bool isItHead;

    do{
       isItHead = randomBool();

       if(isItHead == true){
           cout << "HEADS" << endl;
           headCount++;

       } else {
           cout << "TAILS" << endl;
           headCount = 0;
       }

       flips++;

    } while (headCount < 3);

    cout << "It took " << flips << " flips to get 3 consecutive heads!!" << endl;

    return 0;
}
