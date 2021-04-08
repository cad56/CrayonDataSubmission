#include <stdio.h>
#define n 8
typedef struct location{
  int row;
  int col;
  int move;
}Location;
Location stack[n];
int top = -1;
int is_valid(int x, int y, int board[n+1][n+1]) {
  // The chosed position should be inside of the court and should not be previously occupied.
  if (x>=1 && x<=n && y>=1 && y<=n && board[x][y]==0){
    return 1;
  }
  return 0;
}

int L_move(int board[n+1][n+1], int x, int y, int move, int x_choices[], int y_choices[]) {
  if (move == n*n)
    return 1;

  int k;
  for(k=0; k<8; k++) {
    int x_new = x+x_choices[k];
    int y_new = y+y_choices[k];

    if(is_valid(x+x_choices[k], y+y_choices[k], board)) {
      top++;
    	stack[top].row = x+x_choices[k];
    	stack[top].col = y+y_choices[k];
      stack[top].move = move;
      board[x_new][y_new] = 1;//To mark that the position is occupied once
      if (L_move(board, x_new, y_new, move+1, x_choices, y_choices)){
        return 1;
      }
      board[x+x_choices[k]][y+y_choices[k]] = 0; // backtracking
      top--;
    }
  }

  return 0;
}

void start() {
  int board[n+1][n+1];

  int i, j;
  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      board[i][j] = 0;
    }
  }

  int x_choices[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int y_choices[] = {1, 2, 2, 1, -1, -2, -2, -1};

  board[1][1] = 0; // placing knight at cell(1, 1)

  if (L_move(board, 1, 1, 1, x_choices, y_choices)) {
    printf("Knight's Tour is as follow:\n");
    print();
    return ;
  }
  printf("No solution Exists...\n");
  return;
}
void print(){
	int mat[n][n];
	int i,j;
  mat[0][0]=0;
  // Here we will iteratively pop the stack[] and fill the positions with "Q"
    while(top>-1){
        i = stack[top].row;
        j = stack[top].col;
        mat[i][j] = stack[top].move;
        top--;
    }
    // This will print the 2D solution matrix
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
  start();
  return 0;
}
