.DEFAULT_GOAL := all

FILES :=            \
    .gitignore      \
    collatz-tests   \
    Collatz.c++     \
    Collatz.h       \
    Collatz.log     \
    html            \
    makefile        \
    RunCollatz.c++  \
    RunCollatz.in   \
    RunCollatz.out  \
    TestCollatz.c++ \
    TestCollatz.out

# uncomment these:
#    .travis.yml                           \
#    collatz-tests/GitHubID-RunCollatz.in  \
#    collatz-tests/GitHubID-RunCollatz.out \

ifeq ($(shell uname), Darwin)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/local/lib
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(CI), true)                                                 # Travis CI
    CXX          := g++-5
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := $(PWD)/gtest
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov-5
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(shell uname -p), unknown)                                  # Docker
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := /usr/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.5
else                                                                    # UTCS
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib/x86_64-linux-gnu
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.8
endif

collatz-tests:
	git clone https://github.com/cs371pt-fall-2017/collatz-tests.git

html: Doxyfile Collatz.h
	$(DOXYGEN) Doxyfile

Collatz.log:
	git log > Collatz.log

Doxyfile:
	$(DOXYGEN) -g
	# you must manually edit Doxyfile and
	# set EXTRACT_ALL     to YES
	# set EXTRACT_PRIVATE to YES
	# set EXTRACT_STATEIC to YES

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	$(CXX) $(CXXFLAGS) Collatz.c++ RunCollatz.c++ -o RunCollatz
	-$(CLANG-CHECK) -extra-arg=-std=c++11          Collatz.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze Collatz.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunCollatz.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunCollatz.c++  --

RunCollatz.c++x: RunCollatz
	./RunCollatz < RunCollatz.in > RunCollatz.tmp
	-diff RunCollatz.tmp RunCollatz.out

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) Collatz.c++ TestCollatz.c++ -o TestCollatz $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestCollatz.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestCollatz.c++ --

TestCollatz.c++x: TestCollatz
	$(VALGRIND) ./TestCollatz
	-$(GCOV) -b Collatz.c++ | grep -A 5 "File '.*Collatz.c++'"

all: RunCollatz TestCollatz

check: $(FILES)

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  *.tmp
	rm -f  RunCollatz
	rm -f  TestCollatz
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/collatz -w /usr/collatz gpdowning/gcc

format:
	$(CLANG-FORMAT) -i Collatz.c++
	$(CLANG-FORMAT) -i Collatz.h
	$(CLANG-FORMAT) -i RunCollatz.c++
	$(CLANG-FORMAT) -i TestCollatz.c++

run: RunCollatz.c++x TestCollatz.c++x

scrub:
	make clean
	rm -f  Collatz.log
	rm -f  Doxyfile
	rm -rf collatz-tests
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

travis: collatz-tests html Collatz.log
	make clean
	ls -al
	make run
	ls -al
	make -r check

versions:
	which cmake
	cmake --version
	@echo
	which make
	make --version
	@echo
	which git
	git --version
	@echo
	which $(CXX)
	$(CXX) --version
	@echo
	ls -adl $(INCLUDE)/boost
	@echo
	ls -adl $(INCLUDE)/gtest
	@echo
	ls -al $(LIBB)/libboost_serialization.a
	@echo
	ls -al $(LIBG)/libgtest.a
	ls -al $(LIBG)/libgtest_main.a
	@echo
	which $(CLANG-CHECK)
	$(CLANG-CHECK) --version
	@echo
	which $(GCOV)
	$(GCOV) --version
	@echo
	which $(VALGRIND)
	$(VALGRIND) --version
	@echo
	which $(DOXYGEN)
	$(DOXYGEN) --version
	@echo
	which $(CLANG-FORMAT)
	$(CLANG-FORMAT) --version
