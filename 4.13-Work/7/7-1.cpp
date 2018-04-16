#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    vector<char> data_input, data_output;

    // For input data
    char ch {};
    cin >> noskipws >> ch;    // Do not skip any input character
    while ( !isspace(ch) ) {
        data_input.push_back(ch);
        cin >> ch;
    }

    // For output data
    cin >> ch;
    while ( !isspace(ch) ) {
        data_output.push_back(ch);
        cin >> ch;
    }
    cin >> skipws;          // Reset the input stream

    bool isEqual {true};
    for (size_t i {}; i < data_input.size(); i++) {
        if (data_input[i] != data_output[i] ) {
            isEqual = false;
            break;
        }
    }
    if (isEqual) {
        for (size_t i {}; i < data_input.size(); i++) {
            cout << "1->2\n";
        }
        return 0;
    }

    isEqual = true;
    for (size_t i {}; i < data_input.size(); i++) {
        if (data_input[i] != data_output[data_input.size() - 1 - i] ) {
            isEqual = false;
            break;
        }
    }
    if ( !isEqual) {
        cout << "Are you kidding me?\n";
        return 0;
    }

    for (size_t i {}; i < data_input.size() - 1; i++) {
        cout << "1->3\n";
    }
    cout << "1->2\n";
    for (size_t i {}; i < data_input.size() - 1; i++) {
        cout << "3->2\n";
    }
}

