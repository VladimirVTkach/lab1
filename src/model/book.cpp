#include "book.h"

Book::Book() :
        name_(""),
        authors_(std::vector<Author>()),
        pages_(0),
        release_date_(std::chrono::year_month_day()),
        description_(""),
        characters_(std::map<Character *, CharacterRole>()) {}

/** Constructs Book instance with specified field's values
* @param name book's name
* @param authors list of book authors
* @param pages count of pages in book
* @param release_date book's release date
* @param description book's short description
* @param characters book's characters each stored with key corresponding to their roles
* */
Book::Book(const std::string &name,
           const std::vector<Author> &authors,
           int pages,
           const std::chrono::year_month_day &release_date,
           const std::string &description,
           const std::map<Character *, CharacterRole> &characters) :
        name_(name),
        authors_(authors),
        pages_(pages),
        release_date_(release_date),
        description_(description),
        characters_(characters) {}

/** @return book's name */
const std::string &Book::GetName() const {
    return name_;
}

/** @return list of book authors */
const std::vector<Author> &Book::GetAuthors() const {
    return authors_;
}

/** @return count of pages in book */
int Book::GetPages() const {
    return pages_;
}

/** @return book's release date */
const std::chrono::year_month_day &Book::GetReleaseDate() const {
    return release_date_;
}

/** @return book's short description */
const std::string &Book::GetDescription() const {
    return description_;
}

/** @return book's characters each stored with key corresponding to their roles */
const std::map<Character *, CharacterRole> &Book::GetCharacters() const {
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

bool Book::operator<(const Book &rhs) const {
    if (name_ < rhs.name_)
        return true;
    if (rhs.name_ < name_)
        return false;
    if (authors_ < rhs.authors_)
        return true;
    if (rhs.authors_ < authors_)
        return false;
    if (pages_ < rhs.pages_)
        return true;
    if (rhs.pages_ < pages_)
        return false;
    if (release_date_ < rhs.release_date_)
        return true;
    if (rhs.release_date_ < release_date_)
        return false;
    if (description_ < rhs.description_)
        return true;
    if (rhs.description_ < description_)
        return false;
    return characters_ < rhs.characters_;
}

bool Book::operator>(const Book &rhs) const {
    return rhs < *this;
}

bool Book::operator<=(const Book &rhs) const {
    return !(rhs < *this);
}

bool Book::operator>=(const Book &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const std::vector<Author> &authors) {
    os << "[";
    for (const Author &author: authors) {
        os << "{" << author << "},";
    }
    os << "]";
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::map<Character *, CharacterRole> &characters) {
    os << "{";
    for (const auto &[character, role]: characters) {
        os << "{{" << character << "}: " << role << "}" << ",";
    }
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << "name: " << book.name_ << " authors: " << book.authors_ << " pages: " << book.pages_ << " release_date: "
       << book.release_date_.day().operator unsigned int() << "."
       << book.release_date_.month().operator unsigned int() << "."
       << book.release_date_.year().operator int()
       << " description: " << book.description_ << " characters: " << book.characters_;
    return os;
}
