// ---------------------------------------
// projects/c++/allocator/RunAllocator.c++
// Copyright (C) 2017
// Glenn P. Downing
// ---------------------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <fstream>  // ifstream
#include <iostream> // cout, endl, getline

#include "Allocator.h"

// ----
// main
// ----

int main () {
    using namespace std;
    // read  RunAllocator.in
    // write RunAllocator.out

    // replace!
    ifstream fin("RunAllocator.out");
    char a[80];
    while (fin.getline(a, 80))
        cout << a << endl;
    return 0;}
