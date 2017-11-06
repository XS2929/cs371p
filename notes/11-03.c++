// -----------
// Fri,  3 Nov
// -----------

allocator<T> x;
T* a = x.allocate(s);
int i = 0;
try {
    while (i != s) {
        x.construct(a + i, v);
        ++i;}
catch (...) {
    int j = i;
    while (j != 0) {
        --j;
        x.destroy(j);}
    throw;}
...
for (int i = 0; i != s; ++i)
    x.destroy(a + i);
x.deallocate(a, s);

/*
what are the two main relationships between classes?
    inheritance
    containment

in Java
    vector
    stack extends vector, better thing to contain
*/

template <typename T, typename C = deque<T>>
class stack {
    private:
        C _c;

    public:
        stack () = default

        stack (const C& c) :
            _c (c)
            {}

        void push (const T& v) {
            _c.push_back(v);}

        void pop () {
            _c.pop_back();}

        T& top () {
            return _c.back();}

        const T& top () const {
            return _c.back();}};

void f (const stack<int>& y) {
    cout << y.top();
    y.top() = 2;}

int main () {
    stack<int> x;
    ...
    f(x);
    cout << x.top();
    x.top() = 2;

/*
stack
    vector
    deque (default)
    list
    push
    pop
    top (2)

queue
    deque (default)
    list
    push
    pop
    back (2)
    front (2)

priority_queue
    vector (default)
    deque
    push
    pop
    top (1)
*/
