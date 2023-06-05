//
//  sudoku_solver.cpp
//  sudoku_project
//
//  Created by ACHIYANT  on 04/01/21.
//  Created with Mac OS (XCode).
// Testing text 1
#include <stdio.h>
#include <stdlib.h>
int n;

//This function is used to print the desired anser of the sudoku .
void print(int arr[n][n])
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("*--------*--------*--------*");
            printf("\n");
        }
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                printf("| ");
            printf("%d ", arr[i][j]);
            if (j == 2 || j == 5 || j == 8)
                printf(" | ");
        }
        if (i == 2 || i == 5 || i == 8)
        {
            printf("\n");
            printf("*--------*--------*--------*");
        }
        printf("\n");
    }
}

/*
This function here used to check the validity of the number we have entered in the blank cell.
*/
int validity(int arr[n][n], int row, int col, int num)
{

    for (int x = 0; x <= 8; x++) //This for loop check for the same number in the same row.
        if (arr[row][x] == num)
            return 0;
    for (int x = 0; x <= 8; x++) //This for loop check for the same number in the same column.
        if (arr[x][col] == num)
            return 0;

    int u = row - row % 3, v = col - col % 3;

    for (int i = 0; i < 3; i++) //This for loop is used to check same number in the same 3*3 grid.
        for (int j = 0; j < 3; j++)
            if (arr[i + u][j + v] == num)
                return 0;

    return 1;
}

int result(int arr[n][n], int row, int col)
{

    if (row == n - 1 && col == n) //This is used to stop backtracking if we have backtracked the whole matrix.
        return 1;

    if (col == n)
    {
        row++;
        col = 0;
    }
    /*
    This if condition is used here to check whether the cell is empty or filled .
    if the cell is filled then it wll move to next cell.
    */
    if (arr[row][col] > 0)
        return result(arr, row, col + 1);

    for (int num = 1; num <= n; num++)
    {

        //This will call the validity function to check that wheter the entered no. is vald or not .
        if (validity(arr, row, col, num) == 1)
        {

            arr[row][col] = num;

            if (result(arr, row, col + 1) == 1)
                return 1;
        }

        arr[row][col] = 0; //This will unassigned the no. is the validity Function return error.
    }
    return 0;
}

int main()
{
    //Please enter the no. of rows in the sudoku most for the all 81 elements there are 9 rows .
    printf("Please enter the no. of rows in sudoku (For 81 elements , 9 rows are there ):-");
    scanf("%d", &n);
    int count = 1;
    int arr[n][n];
    //This loop is used to get the sudoku elements by the user if the cell is empty in sudoku then enter 0 for that empty cell .
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("Enter [%d] element : ", count);
            ++count;
            scanf("%d", &arr[i][j]);
        }
    }
    if (result(arr, 0, 0) == 1)
        print(arr);
    //If the sudoku doesn't have the solution then it will through the error.
    else
        printf("This sudoku have not any solution please enter a valid sudoku");

    return 0;
}
