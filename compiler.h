#ifndef CBASED_COMPILER_H
#define CBASED_COMPILER_H

#include <string>

enum class log_level {
    DEBUG,
    SUPRESS
};

enum class optimization_level {
    NOTHING,
    DEBUG,
    RELEASE
};

struct compiler_settings {
    std::string        target;
    log_level          log_level;
    optimization_level optimization_level;
    bool               warn_unused_variables;
};

class compiler {
private:
    compiler_settings settings;

public:
    void compile(const std::string& file, 
            const std::string& destination = "");

    void set_target(const std::string& target) {
        settings.target = target;
    }

    void set_log_level(log_level level) {
        settings.log_level = level;
    }

    void set_optimization_level(optimization_level level) {
        settings.optimization_level = level;
    }
};



#endif