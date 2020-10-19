#pragma once

#include <string>
#include <ostream>

/** Class representing book's character */
class Character {
public:
    Character();

    /** Constructs Character instance with specified field's values
     * @param name character's name
     * @param biography character's biography
     * */
    Character(const std::string &name,
              const std::string &biography);

    /** @return character's name */
    const std::string &GetName() const;

    /** @return character's biography */
    const std::string &GetBiography() const;

    /** Compares for equality this instance to other Character instance.
     * If instances are equal returns true, otherwise false.
     * @param rhs instance of Character to compare this instance to
     * @return comparison result
     * */
    bool operator==(const Character &rhs) const;

    /** Compares for inequality this instance to other Character instance.
     * If instances are not equal returns true, otherwise false.
     * @param rhs instance of Character to compare this instance to
     * @return comparison result
     * */
    bool operator!=(const Character &rhs) const;

    /** Compares the relative order of this instance to other Character instance.
     * If this instances is less then other instance returns true, otherwise false.
     * @param rhs instance of Character to compare this instance to
     * @return comparison result
     * */
    bool operator<(const Character &rhs) const;

    /** Compares the relative order of this instance to other Character instance.
     * If this instances is greater then other instance returns true, otherwise false.
     * @param rhs instance of Character to compare this instance to
     * @return comparison result
     * */
    bool operator>(const Character &rhs) const;

    /** Compares the relative order of this instance to other Character instance.
     * If this instances is less than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Character to compare this instance to
     * @return comparison result
     * */
    bool operator<=(const Character &rhs) const;

    /** Compares the relative order of this instance to other Character instance.
   * If this instances is greater than or equals to other instance returns true, otherwise false.
   * @param rhs instance of Character to compare this instance to
   * @return comparison result
   * */
    bool operator>=(const Character &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Character &character);

private:
    std::string name_;
    std::string biography_;
};