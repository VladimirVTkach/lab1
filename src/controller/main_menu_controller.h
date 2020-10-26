#pragma once

#include "crud_controller.h"
#include "../graph/undirected_graph.h"
#include "../view/console_view.h"

template<typename T>
class MainMenuController {
public:
    MainMenuController(UndirectedGraph<T> &undirected_graph,
                       const ConsoleView &console_view,
                       CrudController<T> &crud_controller) : undirected_graph_(undirected_graph),
                                                             console_view_(console_view),
                                                             crud_controller_(crud_controller) {}

    void Start() {
        console_view_.ShowMainMenu();
        while (true) {
            int option = std::stoi(console_view_.GetUserInput("Your option"));
            if (option <= 0 || option > 10) {
                console_view_.ShowMessage("Invalid option chosen");
            } else {
                if (option == 1) {
                    crud_controller_.AddVertex();
                } else if (option == 2) {
                    crud_controller_.RemoveVertex();
                } else if (option == 3) {
                    crud_controller_.AddEdge();
                } else if (option == 4) {
                    crud_controller_.RemoveEdge();
                } else if (option == 5) {
                    crud_controller_.GetVerticesCount();
                } else if (option == 6) {
                    crud_controller_.GetEdgesCount();
                } else if (option == 7) {
                    crud_controller_.GetAdjacentEdgesCount();
                } else if (option == 8) {
                    crud_controller_.Clear();
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
    CrudController<T> &crud_controller_;
};