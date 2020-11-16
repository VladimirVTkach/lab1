#include <gtest/gtest.h>
#include "../../src/model/book.h"
#include "../../src/model/character.h"

TEST(character_tests, test_get_name) {
    std::string name = "Woland";
    Character character(name,
                        "");
    ASSERT_EQ(name, character.GetName());
}


TEST(character_tests, test_get_biography) {
    std::string biography = "Evil character";
    Character character("",
                        biography);
    ASSERT_EQ(biography, character.GetBiography());
}

TEST(character_tests, test_add_mention) {
    Character character("Woland",
                        "evil");

    Book *book = new Book();
    character.AddMention(book, CharacterRole::MAIN);

    ASSERT_TRUE(character.GetMentions().contains(book));
}

TEST(character_tests, test_get_mention) {
    Character character("Woland",
                        "evil");

    Book *book = new Book();
    character.AddMention(book, CharacterRole::MAIN);

    ASSERT_TRUE(character.GetMentions().contains(book));
    ASSERT_TRUE(character.GetMentions().at(book) == CharacterRole::MAIN);
}