// -----------
// Fri, 20 Oct
// -----------

int i; // declaration
i = 2; // assignment

vs.

int i = 2; // initialization

Mammal x;
Tiger  y;

Mammal* p = &x;
p = &y;         // ok

Tiger* q = &y;
q = &x;        // not ok

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;

    public:
        vector () {
            _s = 0;
            _a = nullptr;}

        int size () const {
            return _s;}

        T& operator [] (int i) {
            return _a[i];}

        const T& operator [] (int i) const {
            return _a[i];}

int main () {
    vector<int> x(10, 2);
    cout << x.size();

    cout << x[1]; // cout << x.operator[](1); // 2
    x[1] = 3;

    const vector<int> y(20, 3);
    cout << y.size();

    cout << y[1]; // cout << y.operator[](1); // 2
    y[1] = 3;     // not ok














