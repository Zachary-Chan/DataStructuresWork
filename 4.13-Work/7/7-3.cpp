#include <iostream>
#include <queue>
#include <vector>
using std::queue;
using std::vector;

vector<queue<int> > vec;

int indexOfVec(int data) {
    for (size_t i {}; i < vec.size(); i++) {
        if (data < vec[i].back() ) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N {};
    std::cin >> N;
    size_t count {};

    for (int i {}; i < N; i++) {
        int temp {};
        std::cin >> temp;

        int index {};
        if ( (index = indexOfVec(temp) ) == -1) {
            queue<int> newQueue;
            newQueue.push(temp);
            vec.push_back(newQueue);
            count++;
        } else {
            vec[index].push(temp);
        }
    }

    std::cout << count << std::endl;
}

