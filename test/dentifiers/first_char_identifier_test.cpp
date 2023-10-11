#include "base.h"

#include <identifiers/exceptions/identifier_except.h>
#include <identifiers/identifier.h>
#include <gtest/gtest.h>

TEST(identifiers, first_char_identifier) {
    for (auto i = 'A'; i <= 'Z'; ++i) {
        try {
            std::stringstream ss;
            ss << i << '9';

            Identifier id{ss.str()};
            id.increase();

            auto value = id.getValue();

            EXPECT_FALSE(TestInstance::isDeniedChar(i));
            EXPECT_EQ('1', value[1]);
        } catch (InvalidIdentifier&) {
            EXPECT_TRUE(TestInstance::isDeniedChar(i));
        }
    }
}
