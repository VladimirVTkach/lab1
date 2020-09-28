#include <gtest/gtest.h>
#include <chrono>
#include "../../src/model/author.h"

TEST(author_tests, test_get_first_name) {
    std::string first_name = "Ivan";
    Author author(first_name,
                  "",
                  std::chrono::year_month_day());
    ASSERT_EQ(first_name, author.GetFirstName());
}

TEST(author_tests, test_get_last_name) {
    std::string last_name = "Ivanov";
    Author author("",
                  last_name,
                  std::chrono::year_month_day());
    ASSERT_EQ(last_name, author.GetLastName());
}

TEST(author_tests, test_get_date_of_birth) {
    std::chrono::year_month_day date_of_birth = std::chrono::year_month_day(
            std::chrono::year(2020),
            std::chrono::month(9),
            std::chrono::day(15));
    Author author("",
                  "",
                  date_of_birth);
    ASSERT_EQ(date_of_birth, author.GetDateOfBirth());
}
