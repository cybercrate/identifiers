#include "identifiers/identifier_group.h"
#include "identifiers/exceptions/identifier_except.h"

#include <sstream>

IdentifierGroup::IdentifierGroup(const std::string& value, char separator)
    : separator_{separator}, mutexPtr_{std::make_shared<std::recursive_mutex>()}
{
    std::size_t begin{};
    std::size_t end = value.find(separator_, begin);

    while (end != std::string::npos) {
        groups_.emplace_back(value.substr(begin, end - begin));

        begin = end + 1;
        end = value.find(separator_, begin);
    }
    groups_.emplace_back(value.substr(begin));

    if (groups_.size() > groupLimit()) {
        throw InvalidIdentifier("too many groups in Identifier.");
    }
}

void IdentifierGroup::increase() {
    std::unique_lock lock{*mutexPtr_};

    auto it = groups_.rbegin();
    auto end = groups_.rend();

    for (; end != it; ++it) {
        auto& group = *it;
        group.increase();

        if (group.getValue() != Identifier::defaultInit()) {
            break;
        }
    }
    if (it == groups_.rend()) {
        addNew();
    }
}

std::string IdentifierGroup::getValue() const {
    std::unique_lock lock{*mutexPtr_};

    std::stringstream ss;

    auto it = groups_.begin();
    auto end = groups_.end();

    // identifier_groups_ always contains at least one group.
    while (true) {
        ss << it->getValue();
        ++it;

        if (it == end) {
            break;
        }
        ss << separator_;
    }
    return ss.str();
}

void IdentifierGroup::addNew() {
    std::unique_lock lock{*mutexPtr_};

    // First group was incremented.
    if (groups_.front().getValue() != Identifier::defaultInit()) {
        return;
    }
    // Add a new group to the beginning of the sequence.
    if (groups_.size() < groupLimit()) {
        groups_.emplace_front(Identifier::defaultInit());
    } else {
        throw EndOfSequence{};
    }
}

constexpr std::size_t IdentifierGroup::groupLimit() {
    return 10;
}
