#include "../tst/tests_runner.h"
#include "graph/adjacent_undirected_graph.h"
#include "graph/matrix_undirected_graph.h"
#include "view/console_view.h"
#include "controller/int_crud_controller.h"
#include "controller/double_crud_controller.h"
#include "controller/string_crud_controller.h"
#include "controller/vector_crud_controller.h"
#include "controller/main_menu_controller.h"

int main() {
// Runs all tests
//    run_all_tests();

    AdjacentUndirectedGraph<std::vector<int>> graph;
    ConsoleView console_view;
    VectorCrudController vectorCrudController(graph, console_view);
    MainMenuController<std::vector<int>> main_menu_controller(graph,
                                                    console_view,
                                                    vectorCrudController);
    main_menu_controller.Start();
}
