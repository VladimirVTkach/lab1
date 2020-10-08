#pragma once

#include "vertex.h"
#include "edge.h"
#include <cstddef>

/** Abstract class representing undirected graph */
template<typename T>
class UndirectedGraph {
public:
    /** Adds new vertex to the graph
     * @param vertex vertex to add
     * */
    virtual void AddVertex(const T &vertex) = 0;

    /** Adds new edge to the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    virtual void AddEdge(const T &left, T &right) = 0;

    /** Removes vertex from the graph
     * @param vertex vertex to remove
     * */
    virtual void RemoveVertex(const T &vertex) = 0;

    /** Removes edge from the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    virtual void RemoveEdge(const T &left, T &right) = 0;

    /** Checks whether the graph is linked
     * @return true if graph is linked, otherwise false
     * */
    virtual bool IsLinked() = 0;

    /** Finds distance between two vertices
     * @param left source vertex
     * @param right destination vertex
     * @return distance between vertices
     * */
    virtual int GetDistance(const T &left, const T &right) = 0;

    /** @return total vertices count */
    virtual size_t GetVerticesCount() = 0;

    /** @return total edges count */
    virtual size_t GetEdgesCount() = 0;

    /** Finds count of adjacent to vertex edges
     * @param vertex target vertex
     * @return count of edges adjacent to target vertex
     * */
    virtual size_t GetAdjacentEdgesCount(const T &vertex) = 0;

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