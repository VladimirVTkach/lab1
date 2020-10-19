#pragma once

#include <string>
#include <chrono>
#include <ostream>

/** Class representing book's author */
class Author {
public:
    Author();

    Author(const std::string &first_name,
           const std::string &last_name,
           const std::chrono::year_month_day &date_of_birth);

    /** @return author's first name */
    const std::string &GetFirstName() const;

    /** @return author's last name */
    const std::string &GetLastName() const;

    /** @return author's date of birth */
    const std::chrono::year_month_day &GetDateOfBirth() const;


    bool operator==(const Author &rhs) const;

    bool operator!=(const Author &rhs) const;

    bool operator<(const Author &rhs) const;

    bool operator>(const Author &rhs) const;

    bool operator<=(const Author &rhs) const;

    bool operator>=(const Author &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Author &author);

private:
    std::string first_name_;
    std::string last_name_;
    std::chrono::year_month_day date_of_birth_;
};
