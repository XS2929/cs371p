// -----------------------------------
// projects/c++/life/RunLifeConway.c++
// Copyright (C) 2017
// Glenn P. Downing
// -----------------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <fstream>  // ifstream
#include <iostream> // cout, endl, getline

#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // create Life<ConwayCell> objects
    // read  RunLifeConway.in
    // all input cells are Conway cells
    // write RunLifeConway.out

    // replace!
    ifstream fin("RunLifeConway.out");
    char a[80];
    while (fin.getline(a, 80))
        cout << a << endl;

    return 0;}
