#include <iostream>
#include <string>
#include <chrono>
#include "book.h"

int main() {
    Author author("Victor",
                  "Pelevin",
                  std::chrono::year_month_day(std::chrono::year(2020),
                                              std::chrono::month(9),
                                              std::chrono::day(15)));
    std::vector<Author> authors;
    authors.push_back(author);

    Book book("Generation P",
              authors,
              322,
              std::chrono::year_month_day(std::chrono::year(2020),
                                          std::chrono::month(9),
                                          std::chrono::day(15)),
              "description");

    std::cout << book.get_name() << std::endl;
    return 0;
}
