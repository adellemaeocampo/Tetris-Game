#include "grid.h"








int Grid:: ClearFullRows(){
  int completed = 0;
  for (int row = numRows-1; row >= 0; row --){
      if (IsRowFull(row)){
          ClearRow(row);
          completed++;
      } else if (completed > 0) {
          MoveRowDown(row, completed);
      }
  }
  return completed;
}




bool Grid::IsRowFull (int row) {
  for (int column=0; column< numCols; column++) {
      if (grid[row][column] == 0) {
          return false;
      }
  }
  return true;
}




void Grid::ClearRow(int row) {
  for (int column=0; column<numCols; column++) {
      grid[row][column] = 0;
  }
}




void Grid::MoveRowDown(int row, int numRows){
  for (int column=0; column<numCols; column++) {
      grid[row + numRows][column] = grid[row][column];
      grid[row][column] = 0;
  }
}




bool Grid::IsCellOutside( int row, int cols){
  if(row>=0 && row< numRows && cols >= 0 && cols < numCols){
      return false;




  }
  return true;
}






