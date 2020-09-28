#pragma once

#include <map>
#include <set>
#include "undirected_graph.h"

template<typename T>
class AdjacentUndirectedGraph : public UndirectedGraph<T> {
public:
    void AddVertex(const Vertex<T> &vertex) override {
        const auto &found_key_it = adjacency_lists_.find(vertex);
        adjacency_lists_.erase(found_key_it);
    }

    void AddEdge(const Edge<T> &edge) override {

    }

    void RemoveVertex(const Vertex<T> &vertex) override {

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

private:
    std::map<Vertex<T>, std::vector<Edge<T>>> adjacency_lists_;
};

