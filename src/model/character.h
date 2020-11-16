#pragma once

#include "book.h"
#include <string>
#include <ostream>
#include <map>

/** Enum representing possible character roles in book */
enum CharacterRole {
    MAIN, SECONDARY
};

/** Class representing book's character */
class Character {
public:
    Character();

    Character(const std::string &name,
              const std::string &biography);

    const std::string &GetName() const;

    const std::string &GetBiography() const;

    void AddMention(const Book* book, CharacterRole characterRole);

    const std::map<Book *, CharacterRole> &GetMentions() const;

    bool operator==(const Character &rhs) const;

    bool operator!=(const Character &rhs) const;

    bool operator<(const Character &rhs) const;

    bool operator>(const Character &rhs) const;

    bool operator<=(const Character &rhs) const;

    bool operator>=(const Character &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Character &character);

private:
    std::string name_;
    std::string biography_;
    std::map<Book *, CharacterRole> mentions_;
};