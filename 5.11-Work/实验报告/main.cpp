// main.cpp
// Drive unit to test "BinaryTree.h"

/*
 * we create a tree as below:
 *                1
 *               / \
 *              2   3
 *             /   / \
 *            4    7  8
 *           / \   \  \
 *          5  6   9  10
 *
 * Then print the tree using preorder traversal, inorder traversal,
 * postorder traversal and doubleorder traversal respectively.
 *
 * Expective Output
 * Preorder traversal: 1 --> 2 --> 4 --> 5 --> 6 --> 3 --> 7 --> 9 --> 8 --> 10
 * Inorder Traversal: 5 --> 4 --> 6 --> 2 --> 1 --> 7 --> 9 --> 3 --> 8 --> 10
 * Postorder Traversal: 5 --> 6 --> 4 --> 2 --> 9 --> 7 --> 10 --> 8 --> 3 --> 1
 * Doubleorder Traversal: 1 --> 2 --> 4 --> 5 --> 5 --> 4 --> 6 --> 6 --> 2 -->
 *      1 --> 3 --> 7 --> 7 --> 9 --> 9 --> 3 --> 8 --> 8 --> 10 --> 10
 *
 *
 * After swapping all the left and right child in the tree, it might be as below:
 *                 1
 *               /  \
 *              3   2
 *             / \   \
 *            8  7   4
 *           /  /   / \
 *          10 9   6  5
 *
 * And all the requirements are CORRECT!
 */

#include <iostream>
#include "BinaryTree.h"
using Node = BinaryTree<int>::Node;

int main() {
    // Construct a tree.
    BinaryTree<int> bT;

    auto* p5 = new Node {5};
    auto* p6 = new Node {6};
    auto* p9 = new Node {9};
    auto* p10 = new Node {10};

    auto* p4 = new Node {4, p5, p6};
    auto* p7 = new Node {7, nullptr, p9};
    auto* p8 = new Node {8, nullptr, p10};

    auto* p2 = new Node {2, p4};
    auto* p3 = new Node {3, p7, p8};

    auto* p1 = new Node {1, p2, p3};
    bT.root = p1;
    // Accomplish constructing.

    std::cout << "Preorder Travresal:\n";
    bT.preorderTraverse();
    std::cout << std::endl;

    std::cout << "Inorder Travresal:\n";
    bT.inorderTraverse();
    std::cout << std::endl;

    std::cout << "Postorder Travresal:\n";
    bT.postorderTraverse();
    std::cout << std::endl;

    std::cout << "Doubleorder Travresal:\n";
    bT.doubleorderTraverse();
    std::cout << std::endl;

    std::cout << "Depth: ";
    std::cout << bT.depth();
    std::cout << std::endl;

    std::cout << "Count of nodes: ";
    std::cout << bT.countNodes();
    std::cout << std::endl;

    std::cout << "Count of leaves: ";
    std::cout << bT.countLeaves();
    std::cout << std::endl;

    std::cout << "Count of nodes that are of only one degree: ";
    std::cout << bT.countNodesOfOneDegree();
    std::cout << std::endl;

    std::cout << "All the leaf-to-root paths:\n";
    bT.printLeafToRootPath();
    std::cout << std::endl << std::endl;


    // Swap all the left and right child.
    bT.swapLeftAndRightChild();
    std::cout << "*******************************************************************************\n";
    std::cout << "*******************************************************************************\n";
    std::cout << "*******************************************************************************\n\n";
    std::cout << "After swapping all the left and right children\n";

    std::cout << "Preorder Travresal:\n";
    bT.preorderTraverse();
    std::cout << std::endl;

    std::cout << "Inorder Travresal:\n";
    bT.inorderTraverse();
    std::cout << std::endl;

    std::cout << "Postorder Travresal:\n";
    bT.postorderTraverse();
    std::cout << std::endl;

    std::cout << "Doubleorder Travresal:\n";
    bT.doubleorderTraverse();
    std::cout << std::endl;

    std::cout << "Depth: ";
    std::cout << bT.depth();
    std::cout << std::endl;

    std::cout << "Count of nodes: ";
    std::cout << bT.countNodes();
    std::cout << std::endl;

    std::cout << "Count of leaves: ";
    std::cout << bT.countLeaves();
    std::cout << std::endl;

    std::cout << "Count of nodes that are of only one degree: ";
    std::cout << bT.countNodesOfOneDegree();
    std::cout << std::endl;

    std::cout << "All the leaf-to-root paths:\n";
    bT.printLeafToRootPath();
    std::cout << std::endl << std::endl;
}
