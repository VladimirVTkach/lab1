#pragma once

#include "crud_controller.h"

class VectorCrudController : public CrudController<std::vector<int>> {
public:
    VectorCrudController(UndirectedGraph<std::vector<int>> &undirected_graph,
                         const ConsoleView &console_view);

    void AddVertex() override;

    void RemoveVertex() override;

    void AddEdge() override;

    void RemoveEdge() override ;

    void GetVerticesCount() override;

    void GetEdgesCount() override;

    void GetAdjacentEdgesCount() override;

    void Clear() override;
};