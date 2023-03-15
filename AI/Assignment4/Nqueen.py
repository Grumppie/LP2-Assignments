N = int(input("Enter no of queens: "))

# for printing boards
board = [[0]*N for _ in range(N)]


def attack(i, j):

    for k in range(0, N):
        if board[i][k] == 1 or board[k][j] == 1:
            return True

    for k in range(0, N):
        for l in range(0, N):
            if (k+l == i+j) or (k-l == i-j):
                if board[k][l] == 1:
                    return True
    return False


def N_queens(n):
    if n == 0:
        return True
    for i in range(0, N):
        for j in range(0, N):
            if (not (attack(i, j))) and (board[i][j] != 1):
                board[i][j] = 1
                if N_queens(n-1) == True:
                    return True
                board[i][j] = 0
    return False


N_queens(N)
for i in board:
    print(i)


# global N
# N = int(input('Enter Number of Queens: '))
# def printSolution(board):
#     for i in range(N):
#         for j in range(N):
#             print (board[i][j], end = " ")
#         print()
# def isSafe(board, row, col):
#     for i in range(col):
#         if board[row][i] == 1:
#             return False

#     for i, j in zip(range(row, -1, -1),
#                     range(col, -1, -1)):
#         if board[i][j] == 1:
#             return False
#     for i, j in zip(range(row, N, 1),
#                     range(col, -1, -1)):
#         if board[i][j] == 1:
#             return False
#     return True
# def solveNQUtil(board, col):
#     if col >= N and board[0][1] == 1 and board[2][0] == 1:
#         return True
#     for i in range(N):
#         if isSafe(board, i, col):
#                          board[i][col] = 1
#         if solveNQUtil(board, col + 1) == True:
#                 return True
#         board[i][col] = 0
#     return False
# def solveNQ(N):
#     board = [[0 for j in range(N)]for i in range(N)]
#     if solveNQUtil(board, 0) == False:
#         print ("Solution does not exist")
#         return False
#     printSolution(board)
#     return True
#     solveNQ(N)
