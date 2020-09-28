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