#include <iostream>
#include <string>
#include <fstream>

#include "console.h"
#include "simpio.h"
#include "map.h"
#include "filelib.h" // for crawl()
#include "vector.h"

using namespace std;

void printStars(int n); // Fuction to print stars without using for loop
int power(int base, int exponent); // Function to calculate power
bool isPalindrome(string s); // Function to check whether the string passed is a palindrome or not
void printBinary(int n); // Prints Binary of int
void reverseLine(ifstream &input); // Function to print lines from a file in LIFO order.
void crawl(string filename, string indent = ""); // Funtion to crawl given directory
int binarySearch(Vector<int>& v, int value, int start, int end); // Function to Binary Search a int Vector

int main() {

    // printStars(5);
    // cout << power(-1,2);
    // cout << isPalindrome("gog");
    // printBinary(-32);

    // ifstream myfile ("poem.txt");
    // reverseLine(myfile);

    // crawl("/home/sourav/Dropbox/projects/moocs/cs106b/lecture-codes/recursion/");

    Vector<int> v1;
    int end;

    for (int i = 0; i <= 50; i++)
        v1.add(i);

    end = v1.size();
    cout << v1[0] << endl;
    cout << binarySearch(v1, 50, 0, end);

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



// ------------------Reverse-Lines-------------------------------
void reverseLine(ifstream &input){

    string line;

    if(getline(input, line)){ // get the current line

        // if there is one more line then read again [resurcive case]
        reverseLine(input); // & is not required as input is already storing address

        // print the current line
        cout << line << endl;

    } else {
        // there are no lines left in the file
    }

}


// ------------------Crawl-Directory-------------------------------
void crawl(string filename, string indent){ // using default parameter for indentation

    cout << indent << getTail(filename) << endl;  // print only file-name/directory-name instead of whole path

    if( isFile(filename) ){
        // base case
    
    } else { // it must be a directory
        // recursive case
        Vector<string> files;
        listDirectory(filename, files); // fills the given vector<sting> with the names of all the files contained in the given directory

        for(string subfile : files){ // iterate through all the strings stored in vector<string> files
            crawl(filename + "/" + subfile, indent + " ");
        }
    
    }

}

//-------------------- Recursive Binary Search ----------------------
int binarySearch(Vector<int>& v, int value, int start, int end){

    int mid = (end + start)/2;

    // cout << start << "-" << mid << "-" << end << endl;

    if ( (mid < start) || ( mid > end) ){
        cout << "not found!!" << endl;
        return -1;
    }

    if(value == v[mid]){
        cout << "found it!!" << endl << endl;
        return mid;
    } else if (value < v[mid]) {
        // too small, go left
        cout << "left" << endl << endl;
        return binarySearch(v, value, start, mid-1);
    } else {
        // too big, go right
        cout << "right" << endl << endl;
        return binarySearch(v, value, mid+1, end);
    }
}





