class graph:
    vertices = {}

    def __init__(self):
        pass

    def addEdge(self, u, v):
        if u in self.vertices:
            self.vertices[u].append(v)
        else:
            l = list()
            l.append(v)
            self.vertices[u] = l

    def printGraph(self):
        for i in self.vertices:
            print(f"{i} -> {self.vertices[i]}")

    def bfs(self, start, goal):
        visited = set()
        queue = []

        if(start == goal):
            print("Goal == Start")
            return

        visited.add(start)
        queue.append(start)

        while(len(queue) != 0):
            front = queue.pop(0)
            print(f"{front}", end=" ")

            if(front == goal):
                print("\nGoal Found!")
                return

            try:
                for n in self.vertices[front]:
                    if(n not in visited):
                        queue.append(n)
                        visited.add(n)
            except:
                pass

        print("Traversal Complete. Goal not found!")


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

print("\nGraph is:")
g.printGraph()

start = int(input("\nEnter the start node: "))
goal = int(input("Enter the goal node: "))

print("\nBFS Traversal is: ", end="")
g.bfs(start, goal)
