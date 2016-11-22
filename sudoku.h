#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <utility>

using namespace std;

typedef int value;
typedef int row;
typedef int col;

class Sudoku
{
   public:
      Sudoku(vector <vector<int> > grid, int grid_size);
      void solve_sudoku();

   private:
      bool is_valid_row(int index);
      bool is_valid_col(int index);
      bool is_valid_box(int r_index, int c_index);
      void print();
      int m_grid_size; 
      vector< vector<int> > m_grid;
      vector< vector<int> > m_org;
      stack<pair<value, pair<row, col> > > m_backtrack;

};

#endif
