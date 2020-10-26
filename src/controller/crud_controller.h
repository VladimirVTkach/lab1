#pragma once

#include "../graph/undirected_graph.h"
#include "../view/console_view.h"

template<typename T>
class CrudController {
public:
    CrudController(UndirectedGraph<T> &undirected_graph,
                   const ConsoleView &console_view) : undirected_graph_(undirected_graph),
                                                      console_view_(console_view) {}

    virtual void AddVertex() = 0;

    virtual void RemoveVertex() = 0;

    virtual void AddEdge() = 0;

    virtual void RemoveEdge() = 0;

    virtual void GetVerticesCount() = 0;

    virtual void GetEdgesCount() = 0;

    virtual void GetAdjacentEdgesCount() = 0;

    virtual void Clear() = 0;

protected:
    UndirectedGraph<T> &undirected_graph_;
    ConsoleView console_view_;
};
