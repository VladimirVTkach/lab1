#include "author.h"

Author::Author(const std::string &first_name,
               const std::string &last_name,
               const std::chrono::year_month_day &date_of_birth) :
        first_name(first_name),
        last_name(last_name),
        date_of_birth(date_of_birth) {}

const std::string &Author::get_first_name() const {
    return Author::first_name;
}

const std::string &Author::get_last_name() const {
    return Author::last_name;
}

const std::chrono::year_month_day &Author::get_date_of_birth() const {
    return Author::date_of_birth;
}

bool Author::operator==(const Author &rhs) const {
    return first_name == rhs.first_name &&
           last_name == rhs.last_name &&
           date_of_birth == rhs.date_of_birth;
}

bool Author::operator!=(const Author &rhs) const {
    return !(rhs == *this);
}
