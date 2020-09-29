#include "character.h"

Character::Character(const std::string &name, const std::string &biography) :
    name_(name),
    biography_(biography) {}

const std::string &Character::GetName() const {
    return Character::name_;
}

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
