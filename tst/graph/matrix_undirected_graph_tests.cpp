#include <gtest/gtest.h>
#include "../../src/graph/matrix_undirected_graph.h"

TEST(matrix_undirected_graph_test, test_add_int_vertex) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    adjacent_undirected_graph.AddVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<int>{vertex1}));
}

TEST(matrix_undirected_graph_test, test_add_int_edge_when_all_vertices_present) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<int>{vertex1}));
    ASSERT_TRUE(adjacency_matrix.at(Vertex<int>{vertex1}).contains(Vertex<int>{vertex2}));
}

TEST(matrix_undirected_graph_test, test_add_int_edge_when_one_vertex_absent) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    adjacent_undirected_graph.AddVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.AddEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_test, test_remove_int_vertex) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<int>{vertex1}));
}

TEST(matrix_undirected_graph_test, test_remove_int_vertex_for_all_adjacent_edges_removed_too) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<int>{vertex1}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<int>{vertex2}).contains(Vertex<int>{vertex1}));
}

TEST(matrix_undirected_graph_test, test_remove_int_edge_when_all_vertices_present) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.RemoveEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_FALSE(adjacency_matrix.at(Vertex<int>{vertex1}).contains(Vertex<int>{vertex2}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<int>{vertex2}).contains(Vertex<int>{vertex1}));
}

TEST(matrix_undirected_graph_test, test_remove_int_edge_when_one_vertex_absent) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.RemoveEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_test, test_int_is_linked_when_graph_is_linked) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_TRUE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_test, test_int_is_linked_when_graph_is_not_linked) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    ASSERT_FALSE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_test, test_int_get_distance_when_all_vertices_present) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(1, adjacent_undirected_graph.GetDistance(vertex1, vertex3));
}

TEST(matrix_undirected_graph_test, test_int_get_distance_when_one_vertex_absent) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    adjacent_undirected_graph.RemoveVertex(vertex3);

    ASSERT_THROW(adjacent_undirected_graph.GetDistance(vertex1, vertex3), std::runtime_error);
}

TEST(matrix_undirected_graph_test, test_int_get_vertices_count) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    ASSERT_EQ(3, adjacent_undirected_graph.GetVerticesCount());
}

TEST(matrix_undirected_graph_test, test_int_get_edges_count) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(3, adjacent_undirected_graph.GetEdgesCount());
}

TEST(matrix_undirected_graph_test, test_int_get_adjacent_edges_count) {
    MatrixUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1{1};
    int vertex2{2};
    int vertex3{3};

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(2, adjacent_undirected_graph.GetAdjacentEdgesCount(vertex1));
}