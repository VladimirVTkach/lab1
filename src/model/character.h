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

    /** Constructs Character instance with specified field's values */
    Character(const std::string &name,
              const std::string &biography);

    /** Returns character name */
    const std::string &GetName() const;

    /** Returns character biography */
    const std::string &GetBiography() const;

    /** Adds mention about character and his role in some book */
    void AddMention(Book *book, CharacterRole characterRole);

    /** Returns all mentions about character and his roles in different books */
    const std::map<Book *, CharacterRole> &GetMentions() const;

    /** Compares two characters for equality */
    bool operator==(const Character &rhs) const;

    /** Compares two characters for inequality */
    bool operator!=(const Character &rhs) const;

    /** Check whether current character is less then other */
    bool operator<(const Character &rhs) const;

    /** Check whether current character is greater then other */
    bool operator>(const Character &rhs) const;

    /** Check whether current character is less than or equal to other */
    bool operator<=(const Character &rhs) const;

    /** Check whether current character is greater than or equal to other */
    bool operator>=(const Character &rhs) const;

    /** Output character to the target stream */
    friend std::ostream &operator<<(std::ostream &os, const Character &character);

private:
    std::string name_;
    std::string biography_;
    std::map<Book *, CharacterRole> mentions_;
};