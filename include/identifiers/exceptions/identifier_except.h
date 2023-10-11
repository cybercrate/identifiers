#ifndef WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPT_H
#define WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPT_H

#include <stdexcept>

class IdentifierException : public std::runtime_error {
public:
    explicit IdentifierException(const std::string& message) : std::runtime_error{message} {}
};

class InvalidIdentifier : public IdentifierException {
public:
    explicit InvalidIdentifier(const std::string& message) : IdentifierException{message} {}
};

class EndOfSequence : public IdentifierException {
public:
    EndOfSequence() : IdentifierException{"end of sequence reached"} {}
};

#endif // WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPT_H
