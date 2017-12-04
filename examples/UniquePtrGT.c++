// ---------------
// UniquePtrGT.c++
// ---------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <algorithm>  // swap
#include <functional> // function
#include <memory>     // default_delete, unique_ptr
#include <utility>    // move

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename T, typename D = default_delete<T>>
class my_unique_ptr {
    public:
        using element_type = T;

    private:
        T* _p;
        D  _d;

    public:
        my_unique_ptr () :
                _p (nullptr),
                _d ()
            {}

        explicit my_unique_ptr (T* p) :
                _p (p),
                _d ()
            {}

        my_unique_ptr (T* p, D d) :
                _p (p),
                _d (d)
            {}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) :
                _p (rhs.release()),
                _d (move(rhs._d))
            {}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            if (this == &rhs)
                return *this;
            reset(rhs.release());
             _d = move(rhs._d);
            return *this;}

        ~my_unique_ptr () {
            reset();}

        T* get () const {
            return _p;}

        T* release () {
            T* p = _p;
            _p = nullptr;
            return p;}

        void reset (T* p = nullptr) {
            if (_p != p) {
                if (_p != nullptr)
                    _d(_p);
                _p = p;}}

        void swap (my_unique_ptr& that) {
            std::swap(_p, that._p);
            std::swap(_d, that._d);}};

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

template <typename T>
struct UniquePtrFixture : Test {
    using unique_ptr_type = T;};

template <typename T>
struct UniquePtrFixture2 : Test {
    using unique_ptr_type2 = T;};

using
    unique_ptr_types =
    Types<
           unique_ptr<A>,
        my_unique_ptr<A>>;

using
    unique_ptr_types2 =
    Types<
           unique_ptr<A, std::function<void (A*)>>,
        my_unique_ptr<A, std::function<void (A*)>>>;

TYPED_TEST_CASE(UniquePtrFixture,  unique_ptr_types);
TYPED_TEST_CASE(UniquePtrFixture2, unique_ptr_types2);

TYPED_TEST(UniquePtrFixture, test_1) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
//  unique_ptr_type x = new A; // error: no viable conversion from 'A *' to 'unique_ptr_type'
    unique_ptr_type x(new A);
    ASSERT_EQ(A::c, 1);
    }
    ASSERT_EQ(A::c, 0);}

TYPED_TEST(UniquePtrFixture, test_2) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr_type x(new A);
    ASSERT_EQ(A::c, 1);
//  unique_ptr_type y = x;       // error: call to implicitly-deleted copy constructor of 'unique_ptr_type'
//  unique_ptr_type y(x);        // error: call to implicitly-deleted copy constructor of 'unique_ptr_type'
    unique_ptr_type y = move(x);
    ASSERT_EQ(A::c,    1);
    ASSERT_EQ(x.get(), nullptr);
    }
    ASSERT_EQ(A::c, 0);}

TYPED_TEST(UniquePtrFixture, test_3) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr_type x(new A, default_delete<A>());
    unique_ptr_type y(new A, default_delete<A>());
    ASSERT_EQ(A::c, 2);
//  x = y;                       // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    ASSERT_EQ(A::c,    1);
    ASSERT_EQ(y.get(), nullptr);
    }
    ASSERT_EQ(A::c, 0);}

TYPED_TEST(UniquePtrFixture2, test_4) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type2;
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr_type x(new A, [] (A* p) -> void {delete p;});
    unique_ptr_type y(new A, [] (A* p) -> void {delete p;});
    ASSERT_EQ(A::c, 2);
//  x = y;                       // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    ASSERT_EQ(A::c,    1);
    ASSERT_EQ(y.get(), nullptr);
    }
    ASSERT_EQ(A::c, 0);}
