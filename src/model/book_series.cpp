#include "book_series.h"

BookSeries::BookSeries() {}

/** Adds new book to the series
 * @param character main character of the series
 * @param book book to add to series
 * */
void BookSeries::AddBook(Character *character, Book *book) {
    if (!character->GetMentions().contains(book)) {
        throw std::runtime_error("character is not mentioned in specified book.");
    }

    series_[character].insert(book);
}

/** Removes book from the series
 * @param character main character of the series
 * @param book book to remove
 * */
void BookSeries::RemoveBook(Character *character, Book *book) {
    if(!series_.contains(character)) {
        throw std::runtime_error("character doesn't belong to any series");
    }

    series_[character].erase(book);
}

/** @return books that are in one series */
const std::set<Book *> &BookSeries::GetBooksByCharacter(Character *character) {
    return series_[character];
}

/** @return all series of books */
const std::map<Character *, std::set<Book *>> &BookSeries::GetAllSeries() {
    return series_;
}

/** @param rhs book series to compare with
 *  @return true if current book series equals to rhs */
bool BookSeries::operator==(const BookSeries &rhs) const {
    return series_ == rhs.series_;
}

/** @param rhs book series to compare with
 *  @return true if current book series not equals to rhs */
bool BookSeries::operator!=(const BookSeries &rhs) const {
    return !(rhs == *this);
}

/** @param rhs book series to compare with
 *  @return true if current book series is less than rhs */
bool BookSeries::operator<(const BookSeries &rhs) const {
    return series_ < rhs.series_;
}

/** @param rhs book series to compare with
 *  @return true if current book series is greater than rhs */
bool BookSeries::operator>(const BookSeries &rhs) const {
    return rhs < *this;
}

/** @param rhs book series to compare with
 *  @return true if current book series is less than or equals to rhs */
bool BookSeries::operator<=(const BookSeries &rhs) const {
    return !(rhs < *this);
}

/** @param rhs book series to compare with
 *  @return true if current book series is greater than or equals to rhs */
bool BookSeries::operator>=(const BookSeries &rhs) const {
    return !(*this < rhs);
}

/** @param os target output stream
 *  @param books list of books for output
 * */
std::ostream &operator<<(std::ostream &os, const std::set<Book *> &books) {
    os << "{";
    for(auto book: books) {
        os << book << ",";
    }
    os << "}";
    return os;
}

/** @param os target output stream
 *  @param series map representing series for output
 * */
std::ostream &operator<<(std::ostream &os, const std::map<Character *, std::set<Book *>> &series) {
    os << "{";
    for(const auto &[key, value]: series) {
        os << "{" << key << ": " << value << "}";
        os << ",";
    }
    os << "}";
    return os;
}

/** @param os target output stream
 *  @param series book series output
 * */
std::ostream &operator<<(std::ostream &os, const BookSeries &series) {
    os << "series_: " << series.series_;
    return os;
}
