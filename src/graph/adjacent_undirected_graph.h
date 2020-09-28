#pragma once

#include <map>
#include <set>
#include "undirected_graph.h"

template<typename T>
class AdjacentUndirectedGraph : public UndirectedGraph<T> {
public:
    void AddVertex(const Vertex<T> &vertex) override {
        adjacency_lists_.try_emplace(vertex, std::set<Edge<T>>());
    }

    void AddEdge(const Edge<T> &edge) override {
        const Vertex<T> &left = edge.left;
        const Vertex<T> &right = edge.right;

        if (!adjacency_lists_.contains(left) || !adjacency_lists_.contains(right)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        InsertEdge(left, edge);
        InsertEdge(right, edge);
        ++edges_count_;
    }

    void RemoveVertex(const Vertex<T> &vertex) override {
        adjacency_lists_.erase(vertex);
    }

    void RemoveEdge(const Edge<T> &edge) override {

    }

    bool IsLinked() override {
        return false;
    }

    int GetDistance(const Vertex<T> &src, const Vertex<T> &dst) override {
        return 0;
    }

    size_t GetVerticesCount() override {
        return adjacency_lists_.size();
    }

    size_t GetEdgesCount() override {
        return 0;
    }

    size_t GetAdjacentEdgesCount(Vertex<T> vertex) override {
        return 0;
    }

    const std::map<Vertex<T>, std::set<Edge<T>>> &GetAdjacencyLists() const {
        return adjacency_lists_;
    }


private:
    void InsertEdge(const Vertex<T> &vertex, const Edge<T> &edge) {
        auto vertex_iterator = adjacency_lists_.find(vertex);
        std::set<Edge<T>> &vertex_edges = vertex_iterator->second;
        vertex_edges.insert(edge);
        adjacency_lists_[vertex] = vertex_edges;
    }

    std::map<Vertex<T>, std::set<Edge<T>>> adjacency_lists_;
    size_t edges_count_;
};

