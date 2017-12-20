/*
  Jacob Mulligan  11/1/2017
  @copyright allrights reserved
  knights_tour.h
*/
#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <vector>
using namespace std;

class KnightsTour {

public:
	KnightsTour(int board_size);// class constructor
    int generate(int row, int col);

private:
	int row, col;
	vector<vector<int> > board;
	int board_size;
	
	void move(int row, int col, int& m, int& num_tours); // recursive backtracking function to solve knights tour
    void get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves); // gets possible knights moves
	void print();// prints board to screen
	bool isSafe(int row, int col);//checks for legal moves
};

#endif
