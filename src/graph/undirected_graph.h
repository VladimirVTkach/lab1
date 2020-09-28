#pragma once

#include <cstddef>

template<typename T>
struct Vertex {
    T data;

    bool operator==(const Vertex &rhs) const {
        return data == rhs.data;
    }

    bool operator!=(const Vertex &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Vertex &rhs) const {
        return data < rhs.data;
    }

    bool operator>(const Vertex &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Vertex &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Vertex &rhs) const {
        return !(*this < rhs);
    }
};

template<typename T>
struct Edge {
    Vertex<T> lhs;
    Vertex<T> rhs;

    bool operator==(const Edge &rhs) const {
        return lhs == rhs.lhs &&
               rhs == rhs.rhs;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Edge &rhs) const {
        if (lhs < rhs.lhs)
            return true;
        if (rhs.lhs < lhs)
            return false;
        return rhs < rhs.rhs;
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
    virtual void AddVertex(const Vertex<T> &vertex) = 0;

    virtual void AddEdge(const Edge<T> &edge) = 0;

    virtual void RemoveVertex(const Vertex<T> &vertex) = 0;

    virtual void RemoveEdge(const Edge<T> &edge) = 0;

    virtual bool IsLinked() = 0;

    virtual int GetDistance(const Vertex<T> &src, const Vertex<T> &dst) = 0;

    virtual size_t GetVerticesCount() = 0;

    virtual size_t GetEdgesCount() = 0;

    virtual size_t GetAdjacentEdgesCount(Vertex<T> vertex) = 0;
};