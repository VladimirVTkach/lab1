#pragma once

#include <string>
#include <chrono>

class Author {
public:
    Author(const std::string &first_name,
           const std::string &last_name,
           const std::chrono::year_month_day &date_of_birth);

    const std::string &get_first_name() const;

    const std::string &get_last_name() const;

    const std::chrono::year_month_day &get_date_of_birth() const;

    bool operator==(const Author &rhs) const;

    bool operator!=(const Author &rhs) const;

private:
    std::string first_name;
    std::string last_name;
    std::chrono::year_month_day date_of_birth;
};
