cmake_minimum_required (VERSION 3.5.1)

project (Collatz CXX)

message (${CMAKE_SOURCE_DIR})
message (${CMAKE_BINARY_DIR})
message (${CMAKE_FILES_DIRECTORY})

set     (CMAKE_OBJECT_DIR ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY})
message (${CMAKE_OBJECT_DIR})

find_package (GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message      (${CLANG-CHECK})

find_program (GCOV gcov)
message      (${GCOV})

find_program (MAKE make)
message      (${MAKE})

find_program (VALGRIND valgrind)
message      (${VALGRIND})

set (CMAKE_CXX_FLAGS                    "-pedantic -Wall -Weffc++")
set (CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set (CMAKE_CXX_STANDARD                 14)
set (CMAKE_CXX_STANDARD_REQUIRED        ON)
set (CMAKE_CXX_EXTENSIONS               OFF)

add_custom_target (run)

add_executable (RunCollatz Collatz.c++ RunCollatz.c++)
target_link_libraries  (RunCollatz PRIVATE GTest::GTest GTest::Main)
add_custom_command (TARGET RunCollatz
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/Collatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/Collatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/Collatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/Collatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/RunCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/RunCollatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/RunCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/RunCollatz.c++ --)
add_custom_target (RunCollatz.c++x
    COMMAND echo ${CMAKE_BINARY_DIR}/RunCollatz '<' ${CMAKE_SOURCE_DIR}/RunCollatz.in '>' RunCollatz.tmp
    COMMAND      ${CMAKE_BINARY_DIR}/RunCollatz  <  ${CMAKE_SOURCE_DIR}/RunCollatz.in  >  RunCollatz.tmp
    COMMAND echo diff RunCollatz.tmp ${CMAKE_SOURCE_DIR}/RunCollatz.out
    COMMAND      diff RunCollatz.tmp ${CMAKE_SOURCE_DIR}/RunCollatz.out)
add_dependencies (RunCollatz.c++x RunCollatz)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} RunCollatz.c++x
    COMMAND      ${MAKE} RunCollatz.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "Collatz.plist"
    "RunCollatz.plist"
    "RunCollatz.tmp")

add_executable (TestCollatz Collatz.c++ TestCollatz.c++)
target_compile_options (TestCollatz PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries  (TestCollatz PRIVATE -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestCollatz
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestCollatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestCollatz.c++ --)
add_custom_command (OUTPUT gcov
    COMMAND echo mkdir -p gcov
    COMMAND      mkdir -p gcov)
add_custom_target (TestCollatz.c++x
    COMMAND echo ${VALGRIND} ${CMAKE_BINARY_DIR}/TestCollatz
    COMMAND      ${VALGRIND} ${CMAKE_BINARY_DIR}/TestCollatz
    COMMAND echo ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestCollatz.dir Collatz.c++ '|' grep -A 5 '"'File "'".*Collatz.c++"'"'"'
    COMMAND      ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestCollatz.dir Collatz.c++  |  grep -A 5   "File '.*Collatz.c++'"
    DEPENDS gcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcov)
add_dependencies (TestCollatz.c++x TestCollatz)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} TestCollatz.c++x
    COMMAND      ${MAKE} TestCollatz.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_OBJECT_DIR}/TestCollatz.dir/Collatz.gcda"
    "${CMAKE_OBJECT_DIR}/TestCollatz.dir/Collatz.gcno"
    "${CMAKE_OBJECT_DIR}/TestCollatz.dir/TestCollatz.gcda"
    "${CMAKE_OBJECT_DIR}/TestCollatz.dir/TestCollatz.gcno"
    "gcov"
    "TestCollatz.dSYM"
    "TestCollatz.plist")
