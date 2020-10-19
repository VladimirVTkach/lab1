#pragma once

#include <ostream>
#include "vertex.h"

/** Class representing graph edge */
template<typename T>
class Edge {
public:
    Edge() {}

    /** Constructs Edge instance with specified field's values
     * @param left vertex on the left side of the edge
     * @param right vertex on the right side of the edge
     * */
    Edge(const Vertex<T> &left, const Vertex<T> &right) : left(left), right(right) {}

    /** @return left side vertex of the edge*/
    const Vertex<T> &GetLeft() const {
        return left;
    }

    /** @return right side vertex of the edge*/
    const Vertex<T> &GetRight() const {
        return right;
    }

    /** Compares for equality this instance to other Edge instance.
   * If instances are equal returns true, otherwise false.
   * @param rhs instance of Edge to compare this instance to
   * @return comparison result
   * */
    bool operator==(const Edge &rhs) const {
        return left == rhs.left &&
               right == rhs.right;
    }

    /** Compares for inequality this instance to other Edge instance.
    * If instances are not equal returns true, otherwise false.
    * @param rhs instance of Edge to compare this instance to
    * @return comparison result
    * */
    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    /** Compares the relative order of this instance to other Edge instance.
     * If this instances is less then other instance returns true, otherwise false.
     * @param rhs instance of Edge to compare this instance to
     * @return comparison result
     * */
    bool operator<(const Edge &rhs) const {
        if (left < rhs.left)
            return true;
        if (rhs.left < left)
            return false;
        return right < rhs.right;
    }

    /** Compares the relative order of this instance to other Edge instance.
     * If this instances is greater then other instance returns true, otherwise false.
     * @param rhs instance of Edge to compare this instance to
     * @return comparison result
     * */
    bool operator>(const Edge &rhs) const {
        return rhs < *this;
    }

    /** Compares the relative order of this instance to other Edge instance.
    * If this instances is less than or equals to other instance returns true, otherwise false.
    * @param rhs instance of Edge to compare this instance to
    * @return comparison result
    * */
    bool operator<=(const Edge &rhs) const {
        return !(rhs < *this);
    }

    /** Compares the relative order of this instance to other Edge instance.
     * If this instances is greater than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Edge to compare this instance to
     * @return comparison result
     * */
    bool operator>=(const Edge &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
        os << "{" << edge.left << " - " << edge.right << "}";
        return os;
    }

private:
    Vertex<T> left;
    Vertex<T> right;
};

