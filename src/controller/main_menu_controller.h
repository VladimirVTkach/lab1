#pragma once

#include "crud_controller.h"
#include "../graph/undirected_graph.h"
#include "../view/console_view.h"

template<typename T>
class MainMenuController {
public:
    MainMenuController(UndirectedGraph<T> &undirected_graph,
                       const ConsoleView &console_view) : undirected_graph_(undirected_graph),
                                                          console_view_(console_view),
                                                          crud_controller(CrudController<T>(undirected_graph,
                                                                                            console_view)) {}

    void Start() {
        console_view_.ShowMainMenu();
        while (true) {
            int option = console_view_.GetUserInput<int>("Your option");
            if (option <= 0 || option > 10) {
                console_view_.ShowMessage("Invalid option chosen");
            } else {
                if (option == 1) {
                    crud_controller.AddVertex();
                } else if (option == 2) {
                    crud_controller.RemoveVertex();
                } else if (option == 3) {
                    crud_controller.AddEdge();
                } else if (option == 4) {
                    crud_controller.RemoveEdge();
                } else if (option == 5) {
                    crud_controller.GetVerticesCount();
                } else if (option == 6) {
                    crud_controller.GetEdgesCount();
                } else if (option == 7) {
                    crud_controller.GetAdjacentEdgesCount();
                } else if (option == 8) {
                    crud_controller.Clear();
                } else if (option == 9) {
                    console_view_.ShowGraph(undirected_graph_);
                } else if (option == 10) {
                    return;
                }
            }
        }
    }

private:
    UndirectedGraph<T> &undirected_graph_;
    ConsoleView console_view_;
    CrudController<T> crud_controller;
};