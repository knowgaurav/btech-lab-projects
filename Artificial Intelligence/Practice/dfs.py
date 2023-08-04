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

    def print_graph(self):
        for i in self.vertices:
            print(f"{i} -> {self.vertices[i]}")

    def dfs_helper(self, s, v):
        v.add(s)
        print(s, end=" ")

        try:
            for n in self.vertices[s]:
                if(n not in v):
                    self.dfs_helper(n, v)
        except:
            return

    def dfs(self, source):
        visited = set()
        self.dfs_helper(source, visited)


g = graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
# g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

g.print_graph()

print("DFS Traversal: ", end="")
g.dfs(2)
