#pragma once

#include "vertex.h"
#include "edge.h"
#include <cstddef>
#include <ostream>

/** Abstract class representing undirected graph */
template<typename T>
class UndirectedGraph {
public:
    virtual void AddVertex(const T &vertex) = 0;

    virtual void AddEdge(const T &left, T &right) = 0;

    virtual void RemoveVertex(const T &vertex) = 0;

    virtual void RemoveEdge(const T &left, T &right) = 0;

    virtual bool IsLinked() = 0;

    virtual void Clear() = 0;

    virtual int GetDistance(const T &left, const T &right) = 0;

    virtual size_t GetVerticesCount() = 0;

    virtual size_t GetEdgesCount() = 0;

    virtual size_t GetAdjacentEdgesCount(const T &vertex) = 0;

    virtual std::string ToString() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const UndirectedGraph &graph) {
        os << graph.ToString();
        return os;
    }

protected:
    /** Returns vertex representation
     * @param vertex data to be stored in vertex
     * @return Vertex class instance containing wrapped data
     * */
    Vertex<T> GetVertexRepr(const T &vertex) {
        return Vertex<T>(vertex);
    }

    /** Returns edge representation
    * @param left_vertex_repr Vertex instance to be stored as left side vertex of the edge
    * @param right_vertex_repr Vertex instance to be stored as right side vertex of the edge
    * @return Edge class instance containing wrapped vertices
    * */
    Edge<T> GetEdgeRepr(const Vertex<T> &left_vertex_repr, const Vertex<T> &right_vertex_repr) {
        return Edge<T>(left_vertex_repr, right_vertex_repr);
    }
};