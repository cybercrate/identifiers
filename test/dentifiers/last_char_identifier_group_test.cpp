#include <identifiers/identifier_group.h>
#include <gtest/gtest.h>

TEST(identifiers, last_char_identifier_group) {
    IdentifierGroup group{"A1"};

    EXPECT_EQ("A1", group.getValue());

    for (int i = 2; i <= 9; ++i) {
        group.increase();

        std::stringstream ss;
        ss << 'A' << i;

        EXPECT_EQ(ss.str(), group.getValue());
    }
    EXPECT_EQ("A9", group.getValue());

    group.increase();
    EXPECT_EQ("B1", group.getValue());
}
