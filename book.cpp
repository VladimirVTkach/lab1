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

const std::string &Book::get_name() const {
    return name;
}

const std::vector<Author> &Book::get_authors() const {
    return authors;
}

int Book::get_pages() const {
    return pages;
}

const std::chrono::year_month_day &Book::get_release_date() const {
    return release_date;
}

const std::string &Book::get_description() const {
    return description;
}
