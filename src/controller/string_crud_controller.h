#pragma once

#include "crud_controller.h"

class StringCrudController : public CrudController<std::string> {
public:
    StringCrudController(UndirectedGraph<std::string> &undirected_graph,
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