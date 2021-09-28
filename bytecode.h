#ifndef CBASED_BYTECODE_H
#define CBASED_BYTECODE_H

#include "visitor.h"

namespace frontend {


class visitor;

/**
 * Type of a bytecode node.
 */
enum class bytecode_type {

};

/**
 * Low level representation before final target code.
 * AST->bytecode->target code
 */
class bytecode : public visitable {
public:
    bytecode();
    virtual void accept(const visitor& v) override {}
};

class number_ir : public bytecode {
public:
    void accept(const visitor& v) override {

    }
private:
    size_t size;
};

/**
 * Call expression
 */
class call_ir : public bytecode {
public:
    void accept(const visitor& v) override {

    }

};


}


#endif //CBASED_BYTECODE_H
