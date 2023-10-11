#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, invalid_last_char_identifier_1) {
    EXPECT_THROW(Identifier{"A0"}, InvalidIdentifier);
}

TEST(identifiers, invalid_last_char_identifier_2) {
    EXPECT_THROW(Identifier{"A11"}, InvalidIdentifier);
}