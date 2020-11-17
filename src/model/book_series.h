#pragma once

#include "character.h"
#include "book.h"
#include <map>
#include <set>
#include <ostream>

class BookSeries {
public:
    BookSeries();

    /** Adds new book to the series */
    void AddBook(Character *character, Book *book);

    /** Removes book from the series */
    void RemoveBook(Character *character, Book *book);

    /** Returns all books where specified character appears */
    const std::set<Book *> &GetBooksByCharacter(Character *character);

    /** Returns all book series */
    const std::map<Character *, std::set<Book *>> &GetAllSeries();

    /** Compares two book series for equality */
    bool operator==(const BookSeries &rhs) const;

    /** Compares two book series for inequality */
    bool operator!=(const BookSeries &rhs) const;

    /** Check whether current book series is less then other */
    bool operator<(const BookSeries &rhs) const;

    /** Check whether current book series is greater then other */
    bool operator>(const BookSeries &rhs) const;

    /** Check whether current book series is less then or equals to other */
    bool operator<=(const BookSeries &rhs) const;

    /** Check whether current book series is greater then or equals to other */
    bool operator>=(const BookSeries &rhs) const;

    /** Output book series to the target stream */
    friend std::ostream &operator<<(std::ostream &os, const BookSeries &series);

private:
    std::map<Character *, std::set<Book *>> series_;
};
