#pragma once

#include <vector>
#include <map>
#include <ostream>
#include "author.h"

/** Class representing book */
class Book {
public:
    Book();

    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description);

    const std::string &GetName() const;

    const std::vector<Author> &GetAuthors() const;

    int GetPages() const;

    const std::chrono::year_month_day &GetReleaseDate() const;

    const std::string &GetDescription() const;

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

        friend std::ostream &operator<<(std::ostream &os, const Book &book);

    bool operator<(const Book &rhs) const;

    bool operator>(const Book &rhs) const;

    bool operator<=(const Book &rhs) const;

    bool operator>=(const Book &rhs) const;

private:
    std::string name_;
    std::vector<Author> authors_;
    int pages_;
    std::chrono::year_month_day release_date_;
    std::string description_;
};
