// -----------
// Mon, 13 Nov
// -----------

const_cast
static_cast
reinterpret_cast

dynamic_cast

struct A {
    virtual void f (int) {...}};

struct B : A {
    void f (int) {...}};

int main () {
    A* p = new B;
    p->f(2);
    (*p).f(2);

class Circle : public Shape {
    private:
        int _r;

    public:
        virtual bool equals (const Shape& rhs) const {
            try {
                return dynamic_cast<const Circle&>(rhs)._r == _r && Shape::equals(rhs);}
            catch (bad_cast&)
                return false;}

struct A {
    virtual void f (long) {...}};

struct B : A {
    @override
    void f (int) {...} override

int main () {
    A* p = new B;
    p->f(2);      // B::f
