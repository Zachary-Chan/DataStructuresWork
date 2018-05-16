// BinaryTree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/*
 * Construct a BinaryTree.
 *
 * ********************************** Preliminaries *********************************
 * We set the leaf's height as 0, and the root's depth is 0 vice versa.
 *
 * ********************************** Functions *************************************
 * void makeEmpty()                         --> Make the tree empty
 * void preorderTraverse() const            --> Preorder traversal
 * void inorderTraverse() const             --> Inorder Traversal
 * void postorderTraverse() const           --> Postorder Traversal
 * int depth() const                        --> Return the depth
 * size_t countNodes() const                --> Return the count of all the nodes
 * size_t countLeaves() const               --> Return the count of all the leaves
 * size_t countNodesOfOneDegree() const     --> Return one degree nodes' count
 * void printLeafToRootPath() const         --> Print leaf-to-root path
 * void swapLeftAndRightChild()             --> Swap the tree's left and right child
 * void doubleorderTrraverse() const        --> Doubleorder traversal
 *
 * **********************************************************************************
 */

#include <iostream>
#include <algorithm>
#include <stack>
using std::stack;

template <typename Comparable>
class BinaryTree {
public:
    // The Node class of the tree.
    struct Node {
        Comparable element {};
        Node* left {};
        Node* right {};

        Node(const Comparable ele = Comparable {}, Node* lt = nullptr, Node* rt = nullptr)
            : element {ele}, left {lt}, right {rt}          {}
    };

    // Root of the tree.
    Node* root {};

private:

    // Internal method to make the subtree empty.
    void makeEmpty(Node*& rt) {
        if ( !rt) {
            return;
        }

        makeEmpty(rt->left);
        makeEmpty(rt->right);
        delete rt;
        rt = nullptr;
    }

    // Internal method to determine if a node is a leaf.
    bool isLeaf(Node* rt) const {
        if ( !rt->left && !rt->right) {
            return true;
        }
        return false;
    }

    // Internal method to traverse the subtree preorderly.
    void preorderTraverse(Node* rt) const {
        if ( !rt) {
            return;
        }

        std::cout << rt->element << " --> ";
        preorderTraverse(rt->left);
        preorderTraverse(rt->right);
    }

    // Internal method to traverse the subtree inorderly.
    void inorderTraverse(Node* rt) const {
        if ( !rt) {
            return;
        }

        inorderTraverse(rt->left);
        std::cout << rt->element << " --> ";
        inorderTraverse(rt->right);
    }

    // Internal method to traverse the subtree postorderly.
    void postorderTraverse(Node* rt) const {
        if ( !rt) {
            return;
        }

        postorderTraverse(rt->left);
        postorderTraverse(rt->right);
        std::cout << rt->element << " --> ";
    }

    // Internal method to calculate the subtree's height.
    // Return the subtree's height if the subtree exists,
    // and -1 vice versa.
    /*
     * For convenience, we set the leaf's height as 0.
     */
    int height(Node* rt) const {
        if ( !rt) {
            return -1;
        }

        return std::max(height(rt->left), height(rt->right) ) + 1;
    }

    // Internal method to count the subtree's nodes.
    size_t countNodes(Node* rt) const {
        if ( !rt) {
            return 0;
        }

        return countNodes(rt->left) + countNodes(rt->right) + 1;
    }

    // Internal method to count the subtree's leaves.
    size_t countLeaves(Node* rt) const {
        if ( !rt) {
            return 0;
        }

        if (isLeaf(rt) ) {
            return 1;
        }

        return countLeaves(rt->left) + countLeaves(rt->right);
    }

    // Internal method to count the subtree's nodes that are only of 1 degree.
    size_t countNodesOfOneDegree(Node* rt) const {
        if ( !rt) {
            return 0;
        }

        size_t count {};
        if ( (rt->left && !rt->right) || ( !rt->left && rt->right) ) {
            count++;
        }

        count += countNodesOfOneDegree(rt->left) + countNodesOfOneDegree(rt->right);
        return count;
    }

    // Auxiliary method to print the stack.
    void printPath(stack<Comparable> stk) const {
        while ( !stk.empty() ) {
            std::cout << stk.top() << " --> ";
            stk.pop();
        }

        // Remove the last " --> ".
        std::cout << "\b\b\b\b\b     ";

        std::cout << std::endl;
    }

    // Internal method to print the subtree's leaf-to-root path.
    // Use a stack to reverse the path.
    void printLeafToRootPath(Node* rt, stack<Comparable>& stk) const {
        if ( !rt) {
            return;
        }

        stk.push(rt->element);

        if (isLeaf(rt) ) {
            printPath(stk);

        } else {
            // Temporary stacks for the recursives.
            stack<Comparable> stk1 {stk};
            stack<Comparable> stk2 {stk};
            printLeafToRootPath(rt->left, stk1);
            printLeafToRootPath(rt->right, stk2);
        }
    }

    // Internal method to swap all the nodes' left child and right child.
    void swapLeftAndRightChild(Node* rt) {
        if ( !rt) {
            return;
        }

        std::swap(rt->left, rt->right);
        swapLeftAndRightChild(rt->left);
        swapLeftAndRightChild(rt->right);
    }

    // Internal method to traverse the subtree by doubleorder.
    void doubleorderTraverse(Node* rt) const {
        if ( !rt)       return;

        std::cout << rt->element << " --> ";

        doubleorderTraverse(rt->left);
        std::cout << rt->element << " --> ";

        doubleorderTraverse(rt->right);
    }

public:
    // Non-parameter constructor.
    BinaryTree(Node* rt = nullptr) : root {rt}      {}

    // Destructor.
    ~BinaryTree() {
        makeEmpty();
    }

    // Make the tree empty.
    void makeEmpty() {
        makeEmpty(root);
    }

    // Preorder traverse the tree.
    void preorderTraverse() const {
        preorderTraverse(root);

        // Remove the last " --> "
        std::cout << "\b\b\b\b\b     ";

        std::cout << std::endl;
    }

    // Inorder traverse the tree.
    void inorderTraverse() const {
        inorderTraverse(root);

        // Remove the last " --> "
        std::cout << "\b\b\b\b\b     ";

        std::cout << std::endl;
    }

    // Postorder traverse the tree.
    void postorderTraverse() const {
        postorderTraverse(root);

        // Remove the last " --> "
        std::cout << "\b\b\b\b\b     ";

        std::cout << std::endl;
    }

    // Return the tree's depth if the tree exists,
    // and -1 vice versa.
    int depth() const {
        return height(root);
    }

    // Return the nodes' count in the tree.
    size_t countNodes() const {
        return countNodes(root);
    }

    // Return the leaves' count in the tree.
    size_t countLeaves() const {
        return countLeaves(root);
    }

    // Return the count of the nodes that are of only one degree in the tree.
    size_t countNodesOfOneDegree() const {
        return countNodesOfOneDegree(root);
    }

    // Print the leaf-to-root path.
    void printLeafToRootPath() const {
        stack<Comparable> stk;
        printLeafToRootPath(root, stk);
    }

    // Swap all the Nodes' left and right child in the tree.
    void swapLeftAndRightChild() {
        swapLeftAndRightChild(root);
    }

    // Doubleorder traversal.
    void doubleorderTraverse() const {
        doubleorderTraverse(root);

        // Remove the last " --> "
        std::cout << "\b\b\b\b\b     ";

        std::cout << std::endl;
    }
};

#endif
