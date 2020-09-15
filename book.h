#include <vector>
#include "author.h"

class Book {
public:
    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description);

    const std::string &getName() const;

    const std::vector<Author> &getAuthors() const;

    int getPages() const;

    const std::chrono::year_month_day &getReleaseDate() const;

    const std::string &getDescription() const;

private:
    std::string name;
    std::vector<Author> authors;
    int pages;
    std::chrono::year_month_day release_date;
    std::string description;
};
