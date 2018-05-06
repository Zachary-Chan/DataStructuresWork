#include <iostream>

struct BinaryNode {
    int element {};
    BinaryNode* left {};
    BinaryNode* right {};

    BinaryNode(int ele, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
        : element {ele}, left {lt}, right {rt}      {}
};

void traversalPreorder(BinaryNode* root) {
    if ( !root) {
        return;
    }

    std::cout << ' ' << root->element;
    traversalPreorder(root->left);
    traversalPreorder(root->right);
}

BinaryNode* rebuildTree(int* postorder, int* inorder, size_t N) {
    if ( !N) {
        return nullptr;
    }

    BinaryNode* node {new BinaryNode {postorder[N - 1] } };

    // Index to divide the left and right child
    size_t index_bound {};
    for (size_t i {}; i < N; i++) {
        if (inorder[i] == node->element) {
            index_bound = i;
        }
    }

    node->left = rebuildTree(postorder, inorder, index_bound);
    node->right = rebuildTree(postorder + index_bound, inorder + index_bound + 1, N - 1 - index_bound);
    return node;
}

int main() {
    size_t N {};
    std::cin >> N;

    int* postorder {new int[N] };
    int* inorder {new int[N] };

    for (size_t i {}; i < N; i++) {
        int temp;
        std::cin >> temp;

        postorder[i] = temp;
    }
    for (size_t i {}; i < N; i++) {
        int temp;
        std::cin >> temp;

        inorder[i] = temp;
    }   // Accomplish input

    auto* root {rebuildTree(postorder, inorder, N) };

    std::cout << "Preorder:";
    traversalPreorder(root);
    std::cout << std::endl;

    delete postorder;
    delete inorder;
}

