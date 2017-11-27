.DEFAULT_GOAL := all

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrime1                \
    IsPrime2                \
    Exceptions              \
    Types                   \
    Incr                    \
    IncrGT                  \
    Operators               \
    Arguments               \
    Equal                   \
    EqualGT                 \
    Iterators               \
    Consts                  \
    Factorial               \
    FactorialGT             \
    Fill1                   \
    Fill2                   \
    Iota1                   \
    Iota2                   \
    Accumulate1             \
    Accumulate2             \
    Copy1                   \
    Copy2                   \
    Transform1              \
    Transform2              \
    RangeIterator1          \
    RangeIterator2          \
    Range1                  \
    Range2                  \
    Arrays                  \
    Vector1                 \
    Vector2                 \
    Vector3                 \
    Vector4                 \
    FunctionOverloading     \
    Move                    \
    Vector5                 \
    Vector6                 \
    Vector7                 \
    Vector8                 \
    Classes                 \
    Shapes1                 \
    Shapes1GT               \
    MethodOverriding1       \
    Shapes2                 \
    Shapes2GT               \
    MethodOverriding2       \
    Handle1                 \
    Handle1GT

%: %.c++
	g++-5 -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall -Weffc++ $< -o $@ -lgtest -lgtest_main -pthread
	-clang-check -extra-arg=-std=c++11          $< --
	-clang-check -extra-arg=-std=c++11 -analyze $< --

%.c++x: %
	./$<
	gcov-5 -b $<.c++ | grep -A 5 "File '$<.c++'"

all: $(FILES)

clean:
	rm -f *.bin
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

run: $(FILES:=.c++x)

travis:
	make clean
	ls -al
	make
	ls -al
	make run
