#include <iostream>
#include <string>
#include "terminal_format.cpp"
#include "node.h"
#include "node.cpp"
using namespace std;
// Binary Search Tree - started 3/19/26
// https://github.com/TRVRNB/CppBinarySearch.git
// this is a data structure that prioritizes memory use, while still having pretty decent performance, and unlike hash tables, can handle a wider range of values
// i mean, i think a lot of hash tables just use random key generation to avoid this problem (SHA-256?) but this is better on memory at least
// the main rule to binary search trees is that the left child must always be SMALLER than its parent, and the right child must always be BIGGER
// so the left child and all of its children will always be smaller than the parent
// and the right child and all its children will always be bigger
// so you can very easily make an algorithm to search through this, just keep going bigger>smaller>bigger>smaller until you get the value you want
// this has worse time complexity than a hash table, i imagine, intuitively it should be O(n) = log2(n) since each iteration of the binary tree stores twice as many values and you are guaranteed to find the value you want in log2(n) number of searches (worst-case), while hash tables are just O(1)
// not a cybersecurity guy, though, but i think this will still be faster for smaller use-cases, since cryptographic random key generation is probably pretty bad on performance
// also doesn't need to handle collisions!

namespace binary_search_tree{
  string version = "1.0";
  Node* root = nullptr;
}
using namespace binary_search_tree;

int main(){
  cout << GREEN << "Binary Search Tree - Version " << version << endl;
  root = new Node(300);
  cout << WHITE << "Root value: " << RESET << root->value << endl;
  cout << YELLOW << "Goodbye!" << endl;
  return 0;
}
