#ifndef WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H
#define WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H

#include "identifier.h"

#include <list>
#include <memory>
#include <mutex>
#include <string>

class Identifier;

class IdentifierGroup {
private:
    // Group list.
    std::list<Identifier> groups_;

    // Group separator.
    char separator_;

    // Shared mutex.
    std::shared_ptr<std::recursive_mutex> mutexPtr_;

public:
    /**
     * @brief Constructs Identifier group from existent sequence.
     *
     * @param value The initial Identifier sequence.
     * @param separator A separator between identifiers.
     */
    explicit IdentifierGroup(const std::string& value, char separator = '-');

public:
    /**
     * @brief Increments current sequence expression.
     */
    void increase();

    /**
     * @brief Returns current value of Identifier sequence.
     * @return Current Identifier group.
     */
    [[nodiscard]]
    std::string getValue() const;

private:
    // Add a new group to the top of the list.
    void addNew();

    // Maximum number of groups in Identifier.
    static constexpr std::size_t groupLimit();
};

#endif // WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H
