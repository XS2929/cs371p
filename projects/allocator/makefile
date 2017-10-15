.DEFAULT_GOAL := all

FILES :=              \
    .gitignore        \
    allocator-tests   \
    Allocator.h       \
    Allocator.log     \
    html              \
    makefile          \
    RunAllocator.c++  \
    RunAllocator.in   \
    RunAllocator.out  \
    TestAllocator.c++

# uncomment these:
#    .travis.yml                               \
#    allocator-tests/GitHubID-RunAllocator.in  \
#    allocator-tests/GitHubID-RunAllocator.out \

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

allocator-tests:
	git clone https://github.com/cs371pt-fall-2017/allocator-tests.git

html: Doxyfile Allocator.h
	$(DOXYGEN) Doxyfile

Allocator.log:
	git log > Allocator.log

Doxyfile:
	$(DOXYGEN) -g
	# you must manually edit Doxyfile and
	# set EXTRACT_ALL     to YES
	# set EXTRACT_PRIVATE to YES
	# set EXTRACT_STATEIC to YES

RunAllocator: Allocator.h RunAllocator.c++
	$(CXX) $(CXXFLAGS) RunAllocator.c++ -o RunAllocator
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunAllocator.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunAllocator.c++  --

RunAllocator.c++x: RunAllocator
	./RunAllocator < RunAllocator.in > RunAllocator.tmp
	-diff RunAllocator.tmp RunAllocator.out

TestAllocator: Allocator.h TestAllocator.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestAllocator.c++ -o TestAllocator $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestAllocator.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestAllocator.c++ --

TestAllocator.c++x: TestAllocator
	$(VALGRIND) ./TestAllocator                                          >  TestAllocator.tmp 2>&1
	-$(GCOV) -b TestAllocator.c++ | grep -A 5 "File 'Allocator.h'"       >> TestAllocator.tmp 2>&1
	-$(GCOV) -b TestAllocator.c++ | grep -A 5 "File 'TestAllocator.c++'" >> TestAllocator.tmp
	cat TestAllocator.tmp

all: RunAllocator TestAllocator

check: $(FILES)

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  *.tmp
	rm -f  RunAllocator
	rm -f  TestAllocator
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/allocator -w /usr/allocator gpdowning/gcc

format:
	$(CLANG-FORMAT) -i Allocator.h
	$(CLANG-FORMAT) -i RunAllocator.c++
	$(CLANG-FORMAT) -i TestAllocator.c++

run: RunAllocator.c++x TestAllocator.c++x

scrub:
	make clean
	rm -f  Allocator.log
	rm -f  Doxyfile
	rm -rf allocator-tests
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

travis: allocator-tests html Allocator.log
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
