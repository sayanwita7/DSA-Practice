graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E', 'F']
}

visited = set()

def dfs(visited, graph, node):
    if node not in visited:
        print(node)
        visited.add(node)
        for neighbor in graph[node]:
            dfs(visited, graph, neighbor)

dfs(visited, graph, 'A')