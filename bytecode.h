#ifndef CBASED_BYTECODE_H
#define CBASED_BYTECODE_H

#include "visitor.h"
#include <cstdint>

namespace frontend {


class visitor;

/**
 * Type of a bytecode node.
 */
enum class bytecode_type {
    ADD,
    SUB,
    MUL,
    DIV,
    ASSIGN,
    CALL,
    RET,
    LOOP,
    IF
};

/**
 * Low level representation before final target code.
 * AST->bytecode->target code
 */
class bytecode : public visitable {
public:
    bytecode();
    virtual void accept(const bytecode_visitor& v) override {}
};

class number_ir : public bytecode {
public:
    int64_t value;
    size_t size;
    void accept(const bytecode_visitor& v) override {
        v.visit(*this);
    }
};

class add_instr : public bytecode {
private:
    std::unique_ptr<number_ir> m_num1;
    std::unique_ptr<number_ir> m_num2;
public:
    add_instr(std::unique_ptr<number_ir> num1,
              std::unique_ptr<number_ir> num2)
              : m_num1(std::move(num1)),
              m_num2(std::move(num2)) {}

    void accept(const bytecode_visitor& v) override {
        v.visit(*this);
    }
};

class sub_instr : public bytecode {
private:
    std::unique_ptr<number_ir> m_num1;
    std::unique_ptr<number_ir> m_num2;
public:
    sub_instr(std::unique_ptr<number_ir> num1,
              std::unique_ptr<number_ir> num2)
              : m_num1(std::move(num1)),
              m_num2(std::move(num2)) {}

    void accept(const bytecode_visitor& v) override {
        v.visit(*this);
    }
};

class mul_instr : public bytecode {
private:
    std::unique_ptr<number_ir> m_num1;
    std::unique_ptr<number_ir> m_num2;
public:
    mul_instr(std::unique_ptr<number_ir> num1,
              std::unique_ptr<number_ir> num2)
              : m_num1(std::move(num1)),
              m_num2(std::move(num2)) {}

    void accept(const bytecode_visitor& v) override {
        v.visit(*this);
    }
};

class div_instr : public bytecode {
private:
    std::unique_ptr<number_ir> m_num1;
    std::unique_ptr<number_ir> m_num2;
public:
    div_instr(std::unique_ptr<number_ir> num1,
            std::unique_ptr<number_ir> num2)
            : m_num1(std::move(num1)),
              m_num2(std::move(num2)) {}

    void accept(const bytecode_visitor& v) override {
        v.visit(*this);
    }
};








}


#endif //CBASED_BYTECODE_H
