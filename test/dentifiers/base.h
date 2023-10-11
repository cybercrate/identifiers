#ifndef TEST_BASE_H
#define TEST_BASE_H

#include <algorithm>
#include <string>

struct TestInstance {
    static bool isDeniedChar(char letter) {
        std::string denied_letters{"DFGJMQV0"};
        auto upper = static_cast<char>(std::toupper(letter));

        return std::any_of(denied_letters.begin(), denied_letters.end(), [upper](const char c) {
            return upper == c;
        });
    }
};

#endif // TEST_BASE_H
