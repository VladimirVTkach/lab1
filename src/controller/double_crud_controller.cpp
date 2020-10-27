#include "double_crud_controller.h"

DoubleCrudController::DoubleCrudController(UndirectedGraph<double> &undirected_graph, const ConsoleView &console_view) :
        CrudController<double>(undirected_graph, console_view) {}

double DoubleCrudController::GetVertex(std::string message) {
    return std::stod(console_view_.GetUserInput(message));
}
