#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for an edge
struct Edge {
    int src, dest, weight;
};

// Function to print the distances
void printDistances(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Bellman-Ford algorithm function
void BellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print distances if no negative-weight cycle is found
    printDistances(dist, V);
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Predefined edges: {source, destination, weight}
    struct Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0; // Predefined source vertex

    BellmanFord(V, E, edges, src);

    return 0;
}