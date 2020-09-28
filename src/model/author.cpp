#include "author.h"

Author::Author(const std::string &first_name,
               const std::string &last_name,
               const std::chrono::year_month_day &date_of_birth) :
        first_name_(first_name),
        last_name_(last_name),
        date_of_birth_(date_of_birth) {}

const std::string &Author::get_first_name() const {
    return Author::first_name_;
}

const std::string &Author::get_last_name() const {
    return Author::last_name_;
}

const std::chrono::year_month_day &Author::get_date_of_birth() const {
    return Author::date_of_birth_;
}

bool Author::operator==(const Author &rhs) const {
    return first_name_ == rhs.first_name_ &&
           last_name_ == rhs.last_name_ &&
           date_of_birth_ == rhs.date_of_birth_;
}

bool Author::operator!=(const Author &rhs) const {
    return !(rhs == *this);
}
