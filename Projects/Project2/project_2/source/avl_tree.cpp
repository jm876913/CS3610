/*
  Jacob Mulligan 10/10/2017
  @copyright all rights reserved
*/


#include <iostream>
#include "avl_tree.h"
using namespace std;
/*
  public instert function
*/
void AVLTree::insert(const int key) {
  this->root = insert(key, this->root);
}
/*
  public remove function
*/
void AVLTree::remove(const int key){
  this->root = remove(key, this->root);
}
/*
  private instert function
  creates new nodes and inputs a value into it and checks for duplicate nodes
*/
BinaryNode* AVLTree::insert(const int key, BinaryNode* node) {
  if (node == NULL) {
    return new BinaryNode(key);
  }

  if(key < node->key) {
    if(node->left == NULL) {
      node->left = new BinaryNode(key); 
    } 
    else {
      node->left = insert(key, node->left);
    }
  }
  else if(key == node->key){
    cout << "duplicate" << endl;
  }
  else {
    if(node->right == NULL) {
      node->right = new BinaryNode(key); 
    } 
    else {
      node->right = insert(key, node->right);
    }
  }

  return node;
}
/*
  private remove function

  removes selected node and outputs if the user tries to remove
  a non existent node
*/
BinaryNode* AVLTree::remove(int key, BinaryNode* node){
 if(node == NULL){
  cout << "no node" << endl;
  return node;
 }
 if(key < node->key){
  node->left = remove(key, node->left);
  node = balance_tree(node);
 }
 else if(key > node->key){
  node->right = remove(key, node->right);
  node = balance_tree(node);
 }
 else{
  BinaryNode* node_remove = node;
  if(node_remove->left && node_remove->right){
    node_remove = node_remove->left;
    while(node_remove->right){
      node_remove = node_remove->right;
    }
    node->key = node_remove->key;
    node->left = remove(node->key, node->left);
    node = balance_tree(node);
  }
  else{
    if(node_remove->left && !node_remove->right){
      node = node_remove->left;
    }
    else if(!node_remove->left && node_remove->right){
      node = node_remove->right;
    }
    else{
      node = NULL;
    }
    delete node_remove;
  }
 }
 return node;
}
/*
  public right rotation function

  rotates nodes to the right
*/
BinaryNode* AVLTree::right_rotate(BinaryNode* node){
  BinaryNode* ptr, *ptr2;
  ptr = node -> left;
  ptr2 = ptr->right;
  ptr->right = node;
  node->left = ptr2;
  return ptr;
}
/*
  public left rotation function

  rotates nodes to the left
*/
BinaryNode* AVLTree::left_rotate(BinaryNode* node){
  BinaryNode* ptr, *ptr2;
  ptr = node ->right;
  ptr2 = ptr->left;
  ptr->left = node;
  node->right = ptr2;
  return ptr;
}
/*
  public right to left rotation function

  sets left node to right and returns the left rotation node
*/
BinaryNode* AVLTree::RL_rotate(BinaryNode* node){
  node->left = right_rotate(node->left);
  return left_rotate(node);
}
/*
  public left to right rotation function

  sets right node to left and returns the right rotation node
*/
BinaryNode* AVLTree::LR_rotate(BinaryNode* node){
  node -> right = left_rotate(node->right);
  return right_rotate(node);
}
/*
  public binary tree balance function

  balances the binary tree to make it an AVL tree
*/
BinaryNode* AVLTree::balance_tree(BinaryNode* node){
  int bf = balance_factor(node);
  if(bf < -1){
    if(balance_factor(node->right) > 0){
      node = RL_rotate(node);
    }
    else{
      node = left_rotate(node);
    }
  }
  else if(bf > 1){
    if(balance_factor(node->left) > 0){
      node = LR_rotate(node);
    }
    else{
      node = right_rotate(node);
    }
  }
  return node;
}
/*
  public print key function

  prints out the nodes entered in inorder traversal
*/
void AVLTree::print_key(BinaryNode* node){
 if(node == NULL){
  return;
 }
 
 print_key(node->left);
 cout << node->key << " ";
 print_key(node->right);
}
/*
  public print function

  checks the users choice so that it will tell the 
  user if the tree is empty
*/
void AVLTree::print(const char choice){
  if(this->root == NULL){
    cout << "Empty" << endl;
    return;
  }

  switch(choice){
    case 'p':
      print_key(root);
      cout << endl;
    break;
    case'h':
      print_h(root);
      cout << endl;
    break;
  }
}
/*
  public print height function

  prints out the height of the tree 
*/
void AVLTree::print_h(BinaryNode* node){
  if(node == NULL){
    return;
  }
  print_h(node->left);
  cout << height(node)<< " ";
  print_h(node->right);
}
/*
  public height function

  finds the height of the tree 
*/
int AVLTree::height(BinaryNode* node){
  int h = 0;
  if(node != NULL){
    int left = height(node->left);
    int right = height(node->right);
    h = 1+ max(left, right);
  }
  return h;

}
/*
  public balance factor function

  calculates the balance factor of the tree to be used to 
  balance the AVL tree
*/

int AVLTree::balance_factor(BinaryNode* node){
  int bf = height(node -> left) - height(node -> right); //subtracting the height of the left node from the right
  return bf;
}
