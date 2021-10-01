#ifndef CBASED_COMPILER_H
#define CBASED_COMPILER_H
#include <vector>
#include "location.h"

enum class error_type {
    SYNTAX_ERROR,
    LOGIC_ERROR
};

enum class warning_type {
    UNUSED_VARIABLE
};

template <typename T>
struct logger_message {
    static_assert(false, "logger_message of this type not supported");
};  

template <>
struct logger_message<error_type> {
    logger_message(error_type perror, 
            const std::string& pmessage, 
            const Location& plocation,
            bool pfatal);

    error_type error;
    std::string message;
    bool fatal;
    Location location;
};

template <>
struct logger_message<warning_type> {
    logger_message();
    error_type error;
    Location location;
};

class logger {
private:
    static inline std::vector<logger_message<error_type>> errors;
    static inline std::vector<logger_message<warning_type>> warnings; 

public:
    static void error(error_type err_type, const std::string& message, Location loc, bool critical = false) {}
    static void warning(const std::string& message) {}
    static void output_logs() {}
private:

};


#endif // CBASED_COMPILER_H