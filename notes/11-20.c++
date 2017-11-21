// -----------
// Mon, 20 Nov
// -----------

class AbstractShape {
    virtual AbstractShape* clone () const = 0;

class Circle : public AbstractShape {
    Circle* clone () const {
        return new Circle(*this);}}

AbstractShape* p = new Circle(...);
AbstractShape* q = p->clone();

Circle* p = new Circle(...);
Circle* q = p->clone();

// return types of dynamically bound methods are COVARIANT

vector<Circle>   x(10, Circle(...));   // homogenous, only Circle
vector<Triangle> y(20, Triangle(...)); // homogenous, only Triangle

vector<AbstractShape*> z(30, Circle(...));     // not ok
vector<AbstractShape*> z(30, new Circle(...)); // ok, but stupid

{
vector<AbstractShape*> z;
for (int i = 0; i != 30; ++i)
    z[i] = new Circle(...);
z.push_back(new Triangle(...));
}

class Shape {
    private:
        AbstractShape* _p;

    public:
        Shape (AbstractShape* p) :
            _p (p)

        Shape (const Shape& rhs) :
            _p (rhs._p->clone())
            {}

        Shape& operator = (Shape rhs) {
            swap(_p, rhs._p);
            return *this;}

        ~Shape () {
            delete _p;}

{
Shape x = new Circle(...);
Shape y = new Triangle(...);

Shape z = y;
y = x;
}
