#include <iostream>
#include <string>
#include <algorithm>
using std::string;

struct BinaryNode {
    char element {};
    BinaryNode* left {};
    BinaryNode* right {};

    BinaryNode(char ele, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
        : element {ele}, left {lt}, right {rt}      {}
};

size_t height(BinaryNode* root) {
    if ( !root) {
        return 0;
    }

    return std::max(height(root->left), height(root->right) ) + 1;
}

BinaryNode* rebuildTree(string preorder, string inorder) {
    if ( preorder.empty() ) {
        return nullptr;
    }

    BinaryNode* node {new BinaryNode {preorder[0] } };

    // Index to devide the left and right child
    size_t index_bound {inorder.find(node->element) };

    node->left = rebuildTree(preorder.substr(1, index_bound), inorder.substr(0, index_bound) );
    node->right = rebuildTree(preorder.substr(1 + index_bound), inorder.substr(index_bound + 1) );
    return node;
}

int main() {
    size_t N {};
    std::cin >> N;
    getchar();

    string preorder {};
    string inorder {};
    std::getline(std::cin, preorder);
    std::getline(std::cin, inorder);

    auto* node {rebuildTree(preorder, inorder) };
    std::cout << height(node) << std::endl;

    delete node;
}

