#include "int_crud_controller.h"

void IntCrudController::AddVertex() {
    int vertex = std::stoi(console_view_.GetUserInput("Enter vertex value"));
    undirected_graph_.AddVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void IntCrudController::RemoveVertex() {
    int vertex = std::stoi(console_view_.GetUserInput("Enter vertex value"));
    undirected_graph_.RemoveVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void IntCrudController::AddEdge() {
    int left_vertex = std::stoi(console_view_.GetUserInput("Enter left vertex value"));
    int right_vertex = std::stoi(console_view_.GetUserInput("Enter right vertex value"));
    try {
        undirected_graph_.AddEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void IntCrudController::RemoveEdge() {
    int left_vertex = std::stoi(console_view_.GetUserInput("Enter left vertex value"));
    int right_vertex = std::stoi(console_view_.GetUserInput("Enter right vertex value"));
    try {
        undirected_graph_.RemoveEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void IntCrudController::GetVerticesCount() {
    size_t vertices_count = undirected_graph_.GetVerticesCount();
    console_view_.ShowMessage(std::to_string(vertices_count));
    console_view_.ShowMainMenu();
}

void IntCrudController::GetEdgesCount() {
    size_t edges_count = undirected_graph_.GetEdgesCount();
    console_view_.ShowMessage(std::to_string(edges_count));
    console_view_.ShowMainMenu();
}

void IntCrudController::GetAdjacentEdgesCount() {
    try {
        int vertex = std::stoi(console_view_.GetUserInput("Enter vertex value"));
        size_t adjacent_edges_count = undirected_graph_.GetAdjacentEdgesCount(vertex);
        console_view_.ShowMessage(std::to_string(adjacent_edges_count));
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void IntCrudController::Clear() {
    undirected_graph_.Clear();
    console_view_.ShowMainMenu();
}
