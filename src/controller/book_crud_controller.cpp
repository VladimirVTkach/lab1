#include "book_crud_controller.h"
#include <sstream>

BookCrudController::BookCrudController(UndirectedGraph<Book> &undirected_graph, const ConsoleView &console_view) :
        CrudController<Book>(undirected_graph, console_view) {}

Book BookCrudController::GetVertex(std::string message) {
    std::string book_name = GetString("Enter name: ");
    std::vector<Author> authors = GetAuthors("Enter list of authors: ");
    int pages = GetNumber("Enter pages count: ");
    std::chrono::year_month_day release_date = GetDate("Enter release date: ");
    std::string description = GetString("Enter description: ");

    return Book(book_name,
                    authors,
                    pages,
                    release_date,
                    description);
}

std::string BookCrudController::GetString(const std::string &hint) {
    std::string name;

    std::cout << hint << std::endl;
    std::getline(std::cin, name);
    std::getline(std::cin, name);

    return name;
}

std::vector<Author> BookCrudController::GetAuthors(const std::string &hint) {
    int authors_count = GetNumber("Enter number of authors: ");

    std::vector<Author> authors;
    for(int i = 0; i < authors_count; i++) {
        authors.push_back(GetAuthor("Enter author: "));
    }

    return authors;
}

Author BookCrudController::GetAuthor(const std::string &hint) {
    std::string first_name;
    std::string last_name;
    std::chrono::year_month_day date_of_birth{};

    std::cout << hint << std::endl;
    first_name = GetString("Enter first name: ");
    last_name = GetString("Enter last name: ");
    date_of_birth = GetDate("Enter date of birth: ");

    return Author(first_name, last_name, date_of_birth);
}

int BookCrudController::GetNumber(const std::string &hint) {
    int pages;

    std::cout << hint << std::endl;
    std::cin >> pages;

    return pages;
}

std::chrono::year_month_day BookCrudController::GetDate(const std::string &hint) {
    int year;
    int month;
    int day;

    std::cout << hint << std::endl;
    std::cout << "Enter year: " << std::endl;
    std::cin >> year;
    std::cout << "Enter month: " << std::endl;
    std::cin >> month;
    std::cout << "Enter day: " << std::endl;
    std::cin >> day;

    return std::chrono::year_month_day(std::chrono::year(year),
                                       std::chrono::month(month),
                                       std::chrono::day(day));
}