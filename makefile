.DEFAULT_GOAL := all

ifeq ($(shell uname), Darwin)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/local/lib
    LIBG         := /usr/local/lib
    LDFLAGS      := -lgtest -lgtest_main
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
    LIBB         := /usr/lib/x86_64-linux-gnu/
    LIBG         := $(PWD)/gtest
    LDFLAGS      := -lgtest -lgtest_main -pthread
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
    LIBB         := /usr/lib/x86_64-linux-gnu/
    LIBG         := /usr/lib
    LDFLAGS      := -lgtest -lgtest_main -pthread
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
    LDFLAGS      := -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.8
endif

all:
	cd examples; make all
	@echo
	cd projects/collatz; make all
	@echo
	cd projects/allocator; make all

clean:
	cd examples; make clean
	@echo
	cd projects/collatz; make clean
	@echo
	cd projects/allocator; make clean

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/cs371p -w /usr/cs371p gpdowning/gcc

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/cs371p.git
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .travis.yml
	git add examples
	git add makefile
	git add notes
	git add projects/collatz
	git add projects/allocator
	git add projects/darwin
	git add projects/life
	git commit -m "another commit"
	git push
	git status

run:
	cd examples; make run
	@echo
	cd projects/collatz; make run
	@echo
	cd projects/allocator; make run

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete              \
    --include "Docker.txt"                   \
    --include "Dockerfile"                   \
    --include "Hello.c++"                    \
    --include "Assertions.c++"               \
    --include "UnitTests1.c++"               \
    --include "UnitTests2.c++"               \
    --include "UnitTests3.c++"               \
    --include "Coverage1.c++"                \
    --include "Coverage2.c++"                \
    --include "Coverage3.c++"                \
    --include "IsPrime1.c++"                 \
    --include "IsPrime2.c++"                 \
    --include "Exceptions.c++"               \
    --include "Types.c++"                    \
    --include "Operators.c++"                \
    --include "Incr.c++"                     \
    --include "IncrGT.c++"                   \
    --include "Variables.c++"                \
    --include "Arguments.c++"                \
    --include "Equal.c++"                    \
    --include "EqualGT.c++"                  \
    --include "Iterators.c++"                \
    --include "Consts.c++"                   \
    --include "Factorial.c++"                \
    --include "FactorialGT.c++"              \
    --include "Fill1.c++"                    \
    --include "Fill2.c++"                    \
    --include "Iota1.c++"                    \
    --include "Iota2.c++"                    \
    --include "Accumulate1.c++"              \
    --include "Accumulate2.c++"              \
    --include "Copy1.c++"                    \
    --include "Copy2.c++"                    \
    --include "Transform1.c++"               \
    --include "Transform2.c++"               \
    --include "RangeIterator1.c++"           \
    --include "RangeIterator2.c++"           \
    --include "Range1.c++"                   \
    --include "Range2.c++"                   \
    --include "Arrays.c++"                   \
    --include "Vector1.c++"                  \
    --include "Vector2.c++"                  \
    --include "Vector3.c++"                  \
    --include "Vector4.c++"                  \
    --include "FunctionOverloading.c++"      \
    --include "Move.c++"                     \
    --include "Vector5.c++"                  \
    --include "Vector6.c++"                  \
    --include "Memory.h"                     \
    --include "Vector7.c++"                  \
    --include "Vector8.c++"                  \
    --include "Classes.c++"                  \
    --include "Shapes1.c++"                  \
    --include "Shapes1GT.c++"                \
    --include "MethodOverriding1.c++"        \
    --include "Shapes2.c++"                  \
    --include "Shapes2GT.c++"                \
    --include "MethodOverriding2.c++"        \
    --include "Shapes3.c++"                  \
    --include "Shapes3GT.c++"                \
    --include "Handle1.c++"                  \
    --include "Handle1GT.c++"                \
    --exclude "*"                            \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete              \
    --include "MethodOverriding1.java"       \
    --include "MethodOverriding2.java"       \
    --exclude "*"                            \
    ../../examples/java/ examples
	@rsync -r -t -u -v --delete              \
    --include "Darwin.uml"                   \
    --include "Stack1.uml"                   \
    --include "Stack2.uml"                   \
    --include "Shapes1.uml"                  \
    --include "Shapes2.uml"                  \
    --include "LifeCC.uml"                   \
    --include "LifeFC.uml"                   \
    --include "LifeC.uml"                    \
    --include "Shapes3.uml"                  \
    --include "Handle1.uml"                  \
    --include "Handle2.uml"                  \
    --exclude "*"                            \
    ../../examples/uml/ examples
	@rsync -r -t -u -v --delete              \
    --include "Collatz.c++"                  \
    --include "Collatz.h"                    \
    --include "RunCollatz.c++"               \
    --include "RunCollatz.in"                \
    --include "RunCollatz.out"               \
    --include "TestCollatz.c++"              \
    --include "TestCollatz.out"              \
    --exclude "*"                            \
    ../../projects/c++/collatz/ projects/collatz
	@rsync -r -t -u -v --delete              \
    --include "Allocator.h"                  \
    --include "RunAllocator.c++"             \
    --include "RunAllocator.in"              \
    --include "RunAllocator.out"             \
    --include "TestAllocator.c++"            \
    --include "TestAllocator.out"            \
    --exclude "*"                            \
    ../../projects/c++/allocator/ projects/allocator
	@rsync -r -t -u -v --delete              \
    --include "RunDarwin.c++"                \
    --include "RunDarwin.in"                 \
    --include "RunDarwin.out"                \
    --exclude "*"                            \
    ../../projects/c++/darwin/ projects/darwin
	@rsync -r -t -u -v --delete              \
    --include "RunLifeConway.in"             \
    --include "RunLifeConway.out"            \
    --include "RunLifeFredkin.in"            \
    --include "RunLifeFredkin.out"           \
    --include "RunLifeCell.in"               \
    --include "RunLifeCell.out"              \
    --exclude "*"                            \
    ../../projects/c++/life/ projects/life

travis:
	cd examples; make travis
	@echo
	cd projects/collatz; make travis
	@echo
	cd projects/allocator; make travis

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
