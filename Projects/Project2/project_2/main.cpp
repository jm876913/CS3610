/*
  Jacob Mulligan 10/10/2017
  @copyright all rights reserved
*/

#include <iostream>
#include "avl_tree.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv) {

  AVLTree tree;
  BinaryNode* AVLnode = NULL;

  char option;
  int key;
  ifstream fin;
  fin.open("input1.dat");
  if(fin.fail()){
    cout << "couldn't open file" << endl;
    return 1;
  }
  else{

    do {
      cin >> option;
      switch(option) {
        case 'i':
          //cout << "inputing" << endl;
          cin >> key;
           AVLnode = tree.insert(key, AVLnode);
          break;
        case 'r':
          cout << "removing a node" << endl;
          cin >> key;
          AVLnode = tree.remove(key, AVLnode);
          break;
        case 'h':
           tree.print_h(AVLnode);
          break;
        case 'p':
           tree.print_key(AVLnode);
          break;
        default:
          break;
      }
    } while(option != 'q');
  }
  fin.close();
}
