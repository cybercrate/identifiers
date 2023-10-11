#include <identifiers/identifier_group.h>
#include <gtest/gtest.h>

TEST(identifiers, increase_identifier_group_1) {
    IdentifierGroup group{"Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A1-A1");
}

TEST(identifiers, increase_identifier_group_2) {
    IdentifierGroup group{"A1-Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A2-A1");
}

TEST(identifiers, increase_identifier_group_3) {
    IdentifierGroup group{"A1-B1-Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A1-B2-A1");
}

TEST(identifiers, increase_identifier_group_4) {
    IdentifierGroup group{"A1-Z9-Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A2-A1-A1");
}

TEST(identifiers, increase_identifier_group_5) {
    IdentifierGroup group{"Z9-Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A1-A1-A1");
}

TEST(identifiers, increase_identifier_group_6) {
    IdentifierGroup group{"Z9-Z9-Z9"};
    group.increase();

    EXPECT_EQ(group.get_value(), "A1-A1-A1-A1");
}
