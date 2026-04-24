#include <stdio.h>

#define N 4  

int board[N][N];
int solutionCount = 0;

void printSolution() {
    printf("\nSolution %d:\n", ++solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void solveNQ(int col) {

    if (col == N) {
        printSolution();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {

            board[i][col] = 1;   

            solveNQ(col + 1);    

            board[i][col] = 0;   
        }
    }
}

int main() {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solveNQ(0);

    printf("\nTotal Solutions: %d\n", solutionCount);

    return 0;
}