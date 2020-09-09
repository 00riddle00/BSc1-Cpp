
// prevent multiple inclusions of header file
#ifndef NAMESPACE_2
#define NAMESPACE_2

namespace Namespace {

class IncorrectTimeException : public std::range_error {
    const std::string function_name;
    public:
        IncorrectTimeException(const std::string& re, const std::string &fn = " ");
        std::string getFunctionName();
};

}

#endif

