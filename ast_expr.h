#ifndef CBASED_AST_EXPR_H
#define CBASED_AST_EXPR_H

#include "ast.h"


namespace frontend {
namespace ast {

    class expr : public ast_node {
    public:
        expr() {}
        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };

    class number : public ast_node {
    private:
        std::string mvalue;
    public:
        number(const std::string& value)
        : mvalue(value) {}
        const inline std::string value() const { return mvalue; }
        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };

    class ident_expr : public ast_node {
    private:
        std::string mname;
    public:
        ident_expr(const std::string& name)
        : mname(name) {}

        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };

    class function_call : public ast_node {
    private:
        std::string mname;
        std::vector<std::unique_ptr<expr>> margs;
    public:
        function_call(const std::string& name,
                      const std::vector<std::unique_ptr<expr>>& args)
                      : mname(name),
                      margs(std::move(args)) {}

        const inline std::string name() const { return mname; }
        const std::vector<std::unique_ptr<expr>>& args() const { return margs; }
        const expr *get_raw_arg(int index) const {
            assert(index <= margs.size());
            return margs[index].get();
        }
        void accept(const ast_visitor& v) override {
            v.visit(*this);
        }
    };

}
}



#endif //CBASED_AST_EXPR_H
