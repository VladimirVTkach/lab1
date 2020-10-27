#pragma once

#include "crud_controller.h"

class IntCrudController : public CrudController<int> {
public:
    IntCrudController(UndirectedGraph<int> &undirected_graph,
                      const ConsoleView &console_view);
protected:
    int GetVertex(std::string message) override;
};