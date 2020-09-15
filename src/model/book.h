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
         const std::map<Character, CharacterRole> &characters);

    const std::string &get_name() const;

    const std::vector<Author> &get_authors() const;

    int get_pages() const;

    const std::chrono::year_month_day &get_release_date() const;

    const std::string &get_description() const;

    const std::map<Character, CharacterRole> &get_characters() const;

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

private:
    std::string name;
    std::vector<Author> authors;
    int pages;
    std::chrono::year_month_day release_date{};
    std::string description;
    std::map<Character, CharacterRole> characters;
};
