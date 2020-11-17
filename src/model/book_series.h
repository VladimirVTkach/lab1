#pragma once

#include "character.h"
#include "book.h"
#include <map>
#include <set>

class BookSeries {
public:
    BookSeries();

    void AddBook(Character *character, Book *book);

    void RemoveBook(Character *character, Book *book);

    const std::set<Book *> &GetBooksByCharacter(Character *character);

    const std::map<Character *, std::set<Book *>> &GetAllSeries();

private:
    std::map<Character *, std::set<Book *>> series_;
};
