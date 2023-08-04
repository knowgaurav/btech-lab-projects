import random as ran
board = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
g = {
    1: [2, 0], 2: [2, 1], 3: [2, 2], 4: [1, 0], 5: [1, 1], 6: [1, 2], 7: [0, 0], 8: [0, 1], 9: [0, 2]
}


def check(i, j):
    if board[i][j] == 0:
        return True
    else:
        return False


def checkleftdiagonal(x):
    if board[0][0] == board[1][1] == board[2][2] == x:
        return True
    else:
        return False


def checkrightdiagonal(x):
    if board[2][0] == board[1][1] == board[0][2] == x:
        return True
    else:
        return False


def checkRow(x):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] == x:
            return True
        else:
            return False


def checkCol(x):
    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i] == x:
            return True
        else:
            return False


def game_choice(x):
    index = ran.randint(1, 9)
    if (check(g[index][0], g[index][1])):
        print("Game choice is: ", index)
        board[g[index][0]][g[index][1]] = x
    else:
        game_choice(x)


def win(i):
    if(checkrightdiagonal(i)):
        return True
    elif(checkleftdiagonal(i)):
        return True
    elif(checkCol(i)):
        return True
    elif(checkRow(i)):
        return True
    return False


def player_choice(x):
    print("It's now", x, "turn")
    t = int(input("Enter the location Player: "))
    if(check(g[t][0], g[t][1])):
        print("Player Choice is: ", t)
        board[g[t][0]][g[t][1]] = x


def displayboard():
    for i in range(3):
        print(" ")
        for j in range(3):
            print(board[i][j], "|", end=" ")
    print("\n")


def game():
    ch = int(input("Enter the choice 1,2: "))
    if(ch == 1):
        x = 2
    else:
        x = 1
    total_moves = 0
    while total_moves < 9:
        game_choice(x)
        total_moves += 1
        displayboard()
        if win(ch):
            print(ch, "Wins")
            break
        if win(x):
            print(x, "Wins")
            break
        print("\n")
        player_choice(ch)
        total_moves += 1
        displayboard()
        if win(ch):
            print(ch, "Wins")
            break
        if win(x):
            print(x, "Wins")
            break
        if(total_moves == 9):
            break
    print("||------Game Over------||")
    print("||------Game by Gaurav------||")
    print("Game is finished in", total_moves, "moves")


game()
