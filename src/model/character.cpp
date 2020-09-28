#include "character.h"

Character::Character(const std::string &name, const std::string &biography) :
    name_(name),
    biography_(biography) {}

const std::string &Character::get_name() const {
    return Character::name_;
}

const std::string &Character::get_biography() const {
    return Character::biography_;
}

bool Character::operator==(const Character &rhs) const {
    return name_ == rhs.name_ &&
           biography_ == rhs.biography_;
}

bool Character::operator!=(const Character &rhs) const {
    return !(rhs == *this);
}