from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    def addEdge(self, u, v):
        self.graph[u].append(v)
    def iddfs(self, start, target):
        depth=0
        bottomReached = False
        while not bottomReached:
          print ("Iterating depth: ", depth)
          result, bottomReached = self.iddfsRec(start, target, 0, depth)
          if result is not None:
            return result
          depth+=1
        return None
    def iddfsRec(self, node, target, cur_depth, max_depth):
      print(node)
      if node == target:
          print("\nPath Found!")
          return node, True
      if cur_depth == max_depth:
          print(f"(Maximum depth reached at node:{node})")
          return None, False
      if not self.graph[node]:
          return None, True
      bottomReached = True
      for i in range(len(self.graph[node])):
          result, bottom_reached_rec = self.iddfsRec(self.graph[node][i], target, cur_depth + 1, max_depth)
          if result is not None:
              return result, True
          bottomReached = bottomReached and bottom_reached_rec
      return None, bottomReached
g = Graph()
g.addEdge('A', 'B')
g.addEdge('A', 'C')
g.addEdge('B', 'D')
g.addEdge('B', 'E')
g.addEdge('C', 'F')
g.addEdge('F', 'G')
start = 'A'
goal = 'F'
res = g.iddfs(start, goal)
if res is None:
  print("\nPath does not exist!")
