#pragma once

#include <map>
#include "undirected_graph.h"

template<typename T>
class MatrixUndirectedGraph : public UndirectedGraph<T> {
public:
    void AddVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_matrix_.try_emplace(vertex_repr, std::map<Vertex<T>, Edge<T>>());
    }

    void AddEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_matrix_.contains(left_vertex_repr) ||
            !adjacency_matrix_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> edge_repr = this->GetEdgeRepr(left_vertex_repr, right_vertex_repr);
        std::map<Vertex<T>, Edge<T>> &adjacent_edges = adjacency_matrix_[left_vertex_repr];
        adjacent_edges[right_vertex_repr] = edge_repr;
    }

    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_matrix_.erase(vertex_repr);
    }

    void RemoveEdge(const T &left, T &right) override {

    }

    bool IsLinked() override {
        return false;
    }

    int GetDistance(const T &left, const T &right) override {
        return 0;
    }

    size_t GetVerticesCount() override {
        return adjacency_matrix_.size();
    }

    size_t GetEdgesCount() override {
        return 0;
    }

    size_t GetAdjacentEdgesCount(const T &vertex) override {
        return adjacency_matrix_[vertex].size();
    }

private:
    std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> adjacency_matrix_;
};