// ------------------------------------
// projects/c++/life/RunLifeFredkin.c++
// Copyright (C) 2017
// Glenn P. Downing
// ------------------------------------

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

    // create Life<FredkinCell> objects
    // read  RunLifeFredkin.in
    // all input cells are Fredkin cells
    // write RunLifeFredkin.out

    // replace!
    ifstream fin("RunLifeFredkin.out");
    char a[80];
    while (fin.getline(a, 80))
        cout << a << endl;

    return 0;}
