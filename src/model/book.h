#pragma once

#include <vector>
#include <map>
#include "author.h"
#include "character.h"

enum CharacterRole {
    MAIN, SECONDARY
};

class Book {
public:
    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description,
         const std::map<CharacterRole, std::vector<Character>> &characters);

    const std::string &GetName() const;

    const std::vector<Author> &GetAuthors() const;

    int GetPages() const;

    const std::chrono::year_month_day &GetReleaseDate() const;

    const std::string &GetDescription() const;

    const std::map<CharacterRole, std::vector<Character>> &GetCharacters() const;

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

private:
    std::string name_;
    std::vector<Author> authors_;
    int pages_;
    std::chrono::year_month_day release_date_;
    std::string description_;
    std::map<CharacterRole, std::vector<Character>> characters_;
};
