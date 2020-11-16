#pragma once

#include <vector>
#include <map>
#include <ostream>
#include "author.h"

/** Class representing book */
class Book {
public:
    Book();

    /** Constructs Book instance with specified field's values */
    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description);

    /** Returns book name*/
    const std::string &GetName() const;

    /** Returns list of book authors */
    const std::vector<Author> &GetAuthors() const;

    /** Returns pages count */
    int GetPages() const;

    /** Returns book release date */
    const std::chrono::year_month_day &GetReleaseDate() const;

    /** Returns book description */
    const std::string &GetDescription() const;

    /** Compares two books for equality */
    bool operator==(const Book &rhs) const;

    /** Compares two books for inequality */
    bool operator!=(const Book &rhs) const;

    /**  */
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    /** Check whether current book is less then other */
    bool operator<(const Book &rhs) const;

    /** Check whether current book is greater then other */
    bool operator>(const Book &rhs) const;

    /** Check whether current book is less than or equal to other */
    bool operator<=(const Book &rhs) const;

    /** Check whether current book is greater than or equal to other */
    bool operator>=(const Book &rhs) const;

private:
    std::string name_;
    std::vector<Author> authors_;
    int pages_;
    std::chrono::year_month_day release_date_;
    std::string description_;
};
