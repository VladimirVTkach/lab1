#include "book_series.h"

BookSeries::BookSeries() {}

/** Adds new book to the series
 * @param book book to add
 * */
void BookSeries::AddBook(Character *character, Book *book) {
    if (!character->GetMentions().contains(book)) {
        throw std::runtime_error("character is not mentioned in specified book.");
    }

    series_[character].insert(book);
}

/** Removes book from the series
 * @param book book to remove
 * */
void BookSeries::RemoveBook(Character *character, Book *book) {
    if(!series_.contains(character)) {
        throw std::runtime_error("character doesn't belong to any series");
    }

    series_[character].erase(book);
}

/** @return books that are in one series */
const std::set<Book *> &BookSeries::GetBooksByCharacter(Character *character) {
    return series_[character];
}

/** @return all series of books */
const std::map<Character *, std::set<Book *>> &BookSeries::GetAllSeries() {
    return series_;
}
