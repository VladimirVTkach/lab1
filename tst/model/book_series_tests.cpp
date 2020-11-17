#include <gtest/gtest.h>
#include "../../src/model/book.h"
#include "../../src/model/character.h"
#include "../../src/model/book_series.h"

TEST(book_series_test, test_add_book) {
    BookSeries book_series;

    Book master_and_margharita("Master and Margarita",
                               std::vector<Author>(),
                               212,
                               std::chrono::year_month_day(),
                               "interesting book");

    Character woland("Woland", "evil character");
    woland.AddMention(&master_and_margharita, CharacterRole::MAIN);

    book_series.AddBook(&woland, &master_and_margharita);

    ASSERT_TRUE(book_series.GetAllSeries().at(&woland).contains(&master_and_margharita));
}

TEST(book_series_test, test_remove_book) {
    BookSeries book_series;

    Book master_and_margharita("Master and Margarita",
                               std::vector<Author>(),
                               212,
                               std::chrono::year_month_day(),
                               "interesting book");

    Character woland("Woland", "evil character");
    woland.AddMention(&master_and_margharita, CharacterRole::MAIN);

    book_series.AddBook(&woland, &master_and_margharita);
    ASSERT_TRUE(book_series.GetAllSeries().at(&woland).contains(&master_and_margharita));

    book_series.RemoveBook(&woland, &master_and_margharita);
    ASSERT_FALSE(book_series.GetAllSeries().at(&woland).contains(&master_and_margharita));
}

TEST(book_series_test, test_get_books_by_character) {
    BookSeries book_series;

    Book harry_potter_and_philosophy_stone("Harry Potter and philosophy stone",
                                           std::vector<Author>(),
                                           212,
                                           std::chrono::year_month_day(),
                                           "first book in a series");

    Book harry_potter_and_chamber_secret("Harry Potter and the chamber secret",
                                         std::vector<Author>(),
                                         212,
                                         std::chrono::year_month_day(),
                                         "second book in a series");

    Character harry_potter("Harry Potter", "bio");
    harry_potter.AddMention(&harry_potter_and_philosophy_stone, CharacterRole::MAIN);
    harry_potter.AddMention(&harry_potter_and_chamber_secret, CharacterRole::MAIN);

    book_series.AddBook(&harry_potter, &harry_potter_and_philosophy_stone);
    book_series.AddBook(&harry_potter, &harry_potter_and_chamber_secret);

    std::set<Book*> harry_potter_books = book_series.GetBooksByCharacter(&harry_potter);
    ASSERT_TRUE(harry_potter_books.contains(&harry_potter_and_philosophy_stone));
    ASSERT_TRUE(harry_potter_books.contains(&harry_potter_and_chamber_secret));
}