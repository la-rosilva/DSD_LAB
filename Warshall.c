#include <stdio.h>

#define V 4  // Number of vertices

// Function to compute transitive closure using Warshall's Algorithm
void warshallTransitiveClosure(int graph[V][V]) {
    int reach[V][V];  // Reachability matrix

    // Initialize reachability matrix with input graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];  // Copy graph
        }
    }

    // Apply Warshall's Algorithm
    for (int k = 0; k < V; k++) {  // Intermediate vertex
        for (int i = 0; i < V; i++) {  // Source vertex
            for (int j = 0; j < V; j++) {  // Destination vertex
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    printf("\nTransitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    printf("Input Graph (Adjacency Matrix):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    warshallTransitiveClosure(graph);
    
    return 0;
}
