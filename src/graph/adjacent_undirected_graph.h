#pragma once

#include <map>
#include <set>
#include "undirected_graph.h"

template<typename T>
class AdjacentUndirectedGraph : public UndirectedGraph<T> {
public:
    void AddVertex(const T &vertex) override {
        Vertex<T> vertex_repr = GetVertexRepr(vertex);
        adjacency_lists_.try_emplace(vertex_repr, std::set<Edge<T>>());
    }

    void AddEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = GetVertexRepr(left);
        Vertex<T> right_vertex_repr = GetVertexRepr(right);

        if (!adjacency_lists_.contains(left_vertex_repr) ||
            !adjacency_lists_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> left_edge_repr = GetEdgeRepr(left_vertex_repr, right_vertex_repr);
        Edge<T> right_edge_repr = GetEdgeRepr(right_vertex_repr, left_vertex_repr);

        InsertEdge(left_vertex_repr, left_edge_repr);
        InsertEdge(right_vertex_repr, right_edge_repr);
        ++edges_count_;
    }

    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = GetVertexRepr(vertex);
        adjacency_lists_.erase(vertex_repr);
    }

    void RemoveEdge(const T &left, T &right) override {
        const Vertex<T> left_vertex_repr = GetVertexRepr(left);
        const Vertex<T> right_vertex_repr = GetVertexRepr(right);

        if (!adjacency_lists_.contains(left_vertex_repr) ||
            !adjacency_lists_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> left_edge_repr = GetEdgeRepr(left_vertex_repr, right_vertex_repr);
        Edge<T> right_edge_repr = GetEdgeRepr(right_vertex_repr, left_vertex_repr);

        DeleteEdge(left_vertex_repr, left_edge_repr);
        DeleteEdge(right_vertex_repr, right_edge_repr);
        --edges_count_;
    }

    bool IsLinked() override {
        return false;
    }

    int GetDistance(const T &left, const T &right) override {
        return 0;
    }

    size_t GetVerticesCount() override {
        return adjacency_lists_.size();
    }

    size_t GetEdgesCount() override {
        return edges_count_;
    }

    size_t GetAdjacentEdgesCount(const T &vertex) override {
        Vertex<T> vertex_repr = GetVertexRepr(vertex);
        auto vertex_iterator = adjacency_lists_.find(vertex_repr);
        if (vertex_iterator == adjacency_lists_.end()) {
            throw std::runtime_error("vertex doesn't exist");
        } else {
            return (vertex_iterator->second).size();
        }
    }

    const std::map<Vertex<T>, std::set<Edge<T>>> &GetAdjacencyLists() const {
        return adjacency_lists_;
    }


private:
    Vertex<T> GetVertexRepr(const T &vertex) {
        return Vertex<T>{vertex};
    }

    Edge<T> GetEdgeRepr(const Vertex<T> &left_vertex_repr, const Vertex<T> &right_vertex_repr) {
        return Edge<T>{left_vertex_repr, right_vertex_repr};
    }

    void InsertEdge(const Vertex<T> &vertex, const Edge<T> &edge) {
        auto vertex_iterator = adjacency_lists_.find(vertex);
        std::set<Edge<T>> &vertex_edges = vertex_iterator->second;
        vertex_edges.insert(edge);
        adjacency_lists_[vertex] = vertex_edges;
    }

    void DeleteEdge(const Vertex<T> &vertex, const Edge<T> &edge) {
        auto vertex_iterator = adjacency_lists_.find(vertex);
        std::set<Edge<T>> &vertex_edges = vertex_iterator->second;
        vertex_edges.erase(edge);
        adjacency_lists_[vertex] = vertex_edges;
    }

    std::map<Vertex<T>, std::set<Edge<T>>> adjacency_lists_;
    size_t edges_count_;
};

