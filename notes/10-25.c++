// -----------
// Wed, 25 Oct
// -----------

struct A {};

/*
A()
A(A)
=(A)
~A()
*/

template <typename T>
class vector {
    private:
        T* _b;
        T* _e;

    public:
        vector (const vector& rhs) { // not ok
            _b = rhs._b;
            _e = rhs._e;}

        vector& operator = (const vector& rhs) { // not ok
            _b = rhs._b;
            _e = rhs._e;
            return *this;}

        vector (const vector& rhs) {
/*
            _b = nullptr;
            *this = rhs;}
*/
            _b = new T[rhs.size()]
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);}

        vector& operator = (vector rhs) {
            swap(_b, rhs._b);
            swap(_e, rhs._e);
/*
            // if (*this == rhs) // vector's  ==
            if (this == &rhs) // pointer's ==
                return *this;
            delete [] _b;
            _b = new T[rhs.size()]
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);
*/
            return *this;}

void f (vector<int> z) { // now works well
    ...}

vector<int> x(10, 2);
vector<int> y(x);
f(x);

vector<int> t(20, 3);
x = t;                // x.operator=(t)

x = x;
