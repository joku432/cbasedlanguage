#ifndef CBASED_LEXER_H
#define CBASED_LEXER_H

#include <memory>
#include <vector>
#include <fstream>
#include "token.h"

class Lexer {
private:
    char mCurrentChar;
    Location mCurLocation;
    std::ifstream mFile;

public:
    Lexer();
    std::vector<std::unique_ptr<Token>> make_tokens(const std::string& file);

private:
    inline void nextChar() {
        mCurLocation.col++;
    }

    inline void peek() {

    }


};


#endif //CBASED_LEXER_H
