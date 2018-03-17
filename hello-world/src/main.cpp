#include <iostream>
#include "console.h"
#include "simpio.h"
#include "map.h"

using namespace std;

int main() {

    string name = getLine("Your Name Master: ");
    cout << "Welcome to CS106B! " << name << endl;

    Map<string, string> dic;

    return 0;
}
