#pragma once

#include <map>
#include "undirected_graph.h"

template<typename T>
class MatrixUndirectedGraph : public UndirectedGraph<T> {
public:
    void AddVertex(const T &vertex) override {

    }

    void AddEdge(const T &left, T &right) override {

    }

    void RemoveVertex(const T &vertex) override {

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
        return 0;
    }

    size_t GetEdgesCount() override {
        return 0;
    }

    size_t GetAdjacentEdgesCount(const T &vertex) override {
        return 0;
    }

private:
    std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> adjacency_matrix_;
};