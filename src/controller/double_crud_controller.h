#pragma once

#include "crud_controller.h"

class DoubleCrudController : public CrudController<double> {
public:
    DoubleCrudController(UndirectedGraph<double> &undirected_graph,
                         const ConsoleView &console_view);

protected:
    double GetVertex(std::string message) override;
};