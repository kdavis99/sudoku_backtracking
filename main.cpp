#include "sudoku.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
   // read in command line arguments
   ifstream grid_input(argv[1], ios::in);
   if (!grid_input) {
      cerr << "Error: could not open input file \"" 
         << argv[1] << "\"" << endl;
      return 1;
   }

   int grid_size = atoi(argv[2]); 
   if (grid_size < 0) {
      cerr << "Error: sudoku grid size must be greater than 0."
         << endl;
   }

   vector<vector<int> > grid;

   grid.resize(grid_size);

   for (unsigned int i = 0; i < grid.size(); ++i) {
      grid[i].resize(grid_size);
   }

   int x, y, val;
   while (grid_input >> x) {
      grid_input >> y;
      grid_input >> val;

      grid[x][y] = val;
   }

   Sudoku sudoku(grid, grid_size);
   sudoku.solve_sudoku();


   return 0;
}
