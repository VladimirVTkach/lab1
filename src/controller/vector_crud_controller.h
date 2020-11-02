#pragma once

#include "crud_controller.h"

class VectorCrudController : public CrudController<std::vector<int>> {
public:
    VectorCrudController(UndirectedGraph<std::vector<int>> &undirected_graph,
                         const ConsoleView &console_view);

protected:
    std::vector<int> GetVertex(std::string message) override;
};