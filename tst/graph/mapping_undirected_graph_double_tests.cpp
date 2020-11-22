#include <gtest/gtest.h>
#include "../../src/graph/mapping_undirected_graph.h"

TEST(matrix_undirected_graph_double_test, test_add_vertex) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.5;

    adjacent_undirected_graph.AddVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<double>{vertex1}));
}

TEST(matrix_undirected_graph_double_test, test_add_edge_when_all_vertices_present) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.2;
    double vertex2 = 2.33;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_TRUE(adjacency_matrix.contains(Vertex<double>{vertex1}));
    ASSERT_TRUE(adjacency_matrix.at(Vertex<double>{vertex1}).contains(Vertex<double>{vertex2}));
}

TEST(matrix_undirected_graph_double_test, test_add_edge_when_one_vertex_absent) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.1;
    double vertex2 = 2.11;

    adjacent_undirected_graph.AddVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.AddEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_double_test, test_remove_vertex) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.6;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<double>{vertex1}));
}

TEST(matrix_undirected_graph_double_test, test_remove_vertex_for_all_adjacent_edges_removed_too) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.0;
    double vertex2 = 2.0;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();

    ASSERT_FALSE(adjacency_matrix.contains(Vertex<double>{vertex1}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<double>{vertex2}).contains(Vertex<double>{vertex1}));
}

TEST(matrix_undirected_graph_double_test, test_remove_edge_when_all_vertices_present) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 3213.1;
    double vertex2 = 3131.1113;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.RemoveEdge(vertex1, vertex2);

    const auto &adjacency_matrix = adjacent_undirected_graph.GetAdjacencyMatrix();
    ASSERT_FALSE(adjacency_matrix.at(Vertex<double>{vertex1}).contains(Vertex<double>{vertex2}));
    ASSERT_FALSE(adjacency_matrix.at(Vertex<double>{vertex2}).contains(Vertex<double>{vertex1}));
}

TEST(matrix_undirected_graph_double_test, test_remove_edge_when_one_vertex_absent) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 31.1;
    double vertex2 = 3131.0;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.RemoveEdge(vertex1, vertex2), std::runtime_error);
}

TEST(matrix_undirected_graph_double_test, test_is_linked_when_graph_is_linked) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 11.1;
    double vertex2 = 311.3;
    double vertex3 = 535.53;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_TRUE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_double_test, test_is_linked_when_graph_is_not_linked) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.0;
    double vertex2 = 2.0;
    double vertex3 = 3.0;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    ASSERT_FALSE(adjacent_undirected_graph.IsLinked());
}

TEST(matrix_undirected_graph_double_test, test_get_distance_when_all_vertices_present) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 31.1;
    double vertex2 = 34.78;
    double vertex3 = 97.111;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(1, adjacent_undirected_graph.GetDistance(vertex1, vertex3));
}

TEST(matrix_undirected_graph_double_test, test_get_distance_when_one_vertex_absent) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.0;
    double vertex2 = 2.0;
    double vertex3 = 3.0;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    adjacent_undirected_graph.RemoveVertex(vertex3);

    ASSERT_THROW(adjacent_undirected_graph.GetDistance(vertex1, vertex3), std::runtime_error);
}

TEST(matrix_undirected_graph_double_test, test_get_vertices_count) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 313.1;
    double vertex2 = 525.1;
    double vertex3 = 85.1;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    ASSERT_EQ(3, adjacent_undirected_graph.GetVerticesCount());
}

TEST(matrix_undirected_graph_double_test, test_get_edges_count) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 1.1;
    double vertex2 = 2.2;
    double vertex3 = 3.3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(3, adjacent_undirected_graph.GetEdgesCount());
}

TEST(matrix_undirected_graph_double_test, test_get_adjacent_edges_count) {
    MappingUndirectedGraph<double> adjacent_undirected_graph;

    double vertex1 = 421.2;
    double vertex2 = 425.78;
    double vertex3 = 896.1333;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(2, adjacent_undirected_graph.GetAdjacentEdgesCount(vertex1));
}