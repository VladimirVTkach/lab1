#include <gtest/gtest.h>
#include "../../src/graph/adjacent_undirected_graph.h"

TEST(adjacent_undirected_graph_int_test, test_add_vertex) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    adjacent_undirected_graph.AddVertex(vertex1);

    const auto &adjacency_lists = adjacent_undirected_graph.GetAdjacencyLists();
    ASSERT_TRUE(adjacency_lists.contains(Vertex<int>{vertex1}));
}

TEST(adjacent_undirected_graph_int_test, test_add_edge_when_all_vertices_present) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    const auto &adjacency_lists = adjacent_undirected_graph.GetAdjacencyLists();

    const auto &found_vertex1_it = adjacency_lists.find(Vertex<int>{vertex1});
    auto &adjacent_vertex1_edges = found_vertex1_it->second;

    const auto &found_vertex2_it = adjacency_lists.find(Vertex<int>{vertex2});
    auto &adjacent_vertex2_edges = found_vertex2_it->second;

    ASSERT_TRUE(adjacent_vertex1_edges.contains(Edge<int>{vertex1, vertex2}));
    ASSERT_TRUE(adjacent_vertex2_edges.contains(Edge<int>{vertex1, vertex2}));
}

TEST(adjacent_undirected_graph_int_test, test_add_edge_when_one_vertex_absent) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    adjacent_undirected_graph.AddVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.AddEdge(vertex1, vertex2), std::runtime_error);
}

TEST(adjacent_undirected_graph_int_test, test_remove_vertex) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_lists = adjacent_undirected_graph.GetAdjacencyLists();

    ASSERT_FALSE(adjacency_lists.contains(Vertex<int>{vertex1}));
}

TEST(adjacent_undirected_graph_int_test, test_remove_vertex_for_all_adjacent_edges_removed_too) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 1;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    const auto &adjacency_lists = adjacent_undirected_graph.GetAdjacencyLists();

    const auto &found_vertex2_it = adjacency_lists.find(Vertex<int>{vertex2});
    auto &adjacent_vertex2_edges = found_vertex2_it->second;

    ASSERT_FALSE(adjacency_lists.contains(Vertex<int>{vertex1}));
    ASSERT_FALSE(adjacent_vertex2_edges.contains(Edge<int>{vertex1, vertex2}));
}

TEST(adjacent_undirected_graph_int_test, test_remove_edge_when_all_vertices_present) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.RemoveEdge(vertex1, vertex2);

    const auto &adjacency_lists = adjacent_undirected_graph.GetAdjacencyLists();

    const auto &found_vertex1_it = adjacency_lists.find(Vertex<int>{vertex1});
    auto &adjacent_vertex1_edges = found_vertex1_it->second;

    const auto &found_vertex2_it = adjacency_lists.find(Vertex<int>{vertex2});
    auto &adjacent_vertex2_edges = found_vertex2_it->second;

    ASSERT_FALSE(adjacent_vertex1_edges.contains(Edge<int>{vertex1, vertex2}));
    ASSERT_FALSE(adjacent_vertex2_edges.contains(Edge<int>{vertex1, vertex2}));
}

TEST(adjacent_undirected_graph_int_test, test_remove_edge_when_one_vertex_absent) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    adjacent_undirected_graph.RemoveVertex(vertex1);

    ASSERT_THROW(adjacent_undirected_graph.RemoveEdge(vertex1, vertex2), std::runtime_error);
}

TEST(adjacent_undirected_graph_int_test, test_is_linked_when_graph_is_linked) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_TRUE(adjacent_undirected_graph.IsLinked());
}

TEST(adjacent_undirected_graph_int_test, test_is_linked_when_graph_is_not_linked) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);

    ASSERT_FALSE(adjacent_undirected_graph.IsLinked());
}

TEST(adjacent_undirected_graph_int_test, test_get_distance_when_all_vertices_present) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(1, adjacent_undirected_graph.GetDistance(vertex1, vertex3));
}

TEST(adjacent_undirected_graph_int_test, test_get_distance_when_one_vertex_absent) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    adjacent_undirected_graph.RemoveVertex(vertex3);

    ASSERT_THROW(adjacent_undirected_graph.GetDistance(vertex1, vertex3), std::runtime_error);
}

TEST(adjacent_undirected_graph_int_test, test_get_vertices_count) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    ASSERT_EQ(3, adjacent_undirected_graph.GetVerticesCount());
}

TEST(adjacent_undirected_graph_int_test, test_get_edges_count) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(3, adjacent_undirected_graph.GetEdgesCount());
}

TEST(adjacent_undirected_graph_int_test, test_get_adjacent_edges_count) {
    AdjacentUndirectedGraph<int> adjacent_undirected_graph;

    int vertex1 = 1;
    int vertex2 = 2;
    int vertex3 = 3;

    adjacent_undirected_graph.AddVertex(vertex1);
    adjacent_undirected_graph.AddVertex(vertex2);
    adjacent_undirected_graph.AddVertex(vertex3);

    adjacent_undirected_graph.AddEdge(vertex1, vertex2);
    adjacent_undirected_graph.AddEdge(vertex2, vertex3);
    adjacent_undirected_graph.AddEdge(vertex3, vertex1);

    ASSERT_EQ(2, adjacent_undirected_graph.GetAdjacentEdgesCount(vertex1));
}