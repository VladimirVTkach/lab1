#include "string_crud_controller.h"

StringCrudController::StringCrudController(UndirectedGraph<std::string> &undirected_graph, const ConsoleView &console_view) :
        CrudController<std::string>(undirected_graph, console_view) {}

void StringCrudController::AddVertex() {
    std::string vertex = console_view_.GetUserInput("Enter vertex value");
    undirected_graph_.AddVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void StringCrudController::RemoveVertex() {
    std::string vertex = console_view_.GetUserInput("Enter vertex value");
    undirected_graph_.RemoveVertex(vertex);
    console_view_.ShowGraph(undirected_graph_);
    console_view_.ShowMainMenu();
}

void StringCrudController::AddEdge() {
    std::string left_vertex = console_view_.GetUserInput("Enter left vertex value");
    std::string right_vertex = console_view_.GetUserInput("Enter right vertex value");
    try {
        undirected_graph_.AddEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void StringCrudController::RemoveEdge() {
    std::string left_vertex = console_view_.GetUserInput("Enter left vertex value");
    std::string right_vertex = console_view_.GetUserInput("Enter right vertex value");
    try {
        undirected_graph_.RemoveEdge(left_vertex, right_vertex);
        console_view_.ShowGraph(undirected_graph_);
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void StringCrudController::GetVerticesCount() {
    size_t vertices_count = undirected_graph_.GetVerticesCount();
    console_view_.ShowMessage(std::to_string(vertices_count));
    console_view_.ShowMainMenu();
}

void StringCrudController::GetEdgesCount() {
    size_t edges_count = undirected_graph_.GetEdgesCount();
    console_view_.ShowMessage(std::to_string(edges_count));
    console_view_.ShowMainMenu();
}

void StringCrudController::GetAdjacentEdgesCount() {
    try {
        std::string vertex = console_view_.GetUserInput("Enter vertex value");
        size_t adjacent_edges_count = undirected_graph_.GetAdjacentEdgesCount(vertex);
        console_view_.ShowMessage(std::to_string(adjacent_edges_count));
        console_view_.ShowMainMenu();
    } catch (std::runtime_error &e) {
        console_view_.ShowMessage(e.what());
        console_view_.ShowMainMenu();
    }
}

void StringCrudController::Clear() {
    undirected_graph_.Clear();
    console_view_.ShowMainMenu();
}
