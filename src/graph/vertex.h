#pragma once

#include <ostream>

/** Class representing graph vertex */
template<typename T>
class Vertex {
public:
    Vertex() {}

    /** Constructs Vertex instance with specified field's values
     * @param data data to be stored in vertex
     * */
    Vertex(T data) : data(data) {}

    /** @return data stored in vertex*/
    T GetData() const {
        return data;
    }

    /** Compares for equality this instance to other Vertex instance.
    * If instances are equal returns true, otherwise false.
    * @param rhs instance of Vertex to compare this instance to
    * @return comparison result
    * */
    bool operator==(const Vertex &rhs) const {
        return data == rhs.data;
    }

    /** Compares for inequality this instance to other Vertex instance.
     * If instances are not equal returns true, otherwise false.
     * @param rhs instance of Vertex to compare this instance to
     * @return comparison result
     * */
    bool operator!=(const Vertex &rhs) const {
        return !(rhs == *this);
    }

    /** Compares the relative order of this instance to other Vertex instance.
     * If this instances is less then other instance returns true, otherwise false.
     * @param rhs instance of Vertex to compare this instance to
     * @return comparison result
     * */
    bool operator<(const Vertex &rhs) const {
        return data < rhs.data;
    }

    /** Compares the relative order of this instance to other Vertex instance.
     * If this instances is greater then other instance returns true, otherwise false.
     * @param rhs instance of Vertex to compare this instance to
     * @return comparison result
     * */
    bool operator>(const Vertex &rhs) const {
        return rhs < *this;
    }

    /** Compares the relative order of this instance to other Vertex instance.
     * If this instances is less than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Vertex to compare this instance to
     * @return comparison result
     * */
    bool operator<=(const Vertex &rhs) const {
        return !(rhs < *this);
    }

    /** Compares the relative order of this instance to other Vertex instance.
     * If this instances is greater than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Vertex to compare this instance to
     * @return comparison result
     * */
    bool operator>=(const Vertex &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex) {
        os << "{" << vertex.data << "}";
        return os;
    }

private:
    T data;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for(T item: v) {
        os << item << " ";
    }
    return os;
}
