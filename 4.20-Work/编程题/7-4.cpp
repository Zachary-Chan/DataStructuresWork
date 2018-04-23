#include <iostream>
#include <queue>
using std::queue;

int main() {
    int n {};
    std::cin >> n;
    getchar();

    if (n < 2 || n > 10) {
        std::cout << "ERROR\n";
        return 0;
    }

    queue<char> que_H {};
    queue<char> que_S {};
    char ch {};

    std::cin >> std::noskipws >> ch;
    while (ch != '\n' ) {
        if (ch == 'H') {
            que_H.push('H');
        } else {
            que_S.push('S');
        }

        std::cin >> ch;
    }
    std::cin >> std::skipws;

    while ( !que_H.empty() ) {
        std::cout << que_H.front();
        que_H.pop();

        if ( !que_S.empty() ) {
            std::cout << que_S.front();
            que_S.pop();
        }
    }

    while ( !que_S.empty() ) {
        std::cout << que_S.front();
        que_S.pop();
    }
    std::cout << std::endl;
}

