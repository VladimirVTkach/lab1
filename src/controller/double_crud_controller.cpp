#include "double_crud_controller.h"

DoubleCrudController::DoubleCrudController(UndirectedGraph<double> &undirected_graph, const ConsoleView &console_view) :
        CrudController<double>(undirected_graph, console_view) {}

void DoubleCrudController::AddVertex() {
    double vertex = std::stod(console_view_.GetUserInput("Enter vertex value"));
    undirected_graph_.AddVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void DoubleCrudController::RemoveVertex() {
    double vertex = std::stod(console_view_.GetUserInput("Enter vertex value"));
    undirected_graph_.RemoveVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void DoubleCrudController::AddEdge() {
    double left_vertex = std::stod(console_view_.GetUserInput("Enter left vertex value"));
    double right_vertex = std::stod(console_view_.GetUserInput("Enter right vertex value"));
    try {
        undirected_graph_.AddEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void DoubleCrudController::RemoveEdge() {
    double left_vertex = std::stod(console_view_.GetUserInput("Enter left vertex value"));
    double right_vertex = std::stod(console_view_.GetUserInput("Enter right vertex value"));
    try {
        undirected_graph_.RemoveEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void DoubleCrudController::GetVerticesCount() {
    size_t vertices_count = undirected_graph_.GetVerticesCount();
    console_view_.ShowMessage(std::to_string(vertices_count));
    console_view_.ShowMainMenu();
}

void DoubleCrudController::GetEdgesCount() {
    size_t edges_count = undirected_graph_.GetEdgesCount();
    console_view_.ShowMessage(std::to_string(edges_count));
    console_view_.ShowMainMenu();
}

void DoubleCrudController::GetAdjacentEdgesCount() {
    try {
        double vertex = std::stod(console_view_.GetUserInput("Enter vertex value"));
        size_t adjacent_edges_count = undirected_graph_.GetAdjacentEdgesCount(vertex);
        console_view_.ShowMessage(std::to_string(adjacent_edges_count));
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void DoubleCrudController::Clear() {
    undirected_graph_.Clear();
    console_view_.ShowMainMenu();
}
