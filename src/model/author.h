#pragma once

#include <string>
#include <chrono>
#include <ostream>

/** Class representing book's author */
class Author {
public:
    Author();

    /** Constructs Author instance with specified field's values */
    Author(const std::string &first_name,
           const std::string &last_name,
           const std::chrono::year_month_day &date_of_birth);

    /** Returns author first name */
    const std::string &GetFirstName() const;

    /** Returns author last name */
    const std::string &GetLastName() const;

    /** Returns author date of birth */
    const std::chrono::year_month_day &GetDateOfBirth() const;

    /** Compares two authors for equality */
    bool operator==(const Author &rhs) const;

    /** Compares two authors for inequality */
    bool operator!=(const Author &rhs) const;

    /** Check whether current author is less then other */
    bool operator<(const Author &rhs) const;

    /** Check whether current author is greater then other */
    bool operator>(const Author &rhs) const;

    /** Check whether current author is less than or equal to other */
    bool operator<=(const Author &rhs) const;

    /** Check whether current author is greater than or equal to other */
    bool operator>=(const Author &rhs) const;

    /** Output author to the target stream */
    friend std::ostream &operator<<(std::ostream &os, const Author &author);

private:
    std::string first_name_;
    std::string last_name_;
    std::chrono::year_month_day date_of_birth_;
};
