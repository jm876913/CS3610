/*
  Jacob Mulligan 10/10/2017
  @copyright all rights reserved
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode {
  BinaryNode(const int key) : key(key), left(NULL), right(NULL) {}

  ~BinaryNode() {
    delete left;
    delete right;
    left = right = NULL;
  }

  int key;
  BinaryNode *left, *right;
};

class AVLTree {

public:
  AVLTree() : root(NULL) {}
  ~AVLTree() { 
    delete root;
  }

  
  
  BinaryNode* right_rotate(BinaryNode* node); // rotates nodes right
  BinaryNode* left_rotate(BinaryNode* node);// rotates nodes left
  BinaryNode* RL_rotate(BinaryNode* node);// moves nodes right to left
  BinaryNode* LR_rotate(BinaryNode* node);// moves nodes left to right
  BinaryNode* balance_tree(BinaryNode* node);// balances to make AVL tree

  void print_key(BinaryNode* node);// prints the nodes of the tree
  void print(const char choice);// tells if the tree is empty
  void print_h(BinaryNode* node);// prints the height of the tree
  int height(BinaryNode* node);// finds the height of the tree
  int balance_factor(BinaryNode* node);// calculates the balance factor
  void remove(const int key);
  void insert(const int key);

private:
  BinaryNode* insert(int key, BinaryNode* node);// creates new nodes and inserts them into the tree
  BinaryNode* remove(int key, BinaryNode* node);//removes a nodes from the tree

  BinaryNode* root;
};

#endif
