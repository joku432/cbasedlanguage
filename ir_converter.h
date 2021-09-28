#ifndef CBASED_IR_CONVERTER_H
#define CBASED_IR_CONVERTER_H

#include <memory>
#include <vector>
#include <string>


namespace frontend {

/**
 * Handles the conversion from
 * AST to a lower level intermediate language.
 * Uses "pimpl"-idiom to hide implementation in source file.
 */
class ir_converter {
private:
    class impl;
    std::unique_ptr<impl> pImpl;
public:
    ir_converter();

    /**
     * Converts a typechecked high level AST
     * to a lower level representation
     * @param ast AST (abstract syntax tree)
     */
     bool convert(std::vector<std::string> ast);

    /**
     * Loads ir from file.
     * @param filePath path of the ir file
     */
    void load_from_file(const std::string& filePath);
};

}


#endif //CBASED_IR_CONVERTER_H
