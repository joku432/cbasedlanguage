#include "lexer.h"
#include "logger.h"

std::vector<std::unique_ptr<Token>> Lexer::tokenize(const std::string& file) {
    mCurLocation = Location(file, 0, 0);
    std::vector<std::unique_ptr<Token>> tokens;

    while (1) {
        if (isalpha(mCurrentChar)) {
            tokens.push_back(make_ident());
        } else if (isdigit(mCurrentChar)) {
            tokens.push_back(make_number());
        } else {

        }
    }

    return tokens;
}


std::unique_ptr<Token> Lexer::make_ident() {
    std::string value;
    Location startLocation = mCurLocation;
    while (isalnum(mCurrentChar) || mCurrentChar == '_') {
        value += mCurrentChar;
        nextChar();
    }

    if (value == "function") {
        return std::make_unique<Token>(startLocation, TokenType::FUNCTION);
    } else if (value == "var") {
        return std::make_unique<Token>(startLocation, TokenType::VAR);
    } else if (value == "if") {
        return std::make_unique<Token>(startLocation, TokenType::IF);
    } else if (value == "elif") {
        return std::make_unique<Token>(startLocation, TokenType::ELIF);
    } else if (value == "else") {
        return std::make_unique<Token>(startLocation, TokenType::ELSE);
    } else if (value == "for") {
        return std::make_unique<Token>(startLocation, TokenType::FOR);
    } else if (value == "while") {
        return std::make_unique<Token>(startLocation, TokenType::WHILE);
    } else if (value == "class") {
        return std::make_unique<Token>(startLocation, TokenType::CLASS);
    }
    return std::make_unique<Token>(startLocation, TokenType::IDENT, value);
}

std::unique_ptr<Token> Lexer::make_number() {
    std::string value;
    Location startLocation = mCurLocation;
    bool gotComma = false;
    while (isdigit(mCurrentChar)) {
        value += mCurrentChar;
        nextChar();
        if (mCurrentChar == ',' && gotComma) {
            logger::error(error_type::SYNTAX_ERROR,
                          "Unexpected ',' in floating point number\n",
                          startLocation);
            break;
        } else if (mCurrentChar == ',' && !gotComma) {
            gotComma = true;
            nextChar();
        }
    }

    return std::make_unique<Token>(startLocation, TokenType::NUMBER, value);
}
std::unique_ptr<Token> Lexer::make_other() {

}

