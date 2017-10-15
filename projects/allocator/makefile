.DEFAULT_GOAL := test

FILES :=              \
    .gitignore        \
    Allocator.h       \
    Allocator.log     \
    html              \
    makefile          \
    RunAllocator.c++  \
    RunAllocator.in   \
    RunAllocator.out  \
    TestAllocator.c++ \
    TestAllocator.out

# uncomment these:
#    .travis.yml                               \
#    allocator-tests/GitHubID-RunAllocator.in  \
#    allocator-tests/GitHubID-RunAllocator.out \

ifeq ($(shell uname), Darwin)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++14 -I$(INCLUDE) -Wall -Weffc++
    LIBB         := /usr/local/lib
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest_main
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

.PHONY: allocator-tests
allocator-tests:
	git clone https://github.com/cs371pt-spring-2017/allocator-tests.git

html: Doxyfile
	doxygen Doxyfile

Allocator.log:
	git log > Allocator.log

Doxyfile:
	doxygen -g

# Make the following edits to Doxyfile.
# EXTRACT_ALL            = YES
# EXTRACT_PRIVATE        = YES
# EXTRACT_STATIC         = YES

RunAllocator: Allocator.h RunAllocator.c++
	$(CXX) $(CXXFLAGS) RunAllocator.c++ -o RunAllocator
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunAllocator.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunAllocator.c++  --

.PHONY: RunAllocator.tmp
RunAllocator.tmp: RunAllocator
	./RunAllocator < RunAllocator.in > RunAllocator.tmp
	diff RunAllocator.tmp RunAllocator.out

TestAllocator: Allocator.h TestAllocator.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TestAllocator.c++ -o TestAllocator $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestAllocator.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestAllocator.c++ --

.PHONY: TestAllocator.tmp
TestAllocator.tmp: TestAllocator
	$(VALGRIND) ./TestAllocator                                          >  TestAllocator.tmp 2>&1
	-$(GCOV) -b TestAllocator.c++ | grep -A 5 "File 'Allocator.h'"       >> TestAllocator.tmp
	-$(GCOV) -b TestAllocator.c++ | grep -A 5 "File 'TestAllocator.c++'" >> TestAllocator.tmp
	cat TestAllocator.tmp

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f  *.bin
	rm -f  *.db
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  RunAllocator
	rm -f  RunAllocator.tmp
	rm -f  TestAllocator
	rm -f  TestAllocator.tmp
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

format:
	$(CLANG-FORMAT) -i Allocator.h
	$(CLANG-FORMAT) -i RunAllocator.c++
	$(CLANG-FORMAT) -i TestAllocator.c++

scrub:
	make clean
	rm -f  Allocator.log
	rm -f  Doxyfile
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: html Allocator.log RunAllocator.tmp TestAllocator.tmp allocator-tests
	ls -al
	make check

versions:
	which make
	make --version
	@echo
	which git
	git --version
	@echo
	which $(CXX)
	$(CXX) --version
	@echo
	ls -ald $(INCLUDE)/boost
	@echo
	ls -ald $(INCLUDE)/gtest
	@echo
	ls -al $(LIBB)/*boost*
	@echo
	ls -al $(LIBG)/*gtest*
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
