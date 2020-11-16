#pragma once

#include <string>
#include <ostream>

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
};