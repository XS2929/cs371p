.DEFAULT_GOAL := all

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

all:
	cd examples; make all

clean:
	cd examples; make clean

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
	git add Dockerfile
	git add examples
	git add makefile
	git add notes
	git commit -m "another commit"
	git push
	git status

run:
	cd examples; make run

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete              \
    --include "Docker.txt"                   \
    --include "Hello.c++"                    \
    --include "UnitTests1.c++"               \
    --include "UnitTests2.c++"               \
    --include "UnitTests3.c++"               \
    --include "Coverage1.c++"                \
    --include "Coverage2.c++"                \
    --include "Coverage3.c++"                \
    --include "BoostSerialization.c++"       \
    --exclude "*"                            \
    ../../examples/c++/ examples

#	@rsync -r -t -u -v --delete              \
#    --include "IsPrime1.c++"                 \
#    --include "IsPrime2.c++"                 \
#    --include "Exceptions.c++"               \
#    --include "Variables.c++"                \
#    --include "Arguments.c++"                \
#    --include "Lambdas.c++"                  \
#    --include "Iterators.c++"                \
#    --include "Consts.c++"                   \
#    --include "Classes.c++"                  \
#    --include "Arrays.c++"                   \
#    --include "FunctionOverloading.c++"      \
#    --include "Move.c++"                     \
#    --include "MethodOverriding1.c++"        \
#    --include "MethodOverriding2.c++"        \
#    --include "Incr.c++"                     \
#    --include "Incr.h"                       \
#    --include "Equal.c++"                    \
#    --include "Equal.h"                      \
#    --include "Copy.c++"                     \
#    --include "Copy.h"                       \
#    --include "Fill.c++"                     \
#    --include "Fill.h"                       \
#    --include "AllOf.c++"                    \
#    --include "AllOf.h"                      \
#    --include "RMSE.c++"                     \
#    --include "RMSE.h"                       \
#    --include "RangeIterator.c++"            \
#    --include "RangeIterator.h"              \
#    --include "Range.c++"                    \
#    --include "Range.h"                      \
#    --include "Vector1.c++"                  \
#    --include "Vector1.h"                    \
#    --include "Vector2.c++"                  \
#    --include "Vector2.h"                    \
#    --include "Memory.h"                     \
#    --include "Vector3.c++"                  \
#    --include "Vector3.h"                    \
#    --include "Vector4.c++"                  \
#    --include "Vector4.h"                    \
#    --include "Shapes1.c++"                  \
#    --include "Shapes1.h"                    \
#    --include "Shapes2.c++"                  \
#    --include "Shapes2.h"                    \
#    --include "Shapes3.c++"                  \
#    --include "Shapes3.h"                    \
#    --include "Shapes.h"                     \
#    --include "Handle1.c++"                  \
#    --include "Handle1.h"                    \
#    --include "Handle2.c++"                  \
#    --include "Handle2.h"                    \
#    --include "UniquePtr.c++"                \
#    --include "UniquePtr.h"                  \
#    --include "SharedPtr.c++"                \
#    --include "SharedPtr.h"                  \
#    --include "Handle3.c++"                  \
#    --include "Handle3.h"                    \
#    --exclude "*"                            \
#    ../../exercises/c++/ exercises
#	@rsync -r -t -u -v --delete              \
#    --include "Collatz.c++"                  \
#    --include "Collatz.h"                    \
#    --include "RunCollatz.c++"               \
#    --include "RunCollatz.in"                \
#    --include "RunCollatz.out"               \
#    --include "TestCollatz.c++"              \
#    --include "TestCollatz.out"              \
#    --exclude "*"                            \
#    ../../projects/c++/collatz/ projects/collatz
#	@rsync -r -t -u -v --delete              \
#    --include "RunVoting.c++"                \
#    --include "RunVoting.in"                 \
#    --include "RunVoting.out"                \
#    --include "TestVoting.c++"               \
#    --include "TestVoting.out"               \
#    --include "Voting.c++"                   \
#    --include "Voting.h"                     \
#    --exclude "*"                            \
#    ../../projects/c++/voting/ projects/voting
#	@rsync -r -t -u -v --delete              \
#    --include "Allocator.h"                  \
#    --include "RunAllocator.c++"             \
#    --include "RunAllocator.in"              \
#    --include "RunAllocator.out"             \
#    --include "TestAllocator.c++"            \
#    --include "TestAllocator.out"            \
#    --exclude "*"                            \
#    ../../projects/c++/allocator/ projects/allocator
#	@rsync -r -t -u -v --delete              \
#    --include "Darwin.c++"                   \
#    --include "Darwin.h"                     \
#    --include "RunDarwin.c++"                \
#    --include "RunDarwin.in"                 \
#    --include "RunDarwin.out"                \
#    --include "TestDarwin.c++"               \
#    --include "TestDarwin.out"               \
#    --exclude "*"                            \
#    ../../projects/c++/darwin/ projects/darwin
#	@rsync -r -t -u -v --delete              \
#    --include "Life.c++"                     \
#    --include "Life.h"                       \
#    --include "RunLifeConway.c++"            \
#    --include "RunLifeConway.in"             \
#    --include "RunLifeConway.out"            \
#    --include "RunLifeFredkin.c++"           \
#    --include "RunLifeFredkin.in"            \
#    --include "RunLifeFredkin.out"           \
#    --include "RunLifeCell.c++"              \
#    --include "RunLifeCell.in"               \
#    --include "RunLifeCell.out"              \
#    --include "TestLife.c++"                 \
#    --include "TestLife.out"                 \
#    --exclude "*"                            \
#    ../../projects/c++/life/ projects/life

travis:
	cd examples; make travis

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
	-$(CLANG-CHECK) --version
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
	-$(CLANG-FORMAT) --version
