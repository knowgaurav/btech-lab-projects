class graph:
    g = []
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

    def make_adj(self):
        cities = self.vertices.keys()

        for i in cities:
            l = list()
            for j in cities:
                if(i == j):
                    l.append(0)
                elif(j in self.vertices[i]):
                    l.append(1)
                else:
                    l.append(0)
            self.g.append(l)

    def print_adj(self):
        for i in range(len(self.g)):
            for j in self.g[i]:
                print(f"{j} ", end="")
            print()

    def isSafe(self, i, colors, c):
        for j in range(0, len(self.vertices.keys())):
            if self.g[i][j] == 1 and colors[j] == c:
                return False

        return True

    def helper(self, colors, i):
        if(i == len(self.vertices.keys())):
            return True

        for c in range(5):
            if self.isSafe(i, colors, c):
                colors[i] = c
                if self.helper(colors, i+1):
                    return True
                colors[i] = 0

    def graphColor(self, colors):
        if self.helper(colors, 0) == None:
            return False
        else:
            return True


g = graph()

g.addEdge("Himachal", "Punjab")
g.addEdge("Himachal", "TamilNadu")
g.addEdge("Punjab", "Himachal")
g.addEdge("Punjab", "TamilNadu")
g.addEdge("Punjab", "Kerala")
g.addEdge("TamilNadu", "Himachal")
g.addEdge("TamilNadu", "Punjab")
g.addEdge("TamilNadu", "Kerala")
g.addEdge("Kerala", "Punjab")
g.addEdge("Kerala", "TamilNadu")

g.print_graph()

g.make_adj()

pallet = ["White", "Red", "Pink", "Yellow", "Black"]
colors = [-1]*4
print("\nGraph Colors are: ")
if g.graphColor(colors):
    cities = ["Himachal", "Punjab", "TamilNadu", "Kerala"]
    for i in range(len(cities)):
        print(f"{cities[i]} : {pallet[colors[i]]}")
else:
    print("Not suffiecient colors!")
# print(colors)
