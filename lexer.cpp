#include "lexer.h"


std::vector<std::unique_ptr<Token>> Lexer::make_tokens(const std::string& file) {
    mCurLocation = Location(file, 0, 0);
    std::vector<std::unique_ptr<Token>> tokens;

    while (1) {

    }

}


