#pragma once

#include "../model/book.h"
#include "crud_controller.h"

class BookCrudController : public CrudController<Book> {
public:
    BookCrudController(UndirectedGraph<Book> &undirected_graph,
                      const ConsoleView &console_view);
protected:
    Book GetVertex(std::string message) override;

private:
    std::string GetString(const std::string &hint);
    std::vector<Author> GetAuthors(const std::string &hint);
    Author GetAuthor(const std::string &hint);
    int GetNumber(const std::string &hint);
    std::chrono::year_month_day GetDate(const std::string &hint);
};