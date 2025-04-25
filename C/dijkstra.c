#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the solution
void printSolution(int dist[]) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm function
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // The output array. dist[i] holds the shortest distance from src to i
    bool sptSet[V];   // sptSet[i] is true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0; // Starting node
    printf("Dijkstra's shortest path algorithm from source %d:\n", source);
    dijkstra(graph, source);

    return 0;
}