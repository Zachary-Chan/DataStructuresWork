#include <iostream>
#include <stack>
#include <string>
using std::string;
using std::stack;

int main() {
    string str {};
    std::getline(std::cin, str);

    stack<char> parenthesis {};

    for (const auto& x : str) {
        switch (x) {
        case '(':
        case '[':
        case '{':
            parenthesis.push(x);
            break;

        case ')':
            if (parenthesis.empty() || parenthesis.top() != '(' ) {
                std::cout << "no\n";
                return 0;
            }
            parenthesis.pop();
            break;

        case ']':
            if (parenthesis.empty() || parenthesis.top() != '[' ) {
                std::cout << "no\n";
                return 0;
            }
            parenthesis.pop();
            break;

        case '}':
            if (parenthesis.empty() || parenthesis.top() != '{' ) {
                std::cout << "no\n";
                return 0;
            }
            parenthesis.pop();
            break;

        default:
            continue;
        }
    }

    if (parenthesis.empty() ) {
        std::cout << "yes\n";
        return 0;
    }

    if (parenthesis.top() == '(' || parenthesis.top() == '[' ||
            parenthesis.top() == '{' ) {
        std::cout << "no\n";
        return 0;
    }

    std::cout << "yes\n";
}

