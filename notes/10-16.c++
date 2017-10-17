// -----------
// Mon, 16 Oct
// -----------

int s;
cin >> s;
int a[s]; // not ok

int* a = new int[2]; // values? uninitialized values
++a;                 // ?
delete [] a;         // undefined

T* const a = new T[2]; // values? default constructor of T
++a;                   // not ok
delete [] a;           // undefined

/*
all things that you can do wrong with delete

1. bad address
2. deleting multiple times
3. never delete
4. delete too early
*/

/*
in Java, no memory management issue, because of a garbage collector
*/

/*
in C++ semi-automatic memory management

1. use class abstraction: constructors and destructors
2. use memory checker, like Valgrind
*/

allocator<double, 100> x;
double* p = x.allocate(3); // O(n), n is number of blocks
x.deallocate(p);           // O(1)

template <typename T, unsigned N>
class Allocator {
    private:
        char[N] x;

    public:
        ...
            at(x, 0) = (N - 8);

int& at (char* a, int i) {                 // writer of sentinel
    return reinterpret_cast<int&>(a[i]);}

int at (const char* a, int i) {            // reader of sentinel
    return reinterpret_cast<int&>(a[i]);}
