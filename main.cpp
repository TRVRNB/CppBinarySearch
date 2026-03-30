#include <iostream>
#include <string>
#include "terminal_format.cpp"
#include "node.h"
#include "node.cpp"
using namespace std;
// Binary Search Tree - started 3/19/26
// https://github.com/TRVRNB/CppBinarySearch.git
// this is a data structure that prioritizes memory use, while still having pretty decent performance, and unlike hash tables, can handle a wide range of values. a lot of hash tables use random key generation to avoid this problem (SHA-256?), this is technically still better on memory though, and SHA-256 is very slow, binary trees also don't need to handle collisions
// the main rule of binary search trees is that the left child must always be SMALLER than its parent, and the right child must always be BIGGER (this order is probably arbitrary but that's what i'll do!)
// so the left child and all of its children will always be smaller than the parent, and the right child and all its children will always be bigger. you can very easily make an algorithm to search through this, just keep going bigger>smaller>bigger>smaller until you get the value you want
// this has worse time complexity than a hash table; intuitively it should be O(n) = log2(n) since each iteration of the binary tree stores twice as many values, therefore you are guaranteed to find the value you want in log2(n) number of searches (worst-case), while hash tables are just O(1)

namespace binary_search_tree{
  string version = "1.2";
  Node* root = nullptr;
}
using namespace binary_search_tree;

Node* add_to_tree(unsigned short to_add, Node* add_to){
  // recursive function, checks this node and its children for empty space that fits the binary search tree requirements
  // yes i know the variable names are terrible
  if (add_to == nullptr){ // empty space is found (requirements are checked by the previous recursion), should also work for root
    if (add_to == root){
      root = new Node(to_add);
      return root;
    }
    add_to = new Node(to_add);
    return add_to;
  }
  if (to_add < add_to->value){ // less than
    Node* child = add_to_tree(to_add, add_to->left);
    if (child != nullptr){
      add_to->left = child;
    }
    return nullptr;
  }
  // greater than or equal to
  Node* child = add_to_tree(to_add, add_to->right);
  if (child != nullptr){
    add_to->right = child;
  }
  return nullptr;
}

void print_tree(Node* to_print, unsigned short recursion){
  // recursive function, prints this node's children
  if (to_print == nullptr){ // if this node doesn't exist
    return;
  }
  for (int i = 1; i < recursion; i++){
    cout << ' ';
  }
  cout << to_print->value << endl;
  // now, print children
  print_tree(to_print->left, recursion + 1);
  print_tree(to_print->right, recursion + 1);
}

int main(){
  cout << GREEN << "Binary Search Tree - Version " << version << endl;
  cout << YELLOW << "Type 'HELP' for a list of commands." << endl;
  string input;
  while (input != "QUIT"){ // QUIT
    input = "";
    cout << GREEN << "Enter a command: " << RESET << flush;
					      cin >> input; // why does GNU-emacs hate this line?
    if (input == "HELP"){ // HELP
      cout << WHITE << "HELP: prints a list of commands (obviously)" << endl;
      cout << WHITE << "QUIT: stops the program" << endl;
      cout << WHITE << "ADD: adds a number to the binary tree" << endl;
      cout << WHITE << "PRINT: prints the binary tree" << endl;
    } else if (input == "ADD"){ // ADD
      string input1;
      cout << GREEN << "Enter an integer (1-999): " << RESET << flush;
      cin >> input1;
      unsigned short to_add = stoi(input1); // unsigned short has range 0 to ~65000
      if (to_add == 0 || to_add > 999){ // check for bounds
	cout << RED << to_add << " isn't within bounds." << endl;
	// this will print the wrapped version, technically you could enter -65000 and it would be within range, it's a feature
	continue;
      }
      add_to_tree(to_add, root); // call add to root
      cout << WHITE << "Added " << to_add << " to tree." << endl;
    } else if (input == "PRINT"){ // PRINT
      cout << RESET;
      print_tree(root, 1);
    }
  }
  cout << YELLOW << "Goodbye!" << endl;
  return 0;
}
