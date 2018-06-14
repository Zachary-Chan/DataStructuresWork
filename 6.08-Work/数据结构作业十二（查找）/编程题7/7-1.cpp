#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main() {
    size_t N {};
    std::cin >> N;

    vector<int> vec(N * 2);
    for (auto& x : vec) {
        std::cin >> x;
    }

    std::sort(vec.begin(), vec.end() );

    size_t index { (N * 2 - 1) / 2};
    std::cout << vec[index] << std::endl;
}

