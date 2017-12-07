// -------------
// SharedPtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <algorithm> // swap
#include <memory>    // default_delete, shared_ptr

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename T>
class my_shared_ptr {
    public:
        using element_type = T;

    private:
        struct deleter {
            virtual      ~deleter ()         {}
            virtual void destroy  (T*) const = 0;};

        template <typename D = default_delete<T>>
        struct deleter_impl : deleter {
            D _d;

            deleter_impl (D d = D()) :
                    _d (d)
                {}

            virtual void destroy (T* p) const {
                _d(p);}};

        T*       _p;
        deleter* _q;
        int*     _c;

    public:
        explicit my_shared_ptr (T* p) :
                _p (p),
                _q ((p == nullptr) ? nullptr : new deleter_impl<>()),
                _c ((p == nullptr) ? nullptr : new int(1))
            {}

        template <typename D>
        explicit my_shared_ptr (T* p, D d) :
                _p (p),
                _q ((p == nullptr) ? nullptr : new deleter_impl<D>(d)),
                _c ((p == nullptr) ? nullptr : new int(1))
            {}

        my_shared_ptr (const my_shared_ptr& rhs) :
                _p (rhs._p),
                _q (rhs._q),
                _c (rhs._c) {
            if (_c != nullptr)
                ++*_c;}

        my_shared_ptr& operator = (const my_shared_ptr& rhs) {
            my_shared_ptr that(rhs);
            swap(that);
            return *this;}

        ~my_shared_ptr () {
            if (use_count() == 1) {
                _q->destroy(_p);
                delete _q;
                delete _c;}
            else if (_c != nullptr)
                --*_c;}

        T* get () const {
            return _p;}

        void swap (my_shared_ptr& that) {
            std::swap(_p, that._p);
            std::swap(_q, that._q);
            std::swap(_c, that._c);}

        int use_count () const {
            if (_c != nullptr)
                return *_c;
            return 0;}};

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

template <typename T>
struct SharedPtrFixture : Test {
    using shared_ptr_type = T;};

using
    shared_ptr_types =
    Types<
           shared_ptr<A>,
        my_shared_ptr<A>>;

TYPED_TEST_CASE(SharedPtrFixture, shared_ptr_types);

TYPED_TEST(SharedPtrFixture, test_1) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
//  shared_ptr_type x = new A;   // error: no viable conversion from 'A *' to 'shared_ptr_type'
    shared_ptr_type x(new A);
    ASSERT_EQ(1, x.use_count());
    ASSERT_EQ(1, A::c);
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(SharedPtrFixture, test_2) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    shared_ptr_type x(new A);
    shared_ptr_type y = x;
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(1, A::c);
    ASSERT_EQ(x.get(), y.get());
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(SharedPtrFixture, test_3) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    shared_ptr_type x(new A, [] (A* p) {delete p;});
    shared_ptr_type y(new A, default_delete<A>());
    ASSERT_EQ(2, A::c);
    ASSERT_NE(x.get(), y.get());
    x = y;
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(1, A::c);
    ASSERT_EQ(x.get(), y.get());
    }
    ASSERT_EQ(0, A::c);}
