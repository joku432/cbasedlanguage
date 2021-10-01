#ifndef CBASED_TOKEN_H
#define CBASED_TOKEN_H

#include <string>
#include "location.h"

enum class TokenType {
    FUNCTION,
    VAR,
    CONST,
    IF,
    ELIF,
    ELSE,
    FOR,
    WHILE,
    CLASS,

    IDENT,
    STRING,
    NUMBER,
    PLUS,
    MINUS,
    ASTERISK,
    SLASH
};

struct Token {
    Location mLocation;
    TokenType mTokenType;
    std::string mValue;

    Token(const Location& location, TokenType tokenType, const std::string& value)
    : mLocation(location),
    mTokenType(tokenType),
    mValue(value) {}

    Token(const Location& location, TokenType tokenType)
        : mLocation(location), mTokenType(tokenType), mValue("") {}

    bool operator==(TokenType otherTokenType) {
        return otherTokenType == mTokenType;
    }

};



#endif //CBASED_TOKEN_H
