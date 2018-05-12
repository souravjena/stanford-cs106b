/*
 * Title  : Fractal - Cantor Set (11-CS106B)
 * Author : Sourav Jena
 *
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "map.h"
#include "gwindow.h"

using namespace std;


void cantorSet(GWindow& window, int x, int y, int width, int levels);


int main() {

    GWindow window(800, 300);
//    window.drawLine(0,0,100,100);
    cantorSet(window, 50, 50, 700, 7);

    return 0;
}



void cantorSet(GWindow& window, int x, int y, int width, int levels){

    pause(50); // for animation

    if(levels > 0){

        // Draw Top Line
        window.drawLine(x, y, x + width, y); // (x1, y1, x2, y2)

        // Draw Bottom 2 Lines (using recursion)
        cantorSet(window, x, y+20, width/3, levels-1);
        cantorSet(window, x+2*width/3, y + 20, width/3, levels-1);

    }

}
