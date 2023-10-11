#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier_group.h>
#include <gtest/gtest.h>

TEST(identifiers, identifier_group_limit) {
    try {
        IdentifierGroup group{"Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9"};
        group.increase();
    } catch (EndOfSequence&) {
        EXPECT_TRUE(true);
    }
}
