#include <identifiers/identifier_group.h>
#include <gtest/gtest.h>

TEST(identifiers, identifier_entry) {
    EXPECT_EQ("A1-B2-C4", [](const std::string& value) {
        IdentifierGroup group{value};
        group.increase();

        return group.getValue();
    }("A1-B2-C3"));
}
