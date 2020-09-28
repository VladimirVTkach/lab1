#include <gtest/gtest.h>
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