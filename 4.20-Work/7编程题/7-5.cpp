#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using std::string;
using std::stack;

int main() {
    stack<int> data {};

    string str {};
    std::getline(std::cin, str);

    int operd {};
    for (size_t i {}; i < str.length(); i++) {
        if (std::isspace(str[i] ) ) {
            continue;
        }

        if (std::isalnum(str[i] ) ) {
            operd = str[i] - '0';
            data.push(operd);

        } else {
            if ( i != str.length() - 1 && str[i] == '-' && std::isdigit(str[i + 1] ) ) {
               operd = -(str[i + 1] - '0' );
               data.push(operd);

               i++;
               continue;
            }

            int temp2 {data.top() };
            data.pop();

            int temp1 {data.top() };
            data.pop();

            switch(str[i] ) {
            case '+':
                data.push(temp1 + temp2);
                break;

            case '-':
                data.push(temp1 - temp2);
                break;

            default:
                data.push(temp1 * temp2);
            }
        }
    }

    std::cout << data.top() << std::endl;
}
