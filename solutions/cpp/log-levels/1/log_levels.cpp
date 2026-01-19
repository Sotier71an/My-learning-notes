#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    int left = line.find(":") + 2;
    std::string substring = line.substr(line.find("\"") + 1);
    int right = substring.find("\"") + 1;
    int length = right - left + 1;
    std::string message = line.substr(left, length);
    return message;
}

std::string log_level(std::string line) {
    // return the log level
    int left = line.find("[") + 1;
    int right = line.find("]") - 1;
    int length = right - left + 1;
    std::string log_level = line.substr(left, length);
    return log_level;
}

std::string reformat(std::string line) {
    // return the reformatted message
    std::string refomated_str = message(line) + " (" + log_level(line) + ")";
    return refomated_str;
}
}  // namespace log_line
