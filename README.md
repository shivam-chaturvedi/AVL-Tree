# AVL Tree Implementation in C++

This repository contains an implementation of an AVL Tree in C++. An AVL Tree is a self-balancing binary search tree where the difference between the heights of left and right subtrees cannot be more than one for all nodes.

Balance factor (left subtree height -right subtree height ) must be lies in {-1,0,1}

## Table of Contents

1. [Introduction](#introduction)
2. [Basics of AVL Tree](#basics-of-avl-tree)
3. [Code Explanation](#code-explanation)
4. [Usage in Real Life](#usage-in-real-life)
5. [Compilation and Execution](#compilation-and-execution)
6. [Contact](#contact)

## Introduction

AVL Trees are a type of self-balancing binary search tree (BST). The key property of an AVL Tree is that it maintains a balance factor for each node, which ensures that the height difference between the left and right subtrees is at most one. This balancing mechanism helps in keeping the height of the tree logarithmic with respect to the number of nodes, which ensures efficient operations.

## Basics of AVL Tree

### What is a Binary Search Tree (BST)?

A Binary Search Tree is a tree data structure where each node has at most two children. For every node, the left subtree contains only nodes with keys less than the node's key, and the right subtree contains only nodes with keys greater than the node's key.

### What is an AVL Tree?

Named after its inventors Adelson-Velsky and Landis, an AVL Tree is a self-balancing BST. It ensures that the height difference between the left and right subtrees of any node is at most one, which is called the Balance Factor.

### Balance Factor

The Balance Factor (BF) of a node is calculated as:

```
BF = height(left subtree) - height(right subtree)
```

An AVL Tree ensures that the absolute value of the balance factor of any node is not greater than one. If it exceeds, the tree performs rotations to maintain balance.

## Code Explanation

The implementation includes the following main components:

1. **Node Structure:** Represents each node in the tree.
2. **Height Calculation:** Determines the height of a node.
3. **Balance Factor Calculation:** Determines the balance factor of a node.
4. **Rotations:** 
   - **Left Rotation**: Used when the right subtree is heavier.
   - **Right Rotation**: Used when the left subtree is heavier.
   - **Left-Right and Right-Left Rotations**: Used in specific cases where double rotations are needed.

5. **Insertion and Deletion:** Maintains tree balance after inserting or deleting a node.

```cpp
// Example snippet for AVL Tree node structure
struct Node {
    int key, height;
    Node *left, *right;
    Node(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
};
```

For a complete code, refer to the [source code file](path/to/your/source/file.cpp).

## Usage in Real Life

AVL Trees are widely used in various real-life applications due to their efficient operations:

1. **Databases:** AVL Trees are used in database indexing to ensure quick search, insertion, and deletion operations.
2. **File Systems:** File systems use AVL Trees to manage the structure of files and directories efficiently.
3. **Memory Management:** In operating systems, AVL Trees help manage free memory spaces by keeping track of free memory blocks.

## Compilation and Execution

To compile and run the code:

```bash
g++ -o AVLTree AVLTree.cpp
./AVLTree
```

Replace `AVLTree.cpp` with the name of your source file.

## Contact

For more information or inquiries, you can reach out to me on [LinkedIn](https://www.linkedin.com/in/shivam-chaturvedi-77629321a).
