// ------------------------------
// projects/c++/life/TestLife.c++
// Copyright (C) 2017
// Glenn P. Downing
// ------------------------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, test) {
    Life<int> x;
    ASSERT_TRUE(x.dummy());}
