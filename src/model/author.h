#pragma once

#include <string>
#include <chrono>

class Author {
public:
    Author();

    Author(const std::string &first_name,
           const std::string &last_name,
           const std::chrono::year_month_day &date_of_birth);

    const std::string &GetFirstName() const;

    const std::string &GetLastName() const;

    const std::chrono::year_month_day &GetDateOfBirth() const;

    bool operator==(const Author &rhs) const;

    bool operator!=(const Author &rhs) const;

    bool operator<(const Author &rhs) const;

    bool operator>(const Author &rhs) const;

    bool operator<=(const Author &rhs) const;

    bool operator>=(const Author &rhs) const;

private:
    std::string first_name_;
    std::string last_name_;
    std::chrono::year_month_day date_of_birth_;
};
