from collections import defaultdict

class Graph:
    def __init__(self):  # fixed constructor
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSSolve(self, v, visited):
        visited.add(v)
        print(v)
        for neighbor in self.graph[v]:
            if neighbor not in visited:
                self.DFSSolve(neighbor, visited)

    def DFS(self, v):
        visited = set()
        self.DFSSolve(v, visited)

g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)
g.addEdge(4, 7)
g.DFS(0)
