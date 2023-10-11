#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, invalid_first_char_identifier_1) {
    EXPECT_THROW(Identifier("D1"), InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_2) {
    EXPECT_THROW(Identifier("F1"), InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_3) {
    EXPECT_THROW(Identifier("G1"), InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_4) {
    EXPECT_THROW(Identifier("J1"), InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_5) {
    EXPECT_THROW(Identifier{"M1"}, InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_6) {
    EXPECT_THROW(Identifier{"Q1"}, InvalidIdentifier);
}

TEST(identifiers, invalid_first_char_identifier_7) {
    EXPECT_THROW(Identifier{"V1"}, InvalidIdentifier);
}
