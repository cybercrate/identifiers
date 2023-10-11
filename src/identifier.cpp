#include "identifiers/identifier.h"
#include "identifiers/exceptions/identifier_except.h"

#include <algorithm>
#include <sstream>
#include <utility>

Identifier::Identifier(std::string value)
    : value_{std::move(value)},
      mutexPtr_{std::make_shared<std::recursive_mutex>()}
{
    checkLength();
    checkFirst();
    checkLast();
}

void Identifier::increase() {
    if (increaseLast()) {
        increaseFirst();
    }
}

std::string Identifier::defaultInit() {
    return "A1";
}

const std::string& Identifier::getValue() const {
    std::unique_lock lock{*mutexPtr_};
    return value_;
}

void Identifier::checkLength() {
    std::unique_lock lock{*mutexPtr_};

    if (value_.length() == 2) {
        return;
    }
    std::stringstream ss;
    ss << "Identifier group " << value_ << " has invalid length.";

    throw InvalidIdentifier{ss.str()};
}

void Identifier::checkFirst() {
    std::unique_lock lock{*mutexPtr_};

    if (isValidFirst(value_[0])) {
        return;
    }
    std::stringstream ss;
    ss << "Identifier group " << value_ << " has invalid letter";

    throw InvalidIdentifier{ss.str()};
}

void Identifier::checkLast() {
    std::unique_lock lock{*mutexPtr_};

    if (isValidLast(value_[1])) {
        return;
    }
    std::stringstream ss;
    ss << "Identifier group " << value_ << " has invalid number";

    throw InvalidIdentifier{ss.str()};
}

bool Identifier::isValidFirst(char first) {
    std::string deniedLetters{"DFGJMQV0"};
    auto upper = static_cast<char>(std::toupper(first));

    return std::all_of(deniedLetters.begin(), deniedLetters.end(), [upper](const char c) {
        return (upper >= 'A') && (upper <= 'Z') && (upper != c);
    });
}

bool Identifier::isValidLast(char last) {
    return ('1' <= last) && ('9' >= last);
}

void Identifier::increaseFirst() {
    std::unique_lock lock{*mutexPtr_};

    auto& letter = value_[0];
    ++letter;

    while (!isValidFirst(letter)) {
        ++letter;
        if ('Z' < letter) {
            letter = 'A';
        }
    }
}

bool Identifier::increaseLast() {
    std::unique_lock lock{*mutexPtr_};

    auto& number = value_[1];
    ++number;

    bool result = '9' < number;
    if (result) {
        number = '1';
    }
    return result;
}
