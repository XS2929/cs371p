// -----------
// Wed,  1 Nov
// -----------

/*
refinement overriding
    the child is forced to call the corresponding method in the parent
    C++/Java: constructor
    C++: destructor

replacement overrding
    the child can choose to call the parent or not
    all other methods
*/

struct A : B {};

A()
~A()
A(A)
=(A)

T* a = new T[s];   // O(n); T(),  s times
fill(a, a + s, v); // O(n); =(T), s times

// use an allocator

allocator<T> x;
T* a = x.allocate(s);        // O(1)
for (int i = 0; i != s; ++i) // O(n)
    x.construct(a + i, v);   // O(1); T(T)

...

for (int i = 0; i != s; ++i) // O(n)
    x.destroy(a + i);        // O(1); ~T()
x.deallocate(a, s);
