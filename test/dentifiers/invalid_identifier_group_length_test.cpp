#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier_group.h>
#include <gtest/gtest.h>

TEST(identifiers, invalid_identifier_group_length_1) {
    EXPECT_THROW(IdentifierGroup{"A"}, InvalidIdentifier);
}

TEST(identifiers, invalid_identifier_group_length_2) {
    EXPECT_THROW(IdentifierGroup{"A11"}, InvalidIdentifier);
}

TEST(identifiers, invalid_identifier_group_length_3) {
    EXPECT_THROW(IdentifierGroup{"A1-A1-A1-A1-A1-A1-A1-A1-A1-A1-A1"}, InvalidIdentifier);
}
