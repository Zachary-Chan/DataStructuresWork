#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

bool compare(const string& str1, const string& str2) {
    return str1.length() < str2.length();
}

int main() {
    vector<string> vec;
    vec.reserve(20);

    string str {};
    std::cin >> str;
    
    while (str != "#" ) {
        vec.push_back(str);
        std::cin >> str;
    }

    std::stable_sort(vec.begin(), vec.end(), compare);

    for (const auto& x : vec) {
        std::cout << x << ' ';
    }
}

