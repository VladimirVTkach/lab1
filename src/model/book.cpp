#include "book.h"

Book::Book(const std::string &name,
           const std::vector<Author> &authors,
           int pages,
           const std::chrono::year_month_day &release_date,
           const std::string &description,
           const std::map<CharacterRole, std::vector<Character>> &characters) {
    Book::name = name;
    Book::authors = authors;
    Book::pages = pages;
    Book::release_date = release_date;
    Book::description = description;
    Book::characters = characters;
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

const std::map<CharacterRole, std::vector<Character>> &Book::get_characters() const {
    return characters;
}

bool Book::operator==(const Book &rhs) const {
    return name == rhs.name &&
           authors == rhs.authors &&
           pages == rhs.pages &&
           release_date == rhs.release_date &&
           description == rhs.description &&
           characters == rhs.characters;
}

bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}
