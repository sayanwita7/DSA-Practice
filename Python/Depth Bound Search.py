from collections import defaultdict

class Graph:
    def __init__(self):  # Correct constructor
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def dls(self, node, goal, depth, visited):
        if node == goal:
            return True
        if depth == 0:
            return False

        visited.add(node)

        for neighbor in self.graph[node]:
            if neighbor not in visited:
                if self.dls(neighbor, goal, depth - 1, visited):
                    return True

        return False

    def iddfs(self, start, goal, max_depth):
        for depth in range(max_depth + 1):
            visited = set()
            if self.dls(start, goal, depth, visited):
                return True
        return False

# Example usage
g = Graph()
g.addEdge('A', 'B')
g.addEdge('A', 'C')
g.addEdge('B', 'D')
g.addEdge('B', 'E')
g.addEdge('C', 'F')

start = 'A'
goal = 'F'
max_depth = 3

if g.iddfs(start, goal, max_depth):
    print("Path found")
else:
    print("Not found")
