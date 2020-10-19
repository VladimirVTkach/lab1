cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 src/main.cpp
        src/model/author.h
        src/model/author.cpp
        src/model/book.h
        src/model/book.cpp
        tst/model/author_tests.cpp
        tst/tests_runner.cpp
        tst/tests_runner.h
        tst/model/book_tests.cpp
        src/model/character.h
        src/model/character.cpp
        tst/model/character_tests.cpp
        src/graph/undirected_graph.h
        src/graph/adjacent_undirected_graph.h
        tst/graph/adjacent_undirected_graph_int_tests.cpp
        src/graph/matrix_undirected_graph.h
        tst/graph/matrix_undirected_graph_int_tests.cpp
        src/graph/vertex.h
        src/graph/edge.h
        tst/graph/adjacent_undirected_graph_double_tests.cpp
        tst/graph/matrix_undirected_graph_double_tests.cpp
        tst/graph/adjacent_undirected_graph_book_tests.cpp
        tst/graph/matrix_undirected_graph_book_tests.cpp
        src/view/console_view.h
        src/controller/main_menu_controller.h
        src/controller/crud_controller.h
        src/model/book_series.h
        src/model/book_series.cpp)

add_subdirectory(tst/lib/googletest-master)
include_directories(tst/lib/googletest-master/googletest include)
include_directories(tst/lib/googletest-master/googlemock include)

target_link_libraries(lab1 gtest gtest_main)