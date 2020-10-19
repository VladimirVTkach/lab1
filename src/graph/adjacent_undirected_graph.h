#pragma once

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include "undirected_graph.h"

template<typename T>
class AdjacentUndirectedGraph : public UndirectedGraph<T> {
public:

    /** Adds new vertex to the graph
     * @param vertex vertex to add
     * */
    void AddVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_lists_.try_emplace(vertex_repr, std::set<Edge<T>>());
    }

    /** Adds new edge to the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    void AddEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_lists_.contains(left_vertex_repr) ||
            !adjacency_lists_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> edge_repr = this->GetEdgeRepr(left_vertex_repr, right_vertex_repr);

        InsertEdge(left_vertex_repr, edge_repr);
        InsertEdge(right_vertex_repr, edge_repr);
        ++edges_count_;
    }

    /** Removes vertex from the graph
     * @param vertex vertex to remove
     * */
    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_lists_.erase(vertex_repr);

        for (auto &[k, v] : adjacency_lists_) {
            std::vector<Edge<T>> to_remove;
            for (const Edge<T> &edge: v) {
                if (edge.GetLeft().GetData() == vertex || edge.GetRight().GetData() == vertex) {
                    to_remove.push_back(edge);
                }
            }

            for (const Edge<T> &edge: to_remove) {
                v.erase(edge);
            }
        }
    }

    /** Removes edge from the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    void RemoveEdge(const T &left, T &right) override {
        const Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        const Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_lists_.contains(left_vertex_repr) ||
            !adjacency_lists_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> edge_repr = this->GetEdgeRepr(left_vertex_repr, right_vertex_repr);

        DeleteEdge(left_vertex_repr, edge_repr);
        DeleteEdge(right_vertex_repr, edge_repr);
        --edges_count_;
    }

    /** Checks whether the graph is linked
     * @return true if graph is linked, otherwise false
     * */
    bool IsLinked() override {
        for (const auto &[k1, v1]: adjacency_lists_) {
            for (const auto &[k2, v2]: adjacency_lists_) {
                if (GetDistance(k1.GetData(), k2.GetData()) == -1) {
                    return false;
                }
            }
        }
        return true;
    }

    /** Clears all data stored in graph */
    void Clear() override {
        adjacency_lists_.clear();
    }

    /** Finds distance between two vertices
     * @param left source vertex
     * @param right destination vertex
     * @return distance between vertices
     * */
    int GetDistance(const T &left, const T &right) override {
        const Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        const Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_lists_.contains(left_vertex_repr) ||
            !adjacency_lists_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        std::map<Vertex<T>, Vertex<T>> parents = Bfs(left_vertex_repr, right_vertex_repr);
        auto right_vertex_repr_it = parents.find(right_vertex_repr);

        if (left_vertex_repr == right_vertex_repr) {
            return 0;
        }

        if (right_vertex_repr_it == parents.end()) {
            return -1;
        } else {
            Vertex<T> right_vertex_parent_repr = right_vertex_repr_it->second;
            size_t path_size = 1;
            while (right_vertex_parent_repr != left_vertex_repr) {
                ++path_size;
                right_vertex_parent_repr = parents[right_vertex_parent_repr];
            }
            return path_size;
        }
    }

    /** @return total vertices count */
    size_t GetVerticesCount() override {
        return adjacency_lists_.size();
    }

    /** @return total edges count */
    size_t GetEdgesCount() override {
        return edges_count_;
    }

    /** Finds count of adjacent to vertex edges
     * @param vertex target vertex
     * @return count of edges adjacent to target vertex
     * */
    size_t GetAdjacentEdgesCount(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        auto vertex_iterator = adjacency_lists_.find(vertex_repr);
        if (vertex_iterator == adjacency_lists_.end()) {
            throw std::runtime_error("vertex doesn't exist");
        } else {
            return (vertex_iterator->second).size();
        }
    }

    /** @return adjacency list */
    const std::map<Vertex<T>, std::set<Edge<T>>> &GetAdjacencyLists() const {
        return adjacency_lists_;
    }

    /** @return string representation of graph*/
    std::string ToString() const override {
        std::stringstream ss;
        for (const auto &[vertex, edges]: adjacency_lists_) {
            ss << vertex << ": ";
            for (auto it = edges.begin(); it != edges.end(); it++) {
                ss << *it << ", ";
            }
            ss << "\n";
        }

        std::string graph_representation = ss.str();
        if (graph_representation.empty()) {
            return "Graph is empty";
        }
        return ss.str();
    }

private:
    std::map<Vertex<T>, Vertex<T>> Bfs(const Vertex<T> &left_vertex_repr, const Vertex<T> &right_vertex_repr) {
        std::map<Vertex<T>, Vertex<T>> parents;
        std::vector<Vertex<T>> frontier = {left_vertex_repr};
        while (!frontier.empty()) {
            std::vector<Vertex<T>> next;
            for (const auto &vertex: frontier) {
                for (const auto &vertex_adjacent_edge: adjacency_lists_[vertex]) {
                    Vertex<T> target_vertex;
                    if (vertex_adjacent_edge.GetLeft() == vertex) {
                        target_vertex = vertex_adjacent_edge.GetRight();
                    } else {
                        target_vertex = vertex_adjacent_edge.GetLeft();
                    }
                    if (!parents.contains(target_vertex) && target_vertex != left_vertex_repr) {
                        parents[target_vertex] = vertex;
                        next.push_back(target_vertex);
                    }
                }
            }
            frontier = next;
        }
        return parents;
    }

    void InsertEdge(const Vertex<T> &vertex, const Edge<T> &edge) {
        auto vertex_iterator = adjacency_lists_.find(vertex);
        std::set<Edge<T>> &vertex_edges = vertex_iterator->second;
        vertex_edges.insert(edge);
        adjacency_lists_[vertex] = vertex_edges;
    }

    void DeleteEdge(const Vertex<T> &vertex, const Edge<T> &edge) {
        auto vertex_iterator = adjacency_lists_.find(vertex);
        std::set<Edge<T>> &vertex_edges = vertex_iterator->second;
        vertex_edges.erase(edge);
        adjacency_lists_[vertex] = vertex_edges;
    }

    std::map<Vertex<T>, std::set<Edge<T>>> adjacency_lists_;
    size_t edges_count_ = 0;
};

