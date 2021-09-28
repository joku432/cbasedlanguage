#ifndef CBASED_TOKEN_H
#define CBASED_TOKEN_H

#include <string>
#include "location.h"

enum class TokenType {
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

    bool operator==(TokenType otherTokenType) {
        return otherTokenType == mTokenType;
    }

};



#endif //CBASED_TOKEN_H
