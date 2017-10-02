// -----------
// Mon,  2 Oct
// -----------

/*
consts
casts
Factorial
lambdas
*/

int i = 2;
int j = i;

int* p = ...;
int* q = p;

using foo = int*;

using bar = function<int (int, int)>;

// C has only one cast

double  d;
double* p = &d;
int*    q = p;       // not ok
int*    q = (int*)p; // C cast is just a pair parens

// C++ has FOUR casts

const_cast
static_cast
reinterpret_cast
dynamic_cast

int  i = 2;
int& r = i; // most like what kind pointer: int* const
r = 3;

const int& s = i; // most like what kind pointer: const int* const

function<int (int, int)> foo = [] (int x, int y) -> int {return x * y;};

/*
Questions
    What is a recursive procedure vs. process?
    What is tail recursion?
    What's the pointer equivalent of a reference?
    What's the pointer equivalent of a const reference?
    What does accumulate() do?
*/
