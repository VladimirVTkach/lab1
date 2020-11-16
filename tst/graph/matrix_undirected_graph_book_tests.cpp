#include <gtest/gtest.h>
#include <chrono>
#include <map>
#include "../../src/model/author.h"
#include "../../src/model/character.h"
#include "../../src/model/book.h"
#include "../../src/graph/matrix_undirected_graph.h"

TEST(matrix_undirected_graph_book_test, test_add_vertex) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");
    adjacent_undirected_graph.AddVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<Book>{vertex1}));
}

TEST(matrix_undirected_graph_book_test, test_add_edge_when_all_vertices_present) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");
    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<Book>{vertex1}));
    ASSERT_TRUE(adjacency_matrix.at(Vertex<Book>{vertex1}).contains(Vertex<Book>{vertex2}));
}

TEST(matrix_undirected_graph_book_test, test_add_edge_when_one_vertex_absent) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    adjacent_undirected_graph.AddVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.AddEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_book_test, test_remove_vertex) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<Book>{vertex1}));
}

TEST(matrix_undirected_graph_book_test, test_remove_vertex_for_all_adjacent_edges_removed_too) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<Book>{vertex1}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<Book>{vertex2}).contains(Vertex<Book>{vertex1}));
}

TEST(matrix_undirected_graph_book_test, test_remove_edge_when_all_vertices_present) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.RemoveEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_FALSE(adjacency_matrix.at(Vertex<Book>{vertex1}).contains(Vertex<Book>{vertex2}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<Book>{vertex2}).contains(Vertex<Book>{vertex1}));
}

TEST(matrix_undirected_graph_book_test, test_remove_edge_when_one_vertex_absent) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.RemoveEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_book_test, test_is_linked_when_graph_is_linked) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2";

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_TRUE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_book_test, test_is_linked_when_graph_is_not_linked) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    ASSERT_FALSE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_book_test, test_get_distance_when_all_vertices_present) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(1, adjacent_undirected_graph.GetDistance(vertex1, vertex3));
}

TEST(matrix_undirected_graph_book_test, test_get_distance_when_one_vertex_absent) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    adjacent_undirected_graph.RemoveVertex(vertex3);

    ASSERT_THROW(adjacent_undirected_graph.GetDistance(vertex1, vertex3), std::runtime_error);
}

TEST(matrix_undirected_graph_book_test, test_get_vertices_count) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    ASSERT_EQ(3, adjacent_undirected_graph.GetVerticesCount());
}

TEST(matrix_undirected_graph_book_test, test_get_edges_count) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(3, adjacent_undirected_graph.GetEdgesCount());
}

TEST(matrix_undirected_graph_book_test, test_get_adjacent_edges_count) {
    MatrixUndirectedGraph<Book> adjacent_undirected_graph;

    Book vertex1("Book 1",
                 {Author("Ivan",
                         "Ivanov",
                         std::chrono::year_month_day())},
                 111,
                 std::chrono::year_month_day(),
                 "description of Book 1");

    Book vertex2("Book 2",
                 {Author("Petr",
                         "Petrov",
                         std::chrono::year_month_day())},
                 222,
                 std::chrono::year_month_day(),
                 "description of Book 2");

    Book vertex3("Book 3",
                 {Author("Sidor",
                         "Sidorov",
                         std::chrono::year_month_day())},
                 333,
                 std::chrono::year_month_day(),
                 "description of Book 3");

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(2, adjacent_undirected_graph.GetAdjacentEdgesCount(vertex1));
}