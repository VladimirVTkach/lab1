#include <gtest/gtest.h>
#include <chrono>
#include "../../src/model/book.h"

TEST(book_tests, test_get_name) {
    std::string name = "Generation P";
    Book book(name,
              std::vector<Author>(),
              0,
              std::chrono::year_month_day(),
              "",
              std::map<Character*, CharacterRole>());
    ASSERT_EQ(name, book.GetName());
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
              "",
              std::map<Character*, CharacterRole>());
    ASSERT_EQ(authors, book.GetAuthors());
}

TEST(book_tests, test_get_pages) {
    int pages = 100;
    Book book("",
              std::vector<Author>(),
              pages,
              std::chrono::year_month_day(),
              "",
              std::map<Character*, CharacterRole>());
    ASSERT_EQ(pages, book.GetPages());
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
              "",
              std::map<Character*, CharacterRole>());
    ASSERT_EQ(release_date, book.GetReleaseDate());
}

TEST(book_tests, test_get_description) {
    std::string description = "very interesting book!";
    Book book("",
              std::vector<Author>(),
              0,
              std::chrono::year_month_day(),
              description,
              std::map<Character*, CharacterRole>());
    ASSERT_EQ(description, book.GetDescription());
}

TEST(book_tests, test_get_characters) {
    Character character("Woland", "evil character");

    std::map<Character*, CharacterRole> characters;
    characters[&character] = CharacterRole::MAIN;

    Book book("",
              std::vector<Author>(),
              0,
              std::chrono::year_month_day(),
              "",
              characters);
    ASSERT_EQ(characters, book.GetCharacters());
}