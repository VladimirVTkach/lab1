#include "../tst/tests_runner.h"
#include "graph/adjacent_undirected_graph.h"
#include "graph/matrix_undirected_graph.h"
#include "view/console_view.h"
#include "controller/main_menu_controller.h"

int main() {
// Runs all tests
//    run_all_tests();

    AdjacentUndirectedGraph<std::string> graph;
    ConsoleView console_view;
    MainMenuController<std::string> main_menu_controller(graph, console_view);
    main_menu_controller.Start();
}
