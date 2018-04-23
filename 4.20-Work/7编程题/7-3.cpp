#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
using std::stack;
using std::queue;

int main() {
    char ch {};
    queue<char> queue {};
    stack<char> stk {};

    std::cin >> std::noskipws >> ch;
    while ( !std::isspace(ch) ) {
        stk.push(ch);
        queue.push(ch);

        std::cin >> ch;
    }

    while ( !stk.empty() ) {
        if (stk.top() != queue.front() ) {
            std::cout << "NO\n";
            return 0;
        }

        stk.pop();
        queue.pop();
    }

    std::cout << "YES\n";
}

