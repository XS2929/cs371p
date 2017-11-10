// -----------
// Fri, 10 Nov
// -----------

template <typename T>
class shape {
    friend bool operator != (const shape& lhs, const shape& rhs) {
        return (lhs._x != rhs._x) || (lhs._y != rhs._y);}

    private:
        T _x;
        T _y;

    public:
        Shape () = default;

        Shape (T x, T y) :
            _x (x),        // T(T)
            _y (y)         // T(T)
            {}

//        Shape (T x, T y) { // T(), T()
//            _x = x;        // =(T)
//            _y = y;}       // =(T)

        Shape& operator = (const Shape&) = default;

        bool operator == (const shape& rhs) const {
            return (_x == rhs._x) && (_y == rhs._y);}

        void move (T x, T y) {
            _x = x;
            _y = y;}

        double area () {
            return 0;}

// C++ new casts
static_cast
const_cast

class circle : public shape {
    friend bool operator != (const circle& lhs, const circle& rhs) {
        return (static_cast<const shape&>(lhs) != rhs) || (lhs._r != rhs._r);}

    private:
        T r;

    public:
        bool operator == (const circle& rhs) const {
            return shape::operator==(rhs) && (_r == rhs._r);}

        Circle (T x, T y, T r) :
            Shape(x, y),         // T(T), T(T)
            _r (r)               // T(T)
            {}

        double area () {
            return 3.14 * r * r;}

        T radius () {
            return r;}};

int main () {
    string s = "abc";
    string t = "def";
    cout << (s == t);
    cout << (s == "abc");
    cout << ("abc" == s);

struct A {
    void         f (int)    {...}
    virtual void g (int)    {...}
    void         g (double) {...}};

struct B : A {
    void f (int)    {...}
    void g (int)    {...}
    void g (double) {...}};

int main () {
    A* p = nullptr;

    if (...)
        p = new A;
    else
        p = new B;

    p->f(2);    // A::f
    p->g(2);    // <right one>
    p->g(2.34); // A::g

struct A''''' {
    int f (int) {...}
    int g (int) {...}};

...

struct B : ... {
    using A::g;

    int f (int)    {...}
    int g (string) {...}

int main () {
    A x;
    x.f(2); // A::f
    x.g(2); // A::g

    B y;
    y.f(2); // B::f
    y.g(2); // not ok
