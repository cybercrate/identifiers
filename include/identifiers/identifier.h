#ifndef WINGMANN_IDENTIFIERS_IDENTIFIER_H
#define WINGMANN_IDENTIFIERS_IDENTIFIER_H

#include "identifier_group.h"

#include <memory>
#include <mutex>
#include <string>

class Identifier {
    // Identifier value.
    std::string value_;

    // Shared mutex.
    std::shared_ptr<std::recursive_mutex> mutexPtr_;

public:
    /**
     * @brief Constructs Identifier from value
     * @param value A value for initialize Identifier.
     */
    explicit Identifier(std::string value);

public:
    /**
     * @brief Increments current sequence expression.
     */
    void increase();

    /**
     * @brief Gets a string with the beginning of the sequence.
     * @return Beginning of the sequence.
     */
    static std::string defaultInit();

    /**
     * @brief @brief Gets the current value of Identifier.
     * @return @return Current Identifier.
     */
    [[nodiscard]]
    const std::string& getValue() const;

private:
    // Checks if the length of the Identifier is correct.
    void checkLength();

    // Checks if the first char of the Identifier is correct.
    void checkFirst();

    // Checks if the last char of the Identifier is correct.
    void checkLast();

    // Checks if the first symbol is allowed.
    static bool isValidFirst(char first);

    // Checks if the last symbol is allowed.
    static bool isValidLast(char last);

    // Increments the first symbol of Identifier.
    void increaseFirst();

    // Increments the last symbol of Identifier.
    bool increaseLast();
};

#endif // WINGMANN_IDENTIFIERS_IDENTIFIER_H
