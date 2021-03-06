#pragma once

#include <map>
#include "undirected_graph.h"

template<typename T>
class MappingUndirectedGraph : public UndirectedGraph<T> {
public:

    /** Adds new vertex to the graph
     * @param vertex vertex to add
     * */
    void AddVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_matrix_.try_emplace(vertex_repr, std::map<Vertex<T>, Edge<T>>());
    }

    /** Adds new edge to the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    void AddEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_matrix_.contains(left_vertex_repr) ||
            !adjacency_matrix_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        Edge<T> edge_repr = this->GetEdgeRepr(left_vertex_repr, right_vertex_repr);

        std::map<Vertex<T>, Edge<T>> &left_adjacent_edges = adjacency_matrix_[left_vertex_repr];
        left_adjacent_edges[right_vertex_repr] = edge_repr;

        std::map<Vertex<T>, Edge<T>> &right_adjacent_edges = adjacency_matrix_[right_vertex_repr];
        right_adjacent_edges[left_vertex_repr] = edge_repr;

        ++edges_count_;
    }

    /** Removes vertex from the graph
     * @param vertex vertex to remove
     * */
    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);
        adjacency_matrix_.erase(vertex_repr);

        for (const auto &[k, v] : adjacency_matrix_) {
            std::map<Vertex<T>, Edge<T>> &adjacent_edges = adjacency_matrix_[k];
            adjacent_edges.erase(vertex_repr);
        }
    }

    /** Removes edge from the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    void RemoveEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_matrix_.contains(left_vertex_repr) ||
            !adjacency_matrix_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        std::map<Vertex<T>, Edge<T>> &left_adjacent_edges = adjacency_matrix_[left_vertex_repr];
        left_adjacent_edges.erase(right_vertex_repr);

        std::map<Vertex<T>, Edge<T>> &right_adjacent_edges = adjacency_matrix_[right_vertex_repr];
        right_adjacent_edges.erase(left_vertex_repr);

        --edges_count_;
    }

    /** Checks whether the graph is linked
     * @return true if graph is linked, otherwise false
     * */
    bool IsLinked() override {
        for (const auto &[k1, v1] : adjacency_matrix_) {
            for (const auto &[k2, v2]: adjacency_matrix_) {
                if (GetDistance(k1.GetData(), k2.GetData()) == -1) {
                    return false;
                }
            }
        }
        return true;
    }

    /** Clears all data stored in graph */
    void Clear() override {
        adjacency_matrix_.clear();
    }

    /** Finds distance between two vertices
     * @param left source vertex
     * @param right destination vertex
     * @return distance between vertices
     * */
    int GetDistance(const T &left, const T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!adjacency_matrix_.contains(left_vertex_repr) ||
            !adjacency_matrix_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        if (left_vertex_repr == right_vertex_repr) {
            return 0;
        }

        std::set<Vertex<T>> visited = {left_vertex_repr};
        std::vector<Vertex<T>> frontier = {left_vertex_repr};
        size_t distance = 1;
        while (!frontier.empty()) {
            std::vector<Vertex<T>> next;
            for (const Vertex<T> &vertex_repr: frontier) {
                const std::map<Vertex<T>, Edge<T>> &adjacent_edges = adjacency_matrix_[vertex_repr];
                for (const auto &[k, v] : adjacent_edges) {
                    if (k == right_vertex_repr) {
                        return distance;
                    } else if (!visited.contains(k)) {
                        visited.insert(k);
                        next.push_back(k);
                    }
                }
            }
            distance++;
            frontier = next;
        }
        return -1;
    }

    /** @return total vertices count */
    size_t GetVerticesCount() override {
        return adjacency_matrix_.size();
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
        return adjacency_matrix_[vertex_repr].size();
    }

    /** @return adjacency list */
    const std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> &GetAdjacencyMatrix() {
        return adjacency_matrix_;
    }

    /** @return string representation of graph */
    std::string ToString() const override {
        std::stringstream ss;
        for (const auto &[vertex, edges]: adjacency_matrix_) {
            ss << vertex << ": ";
            for (auto it = edges.begin(); it != edges.end(); it++) {
                auto entry = *it;
                ss << entry.second << ", ";
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
    std::map<Vertex<T>, std::map<Vertex<T>, Edge<T>>> adjacency_matrix_;
    size_t edges_count_ = 0;
};