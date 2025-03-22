#include <stdio.h>

#define V 4  // Number of vertices
#define INF 99999  // Representation of infinity (no direct path)

// Function to find shortest distances using Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];  // Distance matrix

    // Initialize distance matrix with input graph values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {  // Intermediate vertex
        for (int i = 0; i < V; i++) {  // Source vertex
            for (int j = 0; j < V; j++) {  // Destination vertex
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%4s ", "INF");
            else
                printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    printf("Input Graph (Adjacency Matrix with Weights):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%4s ", "INF");
            else
                printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }

    floydWarshall(graph);

    return 0;
}
