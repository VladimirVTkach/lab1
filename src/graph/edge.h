#pragma once

#include "vertex.h"

template<typename T>
class Edge {
public:
    Edge() {}

    Edge(const Vertex<T> &left, const Vertex<T> &right) : left(left), right(right) {}

    const Vertex<T> &GetLeft() const {
        return left;
    }

    const Vertex<T> &GetRight() const {
        return right;
    }

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

private:
    Vertex<T> left;
    Vertex<T> right;
};

