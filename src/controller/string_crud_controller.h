#pragma once

#include "crud_controller.h"

class StringCrudController : public CrudController<std::string> {
public:
    StringCrudController(UndirectedGraph<std::string> &undirected_graph,
                         const ConsoleView &console_view);

protected:
    std::string GetVertex(std::string message) override;
};