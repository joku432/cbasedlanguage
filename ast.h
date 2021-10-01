#ifndef CBASED_AST_H
#define CBASED_AST_H
#include "visitor.h"
#include <vector>
#include <cassert>
#include <memory>

namespace frontend {
namespace ast {
    class ast_node : public visitable {
    public:
        ast_node();
        virtual void accept(const ast_visitor& v) = 0;
    };
}
}


#endif //CBASED_AST_H
