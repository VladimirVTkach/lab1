#pragma once

#include <vector>
#include <map>
#include "author.h"
#include "character.h"

/** Enum representing possible character roles in book */
enum CharacterRole {
    MAIN, SECONDARY
};

/** Class representing book */
class Book {
public:
    Book();

    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description,
         const std::map<Character *, CharacterRole> &characters);

    const std::string &GetName() const;

    const std::vector<Author> &GetAuthors() const;

    int GetPages() const;

    const std::chrono::year_month_day &GetReleaseDate() const;

    const std::string &GetDescription() const;

    const std::map<Character *, CharacterRole> &GetCharacters() const;

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

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
    std::map<Character *, CharacterRole> characters_;
};
