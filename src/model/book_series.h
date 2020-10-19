#pragma once

#include "character.h"
#include "book.h"
#include <map>
#include <set>

class BookSeries {
public:
    BookSeries();
    void AddBook(Book &book);
    void RemoveBook(Book &book);
    const std::set<Book*> GetBooksByCharacter(Character* character);
    const std::map<Character*, std::set<Book*>> GetAllSeries();
private:
    std::map<Character*, std::set<Book*>> series_;
};
