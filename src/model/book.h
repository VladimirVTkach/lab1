#pragma once

#include <vector>
#include <map>
#include "author.h"
#include "character.h"

/** Enum representing possible character roles in book */
enum CharacterRole {
    MAIN, SECONDARY
};

/** Class representing book */
class Book {
public:
    Book();

    /** Constructs Book instance with specified field's values
     * @param name book's name
     * @param authors list of book authors
     * @param pages count of pages in book
     * @param release_date book's release date
     * @param description book's short description
     * @param characters book's characters each stored with key corresponding to their roles
     * */
    Book(const std::string &name,
         const std::vector<Author> &authors,
         int pages,
         const std::chrono::year_month_day &release_date,
         const std::string &description,
         const std::map<CharacterRole, std::vector<Character>> &characters);

    /** @return book's name */
    const std::string &GetName() const;

    /** @return list of book authors */
    const std::vector<Author> &GetAuthors() const;

    /** @return count of pages in book */
    int GetPages() const;

    /** @return book's release date */
    const std::chrono::year_month_day &GetReleaseDate() const;

    /** @return book's short description */
    const std::string &GetDescription() const;

    /** @return book's characters each stored with key corresponding to their roles */
    const std::map<CharacterRole, std::vector<Character>> &GetCharacters() const;

    /** Compares for equality this instance to other Book instance.
     * If instances are equal returns true, otherwise false.
     * @param rhs instance of Book to compare this instance to
     * @return comparison result
     * */
    bool operator==(const Book &rhs) const;

    /** Compares for inequality this instance to other Book instance.
     * If instances are not equal returns true, otherwise false.
     * @param rhs instance of Book to compare this instance to
     * @return comparison result
     * */
    bool operator!=(const Book &rhs) const;

    /** Compares the relative order of this instance to other Book instance.
     * If this instances is less then other instance returns true, otherwise false.
     * @param rhs instance of Book to compare this instance to
     * @return comparison result
     * */
    bool operator<(const Book &rhs) const;

    /** Compares the relative order of this instance to other Book instance.
     * If this instances is greater then other instance returns true, otherwise false.
     * @param rhs instance of Book to compare this instance to
     * @return comparison result
     * */
    bool operator>(const Book &rhs) const;

    /** Compares the relative order of this instance to other Book instance.
     * If this instances is less than or equals to other instance returns true, otherwise false.
     * @param rhs instance of Book to compare this instance to
     * @return comparison result
     * */
    bool operator<=(const Book &rhs) const;

    /** Compares the relative order of this instance to other Book instance.
    * If this instances is greater than or equals to other instance returns true, otherwise false.
    * @param rhs instance of Book to compare this instance to
    * @return comparison result
    * */
    bool operator>=(const Book &rhs) const;

private:
    std::string name_;
    std::vector<Author> authors_;
    int pages_;
    std::chrono::year_month_day release_date_;
    std::string description_;
    std::map<CharacterRole, std::vector<Character>> characters_;
};
