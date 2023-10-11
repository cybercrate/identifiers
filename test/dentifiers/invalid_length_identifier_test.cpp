#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, invalid_length_identifier) {
    EXPECT_THROW(Identifier{"A"}, InvalidIdentifier);
    EXPECT_THROW(Identifier{"A11"}, InvalidIdentifier);
}
