#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Function to swap two edges
void swap(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify to maintain the min-heap property
void heapify(Edge heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is smaller than the current smallest
    if (left < n && heap[left].weight < heap[smallest].weight)
        smallest = left;

    // Check if right child exists and is smaller than the current smallest
    if (right < n && heap[right].weight < heap[smallest].weight)
        smallest = right;

    // If the smallest is not the current node, swap and continue heapifying
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Function to extract the minimum element (root) from the heap
Edge extractMin(Edge heap[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        exit(1);  // Error if heap is empty
    }
    
    // The root of the heap is the minimum element
    Edge root = heap[0];
    
    // Replace the root with the last element
    heap[0] = heap[*n - 1];
    (*n)--;  // Reduce the heap size
    
    // Heapify the root to maintain the heap property
    heapify(heap, *n, 0);
    
    return root;
}

// Find function to determine the root of the set a vertex belongs to
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;  // If no parent, this node is the root
    }
    // Path compression: Make every node in the set point directly to the root
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Union function to merge two sets
void unionSets(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    // Attach the tree of one set to the other
    if (xroot != yroot) {
        parent[xroot] = yroot;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(Edge edges[], int n, int m) {
    // Build a min-heap from the edges array
    Edge heap[m];
    for (int i = 0; i < m; i++) {
        heap[i] = edges[i];
    }

    // Convert the array into a min-heap
    for (int i = m / 2 - 1; i >= 0; i--) {
        heapify(heap, m, i);
    }

    // Parent array for Union-Find
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;  // Initially, each node is its own parent
    }

    printf("Edges in the MST:\n");
    int mstWeight = 0;  // To store the total weight of the MST
    int mstEdges = 0;   // To count the edges in the MST

    // Process each edge in increasing order of weight (min-heap gives us the smallest edge)
    while (mstEdges < n - 1) {
        Edge minEdge = extractMin(heap, &m);  // Extract the minimum edge from the heap
        int u = minEdge.u;
        int v = minEdge.v;
        int weight = minEdge.weight;

        // If u and v belong to different sets, include this edge in the MST
        if (find(parent, u) != find(parent, v)) {
            printf("%d -- %d == %d\n", u, v, weight);
            mstWeight += weight;
            mstEdges++;
            unionSets(parent, u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n, m;

    // Read number of vertices and edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Array of edges
    Edge edges[m];

    // Read the edges (u, v, weight)
    printf("Enter edges (u, v, weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Call Kruskal's algorithm to find the MST
    kruskal(edges, n, m);

    return 0;
}