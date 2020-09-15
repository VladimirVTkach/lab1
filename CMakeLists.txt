cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 src/main.cpp
        src/author.h
        src/author.cpp
        src/book.h
        src/book.cpp tst/author_tests.cpp tst/tests_runner.cpp tst/tests_runner.h tst/book_tests.cpp)

add_subdirectory(tst/lib/googletest-master)
include_directories(tst/lib/googletest-master/googletest include)
include_directories(tst/lib/googletest-master/googlemock include)

target_link_libraries(lab1 gtest gtest_main)