#include "character.h"

Character::Character(const std::string &name, const std::string &biography) :
    name(name),
    biography(biography) {}

const std::string &Character::get_name() const {
    return Character::name;
}

const std::string &Character::get_biography() const {
    return Character::biography;
}

bool Character::operator==(const Character &rhs) const {
    return name == rhs.name &&
           biography == rhs.biography;
}

bool Character::operator!=(const Character &rhs) const {
    return !(rhs == *this);
}