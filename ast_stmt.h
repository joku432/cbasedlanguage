#ifndef CBASED_AST_STMT_H
#define CBASED_AST_STMT_H
#include "ast.h"

namespace frontend {
namespace ast {

    class stmt : public ast_node {
    public:
        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };

    class function_def : public stmt {
    private:
        std::string name;
        std::vector<std::string> args;
        std::vector<std::unique_ptr<stmt>> stmts;
    public:
        function_def(const std::string& name,
                     const std::vector<std::string>& args,
                     const std::vector<std::unique_ptr<stmt>>& stmts)
                    : mname(name), margs(args), mstmts(std::move(stmts)){}

        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };
}
}


#endif //CBASED_AST_STMT_H
