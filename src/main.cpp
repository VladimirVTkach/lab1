#include "../tst/tests_runner.h"
#include "graph/adjacent_undirected_graph.h"
#include "graph/matrix_undirected_graph.h"
#include "view/console_view.h"
#include "controller/int_crud_controller.h"
#include "controller/double_crud_controller.h"
#include "controller/string_crud_controller.h"
#include "controller/vector_crud_controller.h"
#include "controller/book_crud_controller.h"
#include "controller/main_menu_controller.h"

int main() {
// Runs all tests
    run_all_tests();

//    AdjacentUndirectedGraph<int> graph;
//    ConsoleView console_view;
//    IntCrudController book_crud_controller(graph, console_view);
//    MainMenuController<int> main_menu_controller(graph,
//                                                    console_view,
//                                                    book_crud_controller);
//    main_menu_controller.Start();
}
