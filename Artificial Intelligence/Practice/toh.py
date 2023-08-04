def TOH(n, source, destination, auxilary):
    if(n == 0):
        return

    TOH(n-1, source, auxilary, destination)
    print(f"Move disk {n} from {source} to {destination}")
    TOH(n-1, auxilary, destination, source)


n = 4
TOH(n, "P", "Q", "R")
