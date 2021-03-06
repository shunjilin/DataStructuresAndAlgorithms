#ifndef CHECK_BRACKETS_HPP
#define CHECK_BRACKETS_HPP

#include <string>
#include <vector>

struct LeftBracketInput {
    LeftBracketInput(char left_bracket, int index) :
        left_bracket(left_bracket), index(index) {}
    char left_bracket;
    int index;
};

bool isLeftBracket(char const bracket) {
    return bracket == '{' || bracket == '[' || bracket == '(';
}

bool isRightBracket(char const bracket) {
    return bracket == '}' || bracket == ']' || bracket == ')';
}

bool isMatchingBracket(char const left_bracket, char const right_bracket) {
    return (left_bracket == '{' && right_bracket == '}') ||
        (left_bracket == '[' && right_bracket == ']') ||
        (left_bracket == '(' && right_bracket == ')');
}

// takes an input string and returns "Success" if brackets are matched, and if
// not, returns string of index of the first unmatched bracket
std::string bracketChecker(std::string input) {
    std::vector<LeftBracketInput> stack;
    int index = 0;
    for (char const c: input) {
        ++index;
        if (isLeftBracket(c)) {
            stack.emplace_back(c, index);
        } else if (isRightBracket(c)) {
            if (!stack.empty() &&
                isMatchingBracket(stack.back().left_bracket, c)) {
                stack.pop_back();
            } else {
                return std::to_string(index);
            }
        }
    }

    if (!stack.empty()) {
        return std::to_string(stack.back().index);
    }
    return "Success";
}

#endif
