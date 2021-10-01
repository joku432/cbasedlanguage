#ifndef CBASED_VISITOR_H
#define CBASED_VISITOR_H


namespace frontend {

class visitor;

/**
 * Visitable interface,
 * nodes that wish to accept visitors
 * will implement this class
 */
class visitable {
    virtual void accept(visitor &v) = 0;
};

class visitor {
    virtual void visit(const visitable& v) {
        v.accept(*this);
    }
};

namespace ast {
    class ast_node;
    class expr;
    class number;
    class ident_expr;
    class function_call;
    class stmt;
    class function_def;

    class ast_visitor : public visitor {
        virtual void visit(const ast_node &n) = 0;
        virtual void visit(const expr &n) = 0;
        virtual void visit(const number &n) = 0;
        virtual void visit(const ident_expr &n) = 0;
        virtual void visit(const function_call &n) = 0;
        virtual void visit(const stmt &n) = 0;
        virtual void visit(const function_def &n) = 0;
    };

}

namespace ir {

    class bytecode_visitor : public visitor {

    };

}

}









#endif //CBASED_VISITOR_H
