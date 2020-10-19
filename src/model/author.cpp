#include "author.h"

Author::Author() :
        first_name_(""),
        last_name_(""),
        date_of_birth_(std::chrono::year_month_day()) {}

Author::Author(const std::string &first_name,
               const std::string &last_name,
               const std::chrono::year_month_day &date_of_birth) :
        first_name_(first_name),
        last_name_(last_name),
        date_of_birth_(date_of_birth) {}

const std::string &Author::GetFirstName() const {
    return Author::first_name_;
}

const std::string &Author::GetLastName() const {
    return Author::last_name_;
}

const std::chrono::year_month_day &Author::GetDateOfBirth() const {
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

bool Author::operator<(const Author &rhs) const {
    if (first_name_ < rhs.first_name_)
        return true;
    if (rhs.first_name_ < first_name_)
        return false;
    if (last_name_ < rhs.last_name_)
        return true;
    if (rhs.last_name_ < last_name_)
        return false;
    return date_of_birth_ < rhs.date_of_birth_;
}

bool Author::operator>(const Author &rhs) const {
    return rhs < *this;
}

bool Author::operator<=(const Author &rhs) const {
    return !(rhs < *this);
}

bool Author::operator>=(const Author &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Author &author) {
    os << "first_name: " << author.first_name_ << " last_name: " << author.last_name_ << " date_of_birth: "
       << author.date_of_birth_.day().operator unsigned int() << "."
       << author.date_of_birth_.month().operator unsigned int() << "."
       << author.date_of_birth_.year().operator int();
    return os;
}
