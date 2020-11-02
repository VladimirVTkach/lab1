#include "vector_crud_controller.h"
#include "sstream"
#include <vector>

VectorCrudController::VectorCrudController(UndirectedGraph<std::vector<int>> &undirected_graph,
                                           const ConsoleView &console_view) :
        CrudController<std::vector<int>>(undirected_graph, console_view) {}

std::vector<int> VectorCrudController::GetVertex(std::string message) {
    std::string input_line = console_view_.GetUserInput(message);
    std::stringstream ss(input_line);
    std::vector<int> result_vector;
    std::string item;
    while(std::getline(ss, item, ',')) {
        int next_val = std::stoi(item);
        result_vector.push_back(next_val);
    }
    return result_vector;
}


