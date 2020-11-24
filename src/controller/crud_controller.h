#pragma once

#include "../graph/undirected_graph.h"
#include "../view/console_view.h"

template<typename T>
class CrudController {
public:
    CrudController(UndirectedGraph<T> &undirected_graph,
                   const ConsoleView &console_view) : undirected_graph_(undirected_graph),
                                                      console_view_(console_view) {}

    void AddVertex() {
        T vertex = GetVertex("Enter vertex value");
        undirected_graph_.AddVertex(vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    }

    void RemoveVertex() {
        T vertex = GetVertex("Enter vertex value");
        undirected_graph_.RemoveVertex(vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    }

    void AddEdge() {
        T left_vertex = GetVertex("Enter left vertex value");
        T right_vertex = GetVertex("Enter right vertex value");
        try {
            undirected_graph_.AddEdge(left_vertex, right_vertex);
            console_view_.ShowGraph(undirected_graph_);
            console_view_.ShowMainMenu();
        } catch (std::runtime_error &e) {
            console_view_.ShowMessage(e.what());
            console_view_.ShowMainMenu();
        }
    }

    void RemoveEdge() {
        T left_vertex = GetVertex("Enter left vertex value");
        T right_vertex = GetVertex("Enter right vertex value");
        try {
            undirected_graph_.RemoveEdge(left_vertex, right_vertex);
            console_view_.ShowGraph(undirected_graph_);
            console_view_.ShowMainMenu();
        } catch (std::runtime_error &e) {
            console_view_.ShowMessage(e.what());
            console_view_.ShowMainMenu();
        }
    }

    void GetVerticesCount() {
        size_t vertices_count = undirected_graph_.GetVerticesCount();
        console_view_.ShowMessage(std::to_string(vertices_count));
        console_view_.ShowMainMenu();
    }

    void GetEdgesCount() {
        size_t edges_count = undirected_graph_.GetEdgesCount();
        console_view_.ShowMessage(std::to_string(edges_count));
        console_view_.ShowMainMenu();
    }

    void GetAdjacentEdgesCount() {
        try {
            T vertex = GetVertex("Enter vertex value");
            size_t adjacent_edges_count = undirected_graph_.GetAdjacentEdgesCount(vertex);
            console_view_.ShowMessage(std::to_string(adjacent_edges_count));
            console_view_.ShowMainMenu();
        } catch (std::runtime_error &e) {
            console_view_.ShowMessage(e.what());
            console_view_.ShowMainMenu();
        }
    }

    void Clear() {
        undirected_graph_.Clear();
        console_view_.ShowMainMenu();
    };

    void FindDistance() {
        T left_vertex = GetVertex("Enter left vertex value");
        T right_vertex = GetVertex("Enter right vertex value");
        try {
            int distance = undirected_graph_.GetDistance(left_vertex, right_vertex);
            console_view_.ShowMessage(std::to_string(distance));
            console_view_.ShowMainMenu();
        } catch (std::runtime_error &e) {
            console_view_.ShowMessage(e.what());
            console_view_.ShowMainMenu();
        }
    }

    void IsLinked() {
        bool is_linked = undirected_graph_.IsLinked();

        if(is_linked) {
            console_view_.ShowMessage("graph is linked");
        } else {
            console_view_.ShowMessage("graph is not linked");
        }

        console_view_.ShowMainMenu();
    }

protected:
    UndirectedGraph<T> &undirected_graph_;
    ConsoleView console_view_;

    virtual T GetVertex(std::string message) = 0;
};
