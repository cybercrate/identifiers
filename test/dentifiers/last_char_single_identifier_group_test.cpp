#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, last_char_single_identifier_group) {
    IdentifierGroup group{"A1"};

    EXPECT_EQ("A1", group.get_value());

    for (int i = 2; 9 >= i; ++i) {
        group.increase();

        std::stringstream ss;
        ss << 'A' << i;

        EXPECT_EQ(ss.str(), group.get_value());
    }
    EXPECT_EQ("A9", group.get_value());

    group.increase();
    EXPECT_EQ("B1", group.get_value());
}