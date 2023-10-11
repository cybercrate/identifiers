#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, invalid_identifier_group_count) {
    EXPECT_THROW(Identifier{"B0"}, InvalidIdentifier);
}
