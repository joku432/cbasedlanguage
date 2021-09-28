#include "ir_converter.h"
#include "bytecode.h"

using namespace frontend;

class ir_converter::impl {
private:
    std::vector<std::unique_ptr<bytecode>> ir;

public:
    bool convert(const std::vector<std::string>& ast) {
        for (const auto& node : ast) {
        }
    }

};

ir_converter::ir_converter() {
    pImpl = std::make_unique<impl>();
}

bool ir_converter::convert(std::vector<std::string> ast) {
    return pImpl->convert(ast);
}