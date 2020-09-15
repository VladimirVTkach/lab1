#include "book.h"

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
