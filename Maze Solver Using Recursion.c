/*
UserId=Moinul
Password=Moinul909
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10 // Maximum maze size

// User credentials
#define USERNAME "Moinul"
#define PASSWORD "Moinul909"

// Function prototypes
bool solve_maze(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int solution[MAX_SIZE][MAX_SIZE], int n);
bool is_safe(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int n);
void print_solution(int solution[MAX_SIZE][MAX_SIZE], int n);
int login();

int main() {
    int maze[MAX_SIZE][MAX_SIZE];
    int n;

    // Check user login
    if (login() == -1) {
        printf("Login failed!\n");
        return 1;
    }

    // Get the size of the maze
    printf("Enter the size of the maze (n x n): ");
    scanf("%d", &n);

    // Get the maze input from the user
    printf("Enter the maze (0 for walls and 1 for paths):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int solution[MAX_SIZE][MAX_SIZE] = { { 0 } };

    if (solve_maze(maze, 0, 0, solution, n)) {
        print_solution(solution, n);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}

// Login function
int login() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        return 0; // Successful login
    }
    return -1; // Failed login
}

// Function to check if x, y is valid
bool is_safe(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

// Recursive function to solve the maze
bool solve_maze(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int solution[MAX_SIZE][MAX_SIZE], int n) {
    // Check if (x, y) is the goal
    if (x == n - 1 && y == n - 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (is_safe(maze, x, y, n)) {
        solution[x][y] = 1; // Mark x, y as part of the solution

        // Move forward in x direction
        if (solve_maze(maze, x + 1, y, solution, n))
            return true;

        // Move down in y direction
        if (solve_maze(maze, x, y + 1, solution, n))
            return true;

        // BACKTRACK: unmark x, y as part of solution path
        solution[x][y] = 0;
        return false;
    }

    return false;
}

// Function to print the solution
void print_solution(int solution[MAX_SIZE][MAX_SIZE], int n) {
    printf("Solution path:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", solution[i][j]);
        }
        printf("\n");
    }
}
