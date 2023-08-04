jug1 = int(input("Enter the capacity of jug1: "))
jug2 = int(input("Enter the capacity of jug2: "))
target = int(input("Enter the taget to measure: "))

visited = set()
print(visited)


def waterjugProblem(amount1, amount2):
    if((amount1 == target and amount2 == 0) or (amount1 == 0 and amount2 == target)):
        print(amount1, amount2)
        return True

    if (amount1, amount2) not in visited:
        print(amount1, amount2)

        visited.add((amount1, amount2))

        return (waterjugProblem(0, amount2) or
                waterjugProblem(amount1, 0) or
                waterjugProblem(jug1, amount2) or
                waterjugProblem(amount1, jug2) or
                waterjugProblem(amount1 + min(amount2, (jug1-amount1)), amount2-min(amount2, (jug1-amount1))) or
                waterjugProblem(amount1 - min(amount1, (jug2-amount2)),
                                amount2+min(amount1, (jug2-amount2)))
                )
    else:
        return False


print("Steps: ")
waterjugProblem(0, 0)
