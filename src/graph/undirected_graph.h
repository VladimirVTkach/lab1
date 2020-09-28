#pragma once

template<typename T>
struct Vertex {
    T data;
};

template<typename T>
struct Edge {
    Vertex<T> lhs;
    Vertex<T> rhs;
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
};