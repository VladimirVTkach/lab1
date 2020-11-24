#pragma once

#include "../graph/undirected_graph.h"
#include <iostream>

class ConsoleView {
public:
    void ShowMainMenu() {
        std::cout << "*** Graphs demonstration ***" << std::endl;
        std::cout << "Choose one of the following options: " << std::endl;
        std::cout << "1. Add vertex" << std::endl;
        std::cout << "2. Remove vertex" << std::endl;
        std::cout << "3. Add edge" << std::endl;
        std::cout << "4. Remove edge" << std::endl;
        std::cout << "5. Get total vertices count" << std::endl;
        std::cout << "6. Get total edges count" << std::endl;
        std::cout << "7. Get adjacent to vertex edges count" << std::endl;
        std::cout << "8. Reset graph" << std::endl;
        std::cout << "9. Show graph" << std::endl;
        std::cout << "10. Find distance" << std::endl;
        std::cout << "11. Check is graph linked" << std::endl;
        std::cout << "12. Exit" << std::endl;
    }

    template<typename T>
    void ShowGraph(const UndirectedGraph<T> &graph) {
        std::cout << graph << std::endl;
    }

    std::string GetUserInput(const std::string &hint) {
        std::cout << hint << ": " << std::endl;
        std::string response;
        std::cin >> response;
        return response;
    }

    void ShowMessage(const std::string &message) {
        std::cout << message << std::endl;
    }
};