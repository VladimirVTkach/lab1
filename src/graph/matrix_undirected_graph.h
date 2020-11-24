#pragma once

#include "undirected_graph.h"
#include <vector>
#include <map>

template<typename T>
class MatrixUndirectedGraph : public UndirectedGraph<T> {
public:

    /** Adds new vertex to the graph
     * @param vertex vertex to add
     * */
    void AddVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);

        size_t vertices_count = vertex_to_index_mapping_.size();
        vertex_to_index_mapping_.try_emplace(vertex_repr, vertices_count++);
        for (auto &row: matrix_) {
            row.push_back(nullptr);
        }

        matrix_.push_back(std::vector<Edge<T> *>(vertices_count, nullptr));
    }

    /** Adds new edge to the graph
    * @param left left side vertex of the edge
    * @param right right side vertex of the edge
    * */
    void AddEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!vertex_to_index_mapping_.contains(left_vertex_repr) ||
            !vertex_to_index_mapping_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        int left_vertex_index = vertex_to_index_mapping_[left_vertex_repr];
        int right_vertex_index = vertex_to_index_mapping_[right_vertex_repr];

        auto *edge = new Edge<T>(left_vertex_repr, right_vertex_repr);

        matrix_[left_vertex_index][right_vertex_index] = edge;
        matrix_[right_vertex_index][left_vertex_index] = edge;

        edges_count_++;
    }

    /** Removes vertex from the graph
     * @param vertex vertex to remove
     * */
    void RemoveVertex(const T &vertex) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(vertex);

        if (!vertex_to_index_mapping_.contains(vertex_repr)) {
            throw std::runtime_error("vertex doesn't exist");
        }

        int vertex_index = vertex_to_index_mapping_[vertex_repr];
        matrix_.erase(matrix_.begin() + vertex_index);

        for (auto &row: matrix_) {
            row.erase(row.begin() + vertex_index);
        }

        vertex_to_index_mapping_.erase(vertex_repr);

        std::map<Vertex<T>, int> new_vertex_to_index_mapping_;
        for (auto &[key, value]: vertex_to_index_mapping_) {
            if (value > vertex_index) {
                new_vertex_to_index_mapping_.try_emplace(key, --value);
            } else {
                new_vertex_to_index_mapping_.try_emplace(key, value);
            }
        }

        vertex_to_index_mapping_ = new_vertex_to_index_mapping_;
    }

    /** Removes edge from the graph
     * @param left left side vertex of the edge
     * @param right right side vertex of the edge
     * */
    void RemoveEdge(const T &left, T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!vertex_to_index_mapping_.contains(left_vertex_repr) ||
            !vertex_to_index_mapping_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        int left_vertex_index = vertex_to_index_mapping_[left_vertex_repr];
        int right_vertex_index = vertex_to_index_mapping_[right_vertex_repr];

        matrix_[left_vertex_index][right_vertex_index] = nullptr;
        matrix_[right_vertex_index][left_vertex_index] = nullptr;

        edges_count_--;
    }

    /** Checks whether the graph is linked
     * @return true if graph is linked, otherwise false
     * */
    bool IsLinked() override {
        for (auto &[k1, v1]: vertex_to_index_mapping_) {
            for (auto &[k2, v2]: vertex_to_index_mapping_) {
                if (k1 != k2) {
                    if (GetDistance(k1.GetData(), k2.GetData()) == -1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    /** Clears all data stored in graph */
    void Clear() override {
        vertex_to_index_mapping_.clear();
        matrix_.clear();
    }

    /** Finds distance between two vertices
     * @param left source vertex
     * @param right destination vertex
     * @return distance between vertices
     * */
    int GetDistance(const T &left, const T &right) override {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(left);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(right);

        if (!vertex_to_index_mapping_.contains(left_vertex_repr) ||
            !vertex_to_index_mapping_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        int left_vertex_index = vertex_to_index_mapping_[left_vertex_repr];
        int right_vertex_index = vertex_to_index_mapping_[right_vertex_repr];

        int distance = 0;
        if (matrix_[left_vertex_index][right_vertex_index] != nullptr) {
            return distance;
        } else {
            int min_index = std::min(left_vertex_index, right_vertex_index);
            int max_index = std::max(left_vertex_index, right_vertex_index);

            Vertex<T> min_vertex;
            Vertex<T> max_vertex;
            if (min_index == left_vertex_index) {
                min_vertex = left_vertex_repr;
                max_vertex = right_vertex_repr;
            } else {
                min_vertex = right_vertex_repr;
                max_vertex = left_vertex_repr;
            }

            auto adjacent_edges = GetAdjacentEdges(min_vertex);
            for (int i = min_index + 1; i <= max_index; i++) {
                auto row = matrix_[i];

                std::vector<Edge<T> *> next_edges;
                for (auto edge: row) {
                    if (edge == nullptr) {
                        continue;
                    }

                    bool edge_found = false;
                    for (auto adjacent_edge: adjacent_edges) {
                        if (*edge == *adjacent_edge) {
                            edge_found = true;
                            if (edge->GetRight() == max_vertex) {
                                return distance;
                            }
                        }
                    }

                    if (!edge_found) {
                        next_edges.push_back(edge);
                    }
                }
                distance++;
                adjacent_edges = next_edges;
            }
        }
        return -1;
    }

    /** @return total vertices count */
    size_t GetVerticesCount() override {
        return vertex_to_index_mapping_.size();
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

        if (!vertex_to_index_mapping_.contains(vertex_repr)) {
            throw std::runtime_error("vertex doesn't exist");
        }

        return GetAdjacentEdges(vertex_repr).size();
    }

    /** @return string representation of graph */
    std::string ToString() const override {
        std::stringstream ss;
        for (auto row: matrix_) {
            for (auto edge: row) {
                if (edge == nullptr) {
                    ss << "{empty}" << ", ";
                } else {
                    ss << *edge << ", ";
                }
            }
            ss << "\n";
        }
        return ss.str();
    }

private:
    std::vector<std::vector<Edge<T> *>> matrix_;
    std::map<Vertex<T>, int> vertex_to_index_mapping_;
    size_t edges_count_ = 0;

    std::vector<Edge<T> *> GetAdjacentEdges(Vertex<T> &vertex_repr) {
        int vertex_index = vertex_to_index_mapping_[vertex_repr];

        auto &edges = matrix_[vertex_index];

        std::vector<Edge<T> *> adjacent_edges;

        for (auto edge: edges) {
            if (edge != nullptr) {
                adjacent_edges.push_back(edge);
            }
        }

        return adjacent_edges;
    }
};
