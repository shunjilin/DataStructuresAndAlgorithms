#ifndef STACK_WITH_MAX_HPP
#define STACK_WITH_MAX_HPP

#include <stack>
#include <stdexcept>

template<typename T>
class StackWithMax {
private:
    std::stack<T> stack;
    std::stack<T> max_stack;

public:
    void push(T element) {
        stack.push(element);
        if (!max_stack.empty() && max_stack.top() > element) {
            max_stack.push(max_stack.top());
        } else {
            max_stack.push(element);
        }
    }
    T const & max() const {
        if (max_stack.empty())
            throw std::out_of_range("calling max with empty stack");
        return max_stack.top();
    }
    void pop() {
        stack.pop();
        max_stack.pop();
    }
};

#endif
