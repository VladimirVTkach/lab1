#include "string_crud_controller.h"

StringCrudController::StringCrudController(UndirectedGraph<std::string> &undirected_graph, const ConsoleView &console_view) :
        CrudController<std::string>(undirected_graph, console_view) {}

std::string StringCrudController::GetVertex(std::string message) {
    return console_view_.GetUserInput(message);
}
