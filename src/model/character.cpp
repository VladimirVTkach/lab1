#include "character.h"

Character::Character() :
        name_(""),
        biography_("") {}

/** Constructs Character instance with specified field's values
* @param name character's name
* @param biography character's biography
* */
Character::Character(const std::string &name, const std::string &biography) :
        name_(name),
        biography_(biography) {}

/** @return character's name */
const std::string &Character::GetName() const {
    return Character::name_;
}

/** @return character's biography */
const std::string &Character::GetBiography() const {
    return Character::biography_;
}

bool Character::operator==(const Character &rhs) const {
    return name_ == rhs.name_ &&
           biography_ == rhs.biography_;
}

bool Character::operator!=(const Character &rhs) const {
    return !(rhs == *this);
}

bool Character::operator<(const Character &rhs) const {
    if (name_ < rhs.name_)
        return true;
    if (rhs.name_ < name_)
        return false;
    return biography_ < rhs.biography_;
}

bool Character::operator>(const Character &rhs) const {
    return rhs < *this;
}

bool Character::operator<=(const Character &rhs) const {
    return !(rhs < *this);
}

bool Character::operator>=(const Character &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Character &character) {
    os << "name: " << character.name_ << " biography: " << character.biography_;
    return os;
}
