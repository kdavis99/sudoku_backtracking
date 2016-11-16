#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <queue>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef int value;
typedef int row;
typedef int col;

int main(int argc, char *argv[]) {
   // read in command line arguments
   ifstream sudoku_input(argv[1], ios::in);
   if (!sudoku_input) {
      cerr << "Error: could not open input file \"" 
         << argv[1] << "\"" << endl;
      return 1;
   }

   int sudoku_size = atoi(argv[2]); 
   if (sudoku_size < 0) {
      cerr << "Error: sudoku size must be greater than 0."
         << endl;
   }

   int in_x, in_y, in_val;
   vector<vector<int> > sudoku;
   sudoku.resize(sudoku_size);

   for (unsigned int i = 0; i < sudoku.size(); ++i) {
      sudoku[i].resize(sudoku_size);
   }

   int x, y, val;
   while (sudoku_input >> x) {
      sudoku_input >> y;
      sudoku_input >> val;

      sudoku[x][y] = val;
   }

   for (int i = 0; i < sudoku.size(); ++i) {
      for (int j = 0; j < sudoku[i].size(); ++j) {
         cout << "[ " << sudoku[i][j] << " ]";
      }
      cout << endl;
   }

   stack<pair<value, pair<row, col> > > backtrack;

   return 0;
}
