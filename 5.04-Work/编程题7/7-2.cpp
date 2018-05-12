#include <iostream>
#include <map>
using std::multimap;
using std::pair;

/*
 * To construct an Huffman Tree
 */

struct BinaryNode {
    // Weight for Huffman Tree node
    size_t weight {};
    BinaryNode* left {};
    BinaryNode* right {};

    BinaryNode(size_t wt, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
        : weight {wt}, left {lt}, right {rt}        {}
};

BinaryNode* buildHuffmanTree(multimap<size_t, BinaryNode* >& weights) {
    // const_iterator to the first pair
    auto citr {weights.cbegin() };

    if (weights.size() == 1) {
        return (*citr).second;
    }

    auto pair_left { *citr};
    citr = weights.erase(citr);
    auto pair_right { *citr};
    citr = weights.erase(citr);

    BinaryNode* node {new BinaryNode {pair_left.first + pair_right.first, pair_left.second, pair_right.second} };
    pair<size_t, BinaryNode* > pair_node {node->weight, node};

    weights.insert(pair_node);

    return buildHuffmanTree(weights);
}

size_t countWeight(BinaryNode* root) {
    // Root is leaf
    if ( !root->left && !root->right) {
        return 0;
    }

    size_t count {root->weight + countWeight(root->left) + countWeight(root->right) };
    return count;
}

// Release the heap occupied by the Tree
void makeEmpty(BinaryNode*& root) {
    if ( !root) {
        return;
    }
    
    makeEmpty(root->left);
    makeEmpty(root->right);
    delete root;
    root = nullptr;
}

int main() {
    size_t N {};
    std::cin >> N;

    // Weights for the nodes
    multimap<size_t, BinaryNode* > weights;

    for (size_t i {}; i < N; i++) {
        size_t temp;
        std::cin >> temp;

        pair<size_t, BinaryNode* > node {temp, new BinaryNode {temp} };
        weights.insert(node);
    }   // Accomplish input

    BinaryNode* root {buildHuffmanTree(weights) };

    std::cout << countWeight(root) << std::endl;
    
    makeEmpty(root);
}

