#include "author.h"

Author::Author() :
        first_name_(""),
        last_name_(""),
        date_of_birth_(std::chrono::year_month_day()) {}

/** Constructs Author instance with specified field's values
* @param first_name author's first name
* @param last_name author's last name
* @param date_of_birth author's date of birth
* */
Author::Author(const std::string &first_name,
               const std::string &last_name,
               const std::chrono::year_month_day &date_of_birth) :
        first_name_(first_name),
        last_name_(last_name),
        date_of_birth_(date_of_birth) {}

/** @return author's first name */
const std::string &Author::GetFirstName() const {
    return Author::first_name_;
}

/** @return author's last name */
const std::string &Author::GetLastName() const {
    return Author::last_name_;
}

/** @return author's date of birth */
const std::chrono::year_month_day &Author::GetDateOfBirth() const {
    return Author::date_of_birth_;
}

/** @param rhs author to compare with
 *  @return true if current author equals to rhs */
bool Author::operator==(const Author &rhs) const {
    return first_name_ == rhs.first_name_ &&
           last_name_ == rhs.last_name_ &&
           date_of_birth_ == rhs.date_of_birth_;
}

/** @param rhs author to compare with
 *  @return true if current author not equals to rhs */
bool Author::operator!=(const Author &rhs) const {
    return !(rhs == *this);
}

/** @param rhs author to compare with
 *  @return true if current author is less than rhs */
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

/** @param rhs author to compare with
 *  @return true if current author is greater than rhs */
bool Author::operator>(const Author &rhs) const {
    return rhs < *this;
}

/** @param rhs author to compare with
 *  @return true if current author is less than or equals to rhs */
bool Author::operator<=(const Author &rhs) const {
    return !(rhs < *this);
}

/** @param rhs author to compare with
 *  @return true if current author is greater than or equals to rhs */
bool Author::operator>=(const Author &rhs) const {
    return !(*this < rhs);
}

/** @param os target output stream
 *  @param author author for output
 * */
std::ostream &operator<<(std::ostream &os, const Author &author) {
    os << "first_name: " << author.first_name_ << " last_name: " << author.last_name_ << " date_of_birth: "
       << author.date_of_birth_.day().operator unsigned int() << "."
       << author.date_of_birth_.month().operator unsigned int() << "."
       << author.date_of_birth_.year().operator int();
    return os;
}
