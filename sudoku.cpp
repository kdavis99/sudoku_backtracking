#include "sudoku.h"

Sudoku::Sudoku(vector<vector<int> > grid, int grid_size) {
   m_grid = grid;
   m_org = grid;
   m_grid_size = grid_size;
}

void Sudoku::solve_sudoku() {
   cout << "GIVEN: " <<  endl;
   print();
   for (int r = 0; r < m_grid_size; ++r) {
      for (int c = 0; c < m_grid_size; ++c) {
         if(m_org[r][c] == 0) {
            m_grid[r][c] += 1;
            int count = m_grid[r][c];
            // cout << "grid size: " << m_grid_size << endl;
            // checking if any valid checks fail
            while(!(is_valid_row(r) && is_valid_col(c) && is_valid_box(r,c)) && count <= m_grid_size) {
               // cout << "WHILE - r: " << r << " c: " << c << " count: " << count << endl;
               m_grid[r][c] = count;
               if(!(is_valid_row(r) && is_valid_col(c) && is_valid_box(r,c))) {
                  count++;
               }
            }
            // cout << "backtrack count: " << count << endl;
            // can't find a value so backtrack
            if(count > m_grid_size) {
               // cout << "cant fine a valid num" << endl;
               m_grid[r][c] = 0;
               if (!m_backtrack.empty()) {
                  // if top r < prev r then break inner loop and r-1
                  r = m_backtrack.top().second.first;
                  c = m_backtrack.top().second.second - 1;
                  // cout << "POP - [" << r << "][" << c << "] -> " << m_backtrack.top().first << endl;
                  m_backtrack.pop();
               } else {
                  cout << "oh no" << endl;
               }

            }
            else {
               int val = m_grid[r][c];
               // cout << "PUSH - [" << r << "][" << c << "] -> " << val << endl;
               // print();
               // cout << endl;
               m_backtrack.push(make_pair(val, make_pair(r, c)));
            }


         }

      }
   }
   cout << "\n\nSOLVED: " <<  endl;
   print();
}

void Sudoku::print() {
   int square = sqrt(m_grid.size());

   for (unsigned int i = 0; i < m_grid.size(); ++i) {
      if (i%square == 0) {
         for (unsigned int k = 0; k < m_grid.size() - 1; ++k) {
            cout << "▃▃▃▃▃▃▃";
         // cout << "  ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃";
         // cout << "▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃" << endl;
         }
         cout << "▃▃▃▃" << endl;
      }
      for (unsigned int j = 0; j < m_grid[i].size(); ++j) {
         if(j%square == 0 && j != 0) {
            cout << " ▋ ";
         } else if (j == 0) {
            cout << "▋ ";
         }

         cout << "[ ";
         if (m_grid[i][j]/10 == 0) {
            cout << " ";
         }
         if (m_grid[i][j] == 0) {
            cout << " " << " ]";
         } else {
            cout << m_grid[i][j] << " ]";
         }
      }
      cout << " ▋ " << endl;
   }
   for (unsigned int k = 0; k < m_grid.size() - 1; ++k) {
      cout << "▃▃▃▃▃▃▃";
   }
   cout << "▃▃▃▃" << endl;
}

bool Sudoku::is_valid_row(int index) {
   vector <int> seen (m_grid_size+1);
   for(int i = 0; i < m_grid_size; i++) {
      int found = m_grid[index][i];
      if(found != 0 && seen[found] >= 1) {
         return false;
      }
      else {
         seen[found] += 1;
      }
   }
   return true;
}

bool Sudoku::is_valid_col(int index) {
   vector <int> seen (m_grid_size+1);
   for(int i = 0; i < m_grid_size; i++) {
      int found = m_grid[i][index];
      if(found != 0 && seen[found] >= 1) {
         return false;
      }
      else {
         seen[found] += 1;
      }
   }
   return true;
}

bool Sudoku::is_valid_box(int r_index, int c_index) {
   int box_size = sqrt(m_grid_size);
   int col = c_index/box_size;
   int row  = r_index/box_size;

   int row_start = row*box_size;
   int col_start = col*box_size;
   vector <int> seen (m_grid_size+1);

   for(int r = row_start; r < row_start + box_size; r++) {
      for(int c = col_start; c < col_start + box_size; c++) {
         int found = m_grid[r][c];
         if(found != 0 && seen[found] >= 1) {
            return false;
         }
          else {
            seen[found] += 1;
         }
      }
   }

   return true;
}

