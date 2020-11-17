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

/** Adds mention about character and his role in some book
 *  @param book book to add mention for
 *  @param character_role character role in specified book
 *  */
void Character::AddMention(Book *book, CharacterRole character_role) {
    mentions_[book] = character_role;
}

/** Returns all mentions about character and his roles in different books
 * @return map of Book* to Character role representing character mentions
 * */
const std::map<Book *, CharacterRole> &Character::GetMentions() const {
    return mentions_;
}

/** @param rhs character to compare with
 *  @return true if current character equals to rhs */
bool Character::operator==(const Character &rhs) const {
    return name_ == rhs.name_ &&
           biography_ == rhs.biography_ &&
           mentions_ == rhs.mentions_;
}

/** @param rhs character to compare with
 *  @return true if current character not equals to rhs */
bool Character::operator!=(const Character &rhs) const {
    return !(rhs == *this);
}

/** @param rhs character to compare with
 *  @return true if current book is less than rhs */
bool Character::operator<(const Character &rhs) const {
    if (name_ < rhs.name_)
        return true;
    if (rhs.name_ < name_)
        return false;
    if (biography_ < rhs.biography_)
        return true;
    if (rhs.biography_ < biography_)
        return false;
    return mentions_ < rhs.mentions_;
}

/** @param os target output stream
 *  @param mentions map of mentions for output
 * */
std::ostream &operator<<(std::ostream &os, const std::map<Book *, CharacterRole> &mentions) {
    os << "{";
    for (const auto &[key, value]: mentions) {
        os << "{" << key << ": " << value << "}";
        os << ",";
    }
    os << "}";
    return os;
}

/** @param os target output stream
 *  @param character character for output
 * */
std::ostream &operator<<(std::ostream &os, const Character &character) {
    os << "name_: " << character.name_ << " biography_: " << character.biography_ << " mentions_: "
       << character.mentions_;
    return os;
}

/** @param rhs character to compare with
 *  @return true if current book is greater than rhs */
bool Character::operator>(const Character &rhs) const {
    return rhs < *this;
}

/** @param rhs character to compare with
 *  @return true if current book is less than or equals to rhs */
bool Character::operator<=(const Character &rhs) const {
    return !(rhs < *this);
}

/** @param rhs character to compare with
 *  @return true if current book is greater than or equals to rhs */
bool Character::operator>=(const Character &rhs) const {
    return !(*this < rhs);
}