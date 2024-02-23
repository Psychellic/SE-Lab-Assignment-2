def is_safe(board, row, col, N):
    # Check the row on the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, N):
    # Base case: All queens placed, solution found
    if col == N:
        return True

    # Consider this column and try placing a queen in all rows one by one
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1   # Place the queen

            # Recur to place rest of the queens
            if solve_nqueens_util(board, col + 1, N):
                return True

            # If placing queen in board[i][col] doesn't work, backtrack
            board[i][col] = 0   

    # If no safe position is found in the column, return false
    return False


def print_solution(board, N):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()


if __name__ == "__main__":
    N = int(input("Enter the size of the chessboard (N): "))

    board = [[0] * N for _ in range(N)]  # Initialize the board

    if not solve_nqueens_util(board, 0, N):
        print("Solution does not exist")
    else:
        print_solution(board, N)
