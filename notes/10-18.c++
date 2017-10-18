// -----------
// Wed, 18 Oct
// -----------

struct A {};

int main () {
    A x;     // A(),  default constructor
    A y = x; // A(A), copy    constructor
    y = x;   // =(A), copy    assignment
    }        // ~A(), destructor

int a[] = {2, 3, 4}; // int* const a
T   a[] = {2, 3, 4}; // T(int), 3 times

int a[10] = {2, 3, 4}; // 7 zeros
T   a[10] = {2, 3, 4}; // T(int), 3 times; T(), 7 times

int a[10]; // O(1), uninitialized values
T   a[10]; // O(n), T(), 10 times

int a[10] = {}; // O(n), 10 zeros
T   a[10] = {}; // O(n), T(), 10 times

int s;
cin >> s;
int a[s]; // not ok

int* a = new int[s]; // O(1), uninitialized values
T*   a = new   T[s]; // O(n), T(), s times

T* a = new T[s];   // O(n), T(),  s times
fill(a, a + s, v); // O(n), =(T), s times

vector<T>(s, v); // O(n), T(T), s times

allocator<T> x;              // O(1)
T* a = x.allocate(s);        // O(1)
for (int i = 0; i != s; ++i)
    x.construct(a + i, v)    // O(n)
...
for (int i = 0; i != s; ++i)
    x.destroy(a + i)         // O(n)
x.deallocate(a);             // O(1)
