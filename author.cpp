#include "author.h"

Author::Author(const std::string &first_name,
               const std::string &last_name,
               const std::chrono::year_month_day &date_of_birth) {
    Author::first_name = first_name;
    Author::last_name = last_name;
    Author::date_of_birth = date_of_birth;
}

std::string Author::get_first_name() {
    return Author::first_name;
}

std::string Author::get_last_name() {
    return Author::last_name;
}

std::chrono::year_month_day Author::get_date_of_birth() {
    return Author::date_of_birth;
}
