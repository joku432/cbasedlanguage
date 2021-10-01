#ifndef CBASED_LEXER_H
#define CBASED_LEXER_H

#include <memory>
#include <vector>
#include <fstream>
#include "token.h"

class Lexer {
private:
    char mCurrentChar;
    int mCurPos;
    Location mCurLocation;
    std::ifstream mFile;

public:
    Lexer();
    std::vector<std::unique_ptr<Token>> tokenize(const std::string& file);

private:
    std::unique_ptr<Token> make_ident();
    std::unique_ptr<Token> make_number();
    std::unique_ptr<Token> make_other();
    void nextChar() {
        if (mFile.)
        mCurLocation.col++;
    }


    inline void peek() {

    }


};


#endif //CBASED_LEXER_H
