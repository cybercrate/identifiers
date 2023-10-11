#include "base.h"

#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, firsts_char_single_identifier_group) {
    for (auto i = 'A'; 'Z' >= i; ++i) {
        try {
            std::stringstream ss;
            ss << i << '9';

            Identifier id{ss.str()};
            id.increase();

            auto str = id.getValue();

            EXPECT_FALSE(test_instance::is_denied_char(i));
            EXPECT_EQ('1', str[1]);
        } catch (InvalidIdentifier&) {
            EXPECT_TRUE(test_instance::is_denied_char(i));
        }
    }
    Identifier id{"Z9"};
    EXPECT_EQ("Z9", id.get_value());

    id.increase();
    EXPECT_EQ("A1", id.get_value());
}
