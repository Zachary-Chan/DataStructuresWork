#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;

void func(int M);

int main() {
    int N, M;
    cin >> N >> M;
    getchar();

    for (int i {}; i < N; i++) {
        func(M);
    }
}

void func(int M) {
    stack<int> stk;
    string str {};
    getline(cin, str);

    try {
        for (size_t i {}; i < str.length(); i++) {
            if (str[i] == 'S') {
                stk.push(1);

                if (stk.size() > static_cast<size_t> (M) ) {
                    throw out_of_range {"fatal"};
                }
            } else {
                if (stk.empty() ) {
                    throw out_of_range {"Fatal"};
                }
                stk.pop();
            }
        }
    } catch (exception& ) {
        cout << "NO\n";
        return;
    }

    if ( !stk.empty() ) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

