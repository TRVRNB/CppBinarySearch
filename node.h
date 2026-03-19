#ifndef BINARY_SEARCH_NODE
#define BINARY_SEARCH_NODE
#include <iostream>

class Node{
  // node class for binary search tree
 public:
  Node(unsigned short n_value);
  // i shouldn't need a destructor, no dynamic allocation, main.cpp will handle memory instead
  unsigned short value; // what integer this node represents
  Node* left = nullptr; // left child, must be smaller
  Node* right = nullptr; // right child, must be bigger
};

#endif
