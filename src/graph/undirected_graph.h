#pragma once

#include "vertex.h"
#include <cstddef>

template<typename T>
struct Edge {
    Vertex<T> left;
    Vertex<T> right;

    bool operator==(const Edge &rhs) const {
        return left == rhs.left &&
               right == rhs.right;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Edge &rhs) const {
        if (left < rhs.left)
            return true;
        if (rhs.left < left)
            return false;
        return right < rhs.right;
    }

    bool operator>(const Edge &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Edge &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Edge &rhs) const {
        return !(*this < rhs);
    }
};

template<typename T>
class UndirectedGraph {
public:
    virtual void AddVertex(const T &vertex) = 0;

    virtual void AddEdge(const T &left, T &right) = 0;

    virtual void RemoveVertex(const T &vertex) = 0;

    virtual void RemoveEdge(const T &left, T &right) = 0;

    virtual bool IsLinked() = 0;

    virtual int GetDistance(const T &left, const T &right) = 0;

    virtual size_t GetVerticesCount() = 0;

    virtual size_t GetEdgesCount() = 0;

    virtual size_t GetAdjacentEdgesCount(const T &vertex) = 0;

protected:
    Vertex<T> GetVertexRepr(const T &vertex) {
        return Vertex<T>{vertex};
    }

    Edge<T> GetEdgeRepr(const Vertex<T> &left_vertex_repr, const Vertex<T> &right_vertex_repr) {
        return Edge<T>{left_vertex_repr, right_vertex_repr};
    }
};