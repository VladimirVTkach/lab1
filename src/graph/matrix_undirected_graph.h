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

        std::map<Vertex<T>, Edge<T>> &left_adjacent_edges = adjacency_matrix_[left_vertex_repr];
        left_adjacent_edges[right_vertex_repr] = edge_repr;

        std::map<Vertex<T>, Edge<T>> &right_adjacent_edges = adjacency_matrix_[right_vertex_repr];
        right_adjacent_edges[left_vertex_repr] = edge_repr;

        ++edges_count_;
    }

    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_matrix_.erase(vertex_repr);

        for (const auto &[k, v] : adjacency_matrix_) {
            std::map<Vertex<T>, Edge<T>> &adjacent_edges = adjacency_matrix_[k];
            adjacent_edges.erase(vertex_repr);
        }
    }

    void RemoveEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_matrix_.contains(left_vertex_repr) ||
            !adjacency_matrix_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        std::map<Vertex<T>, Edge<T>> &left_adjacent_edges = adjacency_matrix_[left_vertex_repr];
        left_adjacent_edges.erase(right_vertex_repr);

        std::map<Vertex<T>, Edge<T>> &right_adjacent_edges = adjacency_matrix_[right_vertex_repr];
        left_adjacent_edges.erase(left_vertex_repr);

        --edges_count_;
    }

    bool IsLinked() override {
        for (const auto &[k1, v1] : adjacency_matrix_) {
            for (const auto &[k2, v2]: adjacency_matrix_) {
                if (!adjacency_matrix_[k1].contains(k2)) {
                    return false;
                }
            }
        }
        return true;
    }

    int GetDistance(const T &left, const T &right) override {
        return 0;
    }

    size_t GetVerticesCount() override {
        return adjacency_matrix_.size();
    }

    size_t GetEdgesCount() override {
        return edges_count_;
    }

    size_t GetAdjacentEdgesCount(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        return adjacency_matrix_[vertex_repr].size();
    }

    const std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> &GetAdjacencyMatrix() {
        return adjacency_matrix_;
    }

private:
    std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> adjacency_matrix_;
    size_t edges_count_ = 0;
};