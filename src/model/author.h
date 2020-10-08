#pragma once

#include <string>
#include <chrono>

/** Class representing book's author */
class Author {
public:
    Author();

    /** Constructs Author instance with specified field's values
     * @param first_name author's first name
     * @param last_name author's last name
     * @param date_of_birth author's date of birth
     * */
    Author(const std::string &first_name,
           const std::string &last_name,
           const std::chrono::year_month_day &date_of_birth);

    /** @return author's first name */
    const std::string &GetFirstName() const;

    /** @return author's last name */
    const std::string &GetLastName() const;

    /** @return author's date of birth */
    const std::chrono::year_month_day &GetDateOfBirth() const;

    /** Compares for equality this instance to other Author instance.
     * If instances are equal returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator==(const Author &rhs) const;

    /** Compares for inequality this instance to other Author instance.
     * If instances are not equal returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator!=(const Author &rhs) const;

    /** Compares the relative order of this instance to other Author instance.
     * If this instances is less then other instance returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator<(const Author &rhs) const;

    /** Compares the relative order of this instance to other Author instance.
     * If this instances is greater then other instance returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator>(const Author &rhs) const;

    /** Compares the relative order of this instance to other Author instance.
     * If this instances is less than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator<=(const Author &rhs) const;

    /** Compares the relative order of this instance to other Author instance.
     * If this instances is greater than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Author to compare this instance to
     * @return comparison result
     * */
    bool operator>=(const Author &rhs) const;

private:
    std::string first_name_;
    std::string last_name_;
    std::chrono::year_month_day date_of_birth_;
};
