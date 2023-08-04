class graph:
    vertices = {}
    goalFound = False

    def __init__(self):
        pass

    def addEdge(self, u, v):
        if u in self.vertices:
            self.vertices[u].append(v)
        else:
            l = list()
            l.append(v)
            self.vertices[v] = l

    def printGraph(self):
        for i in self.vertices:
            print(f"{i} -> {self.vertices[i]}")

    def def_helper(self, s, g, v):
        if(self.goalFound):
            return

        if(s == g):
            print(s)
            print("Goal Found!")
            self.goalFound = True

        v.add(s)
        print(s, end=" ")

        try:
            for n in self.vertices[s]:
                if(n not in v):
                    self.def_helper(n, g, v)
        except:
            return

    def dfs(self, start, goal):
        visited = set()
        if(start == goal):
            print("Start == Goal")
            return

        self.def_helper(start, goal, visited)


g = graph()
e = 7

# print("Enter the edges: ")
# for i in range(e):
#     edge = input()
#     edge.split()
#     g.addEdge(int(edge[0]), int(edge[2]))

g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(3, 4)
g.addEdge(4, 0)
g.addEdge(4, 1)
g.addEdge(4, 5)

print("\nGraph is: ")
g.printGraph()

start = (int)(input("\nEnter the start node: "))
goal = (int)(input("Enter the goal node: "))

print("\nDFS Traversal: ", end="")
g.dfs(start, goal)
