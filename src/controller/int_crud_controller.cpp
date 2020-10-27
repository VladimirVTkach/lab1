#include "int_crud_controller.h"

IntCrudController::IntCrudController(UndirectedGraph<int> &undirected_graph, const ConsoleView &console_view) :
        CrudController<int>(undirected_graph, console_view) {}

int IntCrudController::GetVertex(std::string message) {
    return std::stoi(console_view_.GetUserInput(message));
}
