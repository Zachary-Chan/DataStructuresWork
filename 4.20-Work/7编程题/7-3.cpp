#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using std::stack;
using std::string;

int main() {
    string str {};
    stack<char> stk {};

    std::getline(std::cin, str);
    for (const auto& x : str) {
      stk.push(x);
    }

    for (const auto& x : str) {
      if (stk.top() != x) {
        std::cout << "NO\n";
        return 0;
      }
      stk.pop();
    }

    std::cout << "YES\n";
}
