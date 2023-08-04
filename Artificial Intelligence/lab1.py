start_matrix = []
goal_matrix = []


def solve_matrix(m, g, n):
    count = 0
    for i in range(n):
        for j in range(n):
            if ((m[i][j] != ' ') and (m[i][j] != g[i][j])):
                count += 1
                solve_matrix()


def getMatrix(m, n):
    for i in range(n):
        lst = []
        for j in range(n):
            ele = input("Enter (%s,%s) element: " % (i, j))
            if(ele == " "):
                lst.append(ele)
            else:
                lst.append(int(ele))
        m.append(lst)


def printMatrix(m, n):
    for i in range(n):
        for j in range(n):
            print(str(m[i][j]) + " ", end="")
        print()


n = int(input("Enter the matrix size: "))

print("\nEnter start matrix: ")
getMatrix(start_matrix, n)

print("\nEnter goal matrix: ")
getMatrix(goal_matrix, n)

print("\nStart Matrix is: ")
printMatrix(start_matrix, n)

print("\nGoal Matrix is: ")
printMatrix(goal_matrix, n)
