//
// Created by Arek on 16.04.2023.
//
#include <iostream>
#include "Stack.h"
#include "checking_policy.h"

int main() {
    std::cout << std::boolalpha;
//    Stack<int, 5, Abort_on_error_policy> stack(5);
    Stack<int, 5, No_checking_policy> stack(5);

    std::cout << "Is stack empty? " << stack.is_empty() << std::endl;

    stack.push(1);
    std::cout << "Pushed 1 onto stack." << std::endl;

    stack.push(2);
    std::cout << "Pushed 2 onto stack." << std::endl;

    stack.push(3);
    std::cout << "Pushed 3 onto stack." << std::endl;

    std::cout << "Top of stack is " << stack.top() << std::endl;

    stack.push(4);
    std::cout << "Pushed 4 onto stack." << std::endl;

    stack.push(5);
    std::cout << "Pushed 5 onto stack." << std::endl;

    std::cout << "Is stack empty? " << stack.is_empty() << std::endl;

    std::cout << "Top of stack is " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Popped top of stack." << std::endl;

    std::cout << "Top of stack is " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Popped top of stack." << std::endl;

    std::cout << "Top of stack is " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Popped top of stack." << std::endl;

    std::cout << "Is stack empty? " << stack.is_empty() << std::endl;

    stack.pop();
    std::cout << "Popped top of stack." << std::endl;

    std::cout << "Top of stack is " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Popped top of stack." << std::endl;

    std::cout << "Is stack empty? " << stack.is_empty() << std::endl;

    std::cout << "Trying to pop an empty stack should cause the program to abort if Abort_on_error_policy is used"<< std::endl;
    stack.pop();
    std::cout<<"...";
    return 0;

}
