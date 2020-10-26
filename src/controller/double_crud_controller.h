#pragma once

#include "crud_controller.h"

class DoubleCrudController : public CrudController<double> {
public:
    DoubleCrudController(UndirectedGraph<double> &undirected_graph,
                      const ConsoleView &console_view);

    void AddVertex() override;

    void RemoveVertex() override;

    void AddEdge() override;

    void RemoveEdge() override;

    void GetVerticesCount() override;

    void GetEdgesCount() override;

    void GetAdjacentEdgesCount() override;

    void Clear() override;
};