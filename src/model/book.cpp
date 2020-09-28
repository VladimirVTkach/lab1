#include "book.h"

Book::Book(const std::string &name,
           const std::vector<Author> &authors,
           int pages,
           const std::chrono::year_month_day &release_date,
           const std::string &description,
           const std::map<CharacterRole, std::vector<Character>> &characters) :
        name_(name),
        authors_(authors),
        pages_(pages),
        release_date_(release_date),
        description_(description),
        characters_(characters) {}

const std::string &Book::get_name() const {
    return name_;
}

const std::vector<Author> &Book::get_authors() const {
    return authors_;
}

int Book::get_pages() const {
    return pages_;
}

const std::chrono::year_month_day &Book::get_release_date() const {
    return release_date_;
}

const std::string &Book::get_description() const {
    return description_;
}

const std::map<CharacterRole, std::vector<Character>> &Book::get_characters() const {
    return characters_;
}

bool Book::operator==(const Book &rhs) const {
    return name_ == rhs.name_ &&
           authors_ == rhs.authors_ &&
           pages_ == rhs.pages_ &&
           release_date_ == rhs.release_date_ &&
           description_ == rhs.description_ &&
           characters_ == rhs.characters_;
}

bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}
