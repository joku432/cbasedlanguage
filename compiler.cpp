#include "compiler.h"

struct ext_c_compiler {
    virtual std::string command(const std::string& os) = 0;
};

struct gcc_settings : public ext_c_compiler {
    // path to gcc compiler
    std::string path;
    // the level of optimization to apply
    int optimization_lvl;

    std::string command(const std::string& os) override {
        assert(optimization_lvl >= 0 && optimization_lvl )
        if (os == "linux") {
            path = "/usr/bin/gcc";
        } else if (os == "windows") {

        }
        return path + " -O" + std::to_string(optimization_lvl);
    }
};


void compiler::compile(const std::string& file, const std::string& destination = "") {


}