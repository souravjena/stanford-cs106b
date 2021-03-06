/*
 * File: Obenglobish.cpp
 * ----------------------
 * Name: Sourav Jena
 * Section: Jim Halpert
 * This file is the starter project for the Obenglobish problem.
 *
 * This program adds 'ob' before every vowel in the English word except when,
 *  •Vowels that follow other vowels
 *  •An e that occurs at the end of the word
 *
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

string obenglobish(string word);
bool checkVowel(char c);

/* Main program */

int main() {

    while (true) {

        string word = getLine("Enter a word: ");

        if (word == "") break;

        string trans = obenglobish(word);

        cout << word << " -> " << trans << endl;
    }

    return 0;
}


bool checkVowel(char c){

    if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ){
        return true;
    } else {
        return false;
    }

}

string obenglobish(string word){

    word = toLowerCase(word);
    string A;
    string B;
    int posPrevVowel = -100; //should not be -1 or 0

    for(int i = 0; i < word.length(); i++){

        if ( (i == word.length() - 1 ) && (word[i] == 'e') ){ // If last alphabet is 'e'

            // Do nothing

        } else if( checkVowel(word[i]) == true){

            if (i == posPrevVowel + 1){ // If vowels are consecutive

                posPrevVowel = i; // update previous vowel location to current location

            } else {

                A = word.substr(0, i);
                B = word.substr(i, word.length());
                word = A + "ob" + B;
                i = i + 2;
                posPrevVowel = i;

                // cout << posPrevVowel << "-" << i << "-" << word << endl;
            }
        }
    }

    return word;
}
