#include <gtest/gtest.h>
#include <chrono>
#include "../../src/model/book.h"

bool operator==(const std::vector<Author> &lhs, const std::vector<Author> &rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (int i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) return false;
    }
    return true;
}

TEST(book_tests, test_get_name) {
    std::string name = "Generation P";
    Book book(name,
              std::vector<Author>(),
              0,
              std::chrono::year_month_day(),
              "");
    ASSERT_EQ(name, book.get_name());
}

TEST(book_tests, test_get_authors) {
    std::vector<Author> authors;
    Author author("Ivan",
                  "Ivanov",
                  std::chrono::year_month_day());
    authors.push_back(author);

    Book book("",
              authors,
              0,
              std::chrono::year_month_day(),
              "");
    ASSERT_EQ(authors, book.get_authors());
}

TEST(book_tests, test_get_pages) {
    int pages = 100;
    Book book("",
              std::vector<Author>(),
              pages,
              std::chrono::year_month_day(),
              "");
    ASSERT_EQ(pages, book.get_pages());
}

TEST(book_tests, test_get_release_date) {
    std::chrono::year_month_day release_date = std::chrono::year_month_day(
            std::chrono::year(2020),
            std::chrono::month(9),
            std::chrono::day(15));
    Book book("",
              std::vector<Author>(),
              0,
              release_date,
              "");
    ASSERT_EQ(release_date, book.get_release_date());
}

TEST(book_tests, test_get_description) {
    std::string description = "very interesting book!";
    Book book("",
              std::vector<Author>(),
              0,
              std::chrono::year_month_day(),
              description);
    ASSERT_EQ(description, book.get_description());
}