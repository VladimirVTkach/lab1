#include "book.h"

Book::Book(const std::string &name,
     const std::vector<Author> &authors,
     int pages,
     const std::chrono::year_month_day &release_date,
     const std::string &description) {
    Book::name = name;
    Book::authors = authors;
    Book::pages = pages;
    Book::release_date = release_date;
    Book::description = description;
}

const std::string &Book::getName() const {
    return name;
}

const std::vector<Author> &Book::getAuthors() const {
    return authors;
}

int Book::getPages() const {
    return pages;
}

const std::chrono::year_month_day &Book::getReleaseDate() const {
    return release_date;
}

const std::string &Book::getDescription() const {
    return description;
}
