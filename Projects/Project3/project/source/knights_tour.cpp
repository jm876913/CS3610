/*
  Jacob Mulligan  11/1/2017
  @copyright allrights reserved
  knights_tour.cpp
*/
#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves){
  num_moves=0;
  if(isSafe(row+2, col-1)){// right 2 down 1
    row_moves[num_moves] = row+2;
    col_moves[num_moves] = col-1;
    num_moves++;
  }

  if(isSafe(row+2, col+1)){//right 2 up 1
    row_moves[num_moves] = row+2;
    col_moves[num_moves] = col+1;
    num_moves++;
  }

  if(isSafe(row+1, col+2)){//right 1 up 2
    row_moves[num_moves] = row+1;
    col_moves[num_moves] = col+2;
    num_moves++;
  }

  if(isSafe(row+1, col-2)){//right 1 down 2
    row_moves[num_moves] = row+1;
    col_moves[num_moves] = col-2;
    num_moves++;
  }

  if(isSafe(row-2, col+1)){//left 2 up 1
    row_moves[num_moves] = row-2;
    col_moves[num_moves] = col+1;
    num_moves++;
  }

  if(isSafe(row-2, col-1)){//left2 down 1
    row_moves[num_moves] = row-2;
    col_moves[num_moves] = col-1;
    num_moves++;
  }

  if(isSafe(row-1, col+2)){//left 1 up 2
    row_moves[num_moves] = row-1;
    col_moves[num_moves] = col+2;
    num_moves++;
  }

  if(isSafe(row-1, col-2)){// left 1 down 2
    row_moves[num_moves] = row-1;
    col_moves[num_moves] = col-2;
    num_moves++;
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours){
  int mo;
  int max;
  max = board_size*board_size;
  int row_moves[max], col_moves[max];

  m++;// increment current move
  board[row][col] = m; // set board knight to current move

  if(m >= max){// check for complete tours
    num_tours++;// increment tours
    print();// print to screen
    board[row][col] = 0;// reset last move
    m--;// decrement current move
    return;
  }  

  mo = 0;
  get_moves(row, col, row_moves, col_moves, mo);
  if(mo == 0){// if there are no moves
    board[row][col] = 0;// reset last move
    m--;
    return;
  }

  for(int i = 0; i < mo; i++){
    move(row_moves[i], col_moves[i], m, num_tours); // recursive call to move
    if(i + 1 == mo && board[row_moves[i]][col_moves[i]] == 0){
      board[row][col] = 0;
      m--;
      return;
    }
  }
  
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}

bool KnightsTour::isSafe(int row, int col){// funciton used to check if knight is able to be placed
  if(row < 0 || row >= 5 || col < 0 || col >= 5)// checks bounds of the board
    return false; // false if not in bounds
  if(board[row][col] != 0)//if space has been used then returns false
    return false;
    
  return true;
}