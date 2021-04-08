#include <stdio.h>
#define size 8
// A structure element to store the coordinate points in the stack
typedef struct position {
	int row;
	int col;
	} Position;
// a array of type Position which is used to implement the stack
Position stack[size];
int top =-1; //we will start top variable from -1

// This is the function to check whether the position we wish to place the queen is safe or on attack
// If the position is on attack it returns 1 else 0
int on_attack(int x, int y, int board[size][size], int N) {
  // we will only check the queens placed in rows previous rows only.
  int k, l;
  // This will check for the column safety
  for(k=1; k<=x-1; k++) {
    if(board[k][y] == 1){
      return 1;
    }
  }
  // This will check for the safety on upper right diagonal
  k = x-1;
  l = y+1;
  while (k>=1 && l<=N) {
    if (board[k][l] == 1){
      return 1;
    }
    k=k+1;
    l=l+1;
  }
  // This wil check for the safety on upper left diagonal
  k = x-1;
  l = y-1;
  while (k>=1 && l>=1) {
    if (board[k][l] == 1){
      return 1;
    }
    k=k-1;
    l=l-1;
  }

  return 0;
}

int n_queen(int row, int n, int N, int board[size][size]) {
  // This is the first step of recursion i.e., for stoping case
  // As we move on we will decrement the no of queens.
  if (n==0){
    return 1;
  }
  int j;
  // In a row we will check for the safe positon and place the queen there.
  for (j=1; j<=N; j++) {
    if(!on_attack(row, j, board, N)) {
      // After confirming the position is safe then we will push it to the stack and
      //  we will mark the position in board.
    	top++;
    	stack[top].row = row;
    	stack[top].col = j;
      board[row][j] = 1;
      // After queen is placed we will recursively call the n_queen function
      // to see whether this position will be suited for our purpose.
      if (n_queen(row+1, n-1, N, board)){
        return 1;
      }
      // If that position is not suited then we will backtrack and clear the positon of queen by setting it to 0 again.
      board[row][j] = 0;
      top--; //we will also decrement the top of stack
    }
  }
  return 0;
}
// This print function will use the stack[] to crate the final chessboard.
void print(){
	int mat[size+1][size+1];
	int i,j;
	for(i=1;i<=size;i++) {
    for(j=1;j<=size;j++)
      mat[i][j] = 0;
  }
  // Here we will iteratively pop the stack[] and fill the positions with "Q"
    while(top>-1){
        i = stack[top].row;
        j = stack[top].col;
        mat[i][j] = 1;
        top--;
    }
    // This will print the 2D solution matrix
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
  // The board[size][size] is first created and then will be cleared after it's use.
  // board[size][size] is used to marking the places of queen.
  int board[size+1][size+1];
  int i, j;

  for(i=1;i<=size;i++) {
    for(j=1;j<=size;j++)
      board[i][j] = 0;
  }

  if(n_queen(1, size, size, board)){
    print();
  }
  //Clear the board[size][size] cause we don't need it as we have stored locations in stack
  // in print function a new 2D matrix was created,In which we pop every element of stack and
  // place it in the matrix.
  // print();

    return 0;
}
