#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void bubbleSort(vector<int>& vec, size_t K) {
    for (size_t i {}; i < K; i++) {
        for (size_t j {}; j < vec.size() - 1 - i; j++) {
            if (vec[j] > vec[j + 1] ) {
                int temp {vec[j] };
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;

    vector<int> vec(N);
    for (auto& x : vec) {
        std::cin >> x;
    }

    bubbleSort(vec, K);

    for (size_t i {}; i < vec.size() - 1; i++ ) {
        std::cout << vec[i] << ' ';
    }
    std::cout << vec[vec.size() - 1];
}

