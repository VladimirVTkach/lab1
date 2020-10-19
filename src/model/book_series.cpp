#include "book_series.h"

BookSeries::BookSeries() {}

/** Adds new book to the series
 * @param book book to add
 * */
void BookSeries::AddBook(Book &book) {
    auto book_characters = book.GetCharacters();
    for (auto entry : book_characters) {
        auto character_ptr = entry.first;
        if (series_.contains(character_ptr)) {
            series_[character_ptr].insert(&book);
        }
    }
}

/** Removes book from the series
 * @param book book to remove
 * */
void BookSeries::RemoveBook(Book &book) {
    auto book_characters = book.GetCharacters();
    for (auto entry : book_characters) {
        auto character_ptr = entry.first;
        if (series_.contains(character_ptr)) {
            series_[character_ptr].erase(&book);
        }
    }
}

/** @return books that are in one series */
const std::set<Book *> BookSeries::GetBooksByCharacter(Character *character) {
    return series_[character];
}

/** @return all series of books */
const std::map<Character *, std::set<Book *>> BookSeries::GetAllSeries() {
    return series_;
}
