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

class ast_visitor : public visitor {

};

class bytecode_visitor : public visitor {

};

}









#endif //CBASED_VISITOR_H
