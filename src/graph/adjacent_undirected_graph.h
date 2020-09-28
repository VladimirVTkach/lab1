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
        const Vertex<T> &lhs = edge.lhs;
        const Vertex<T> &rhs = edge.rhs;

        auto lhs_adjacent_edges = GetAdjacentEdgesOrEmptySet(lhs);
        auto rhs_adjacent_edges = GetAdjacentEdgesOrEmptySet(lhs);

        lhs_adjacent_edges.insert(edge);
        rhs_adjacent_edges.insert(edge);

        adjacency_lists_.insert_or_assign(lhs, lhs_adjacent_edges);
        adjacency_lists_.insert_or_assign(rhs, rhs_adjacent_edges);

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

    std::set<Edge<Vertex<T>>> GetAdjacentEdgesOrEmptySet(Vertex<T> &vertex) override {
        const auto &found_vertex_it = FindVertexIt(vertex);
        if (found_vertex_it == adjacency_lists_.end()) {
            return std::set<Edge<Vertex<T>>>();
        } else {
            return found_vertex_it->second;
        }
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
    const auto &FindVertexIt(const Vertex<T> &vertex) {
        const auto &found_vertex_it = adjacency_lists_.find(vertex);
        return found_vertex_it;
    }

    std::map<Vertex<T>, std::set<Edge<T>>> adjacency_lists_;
    size_t edges_count_;
};

