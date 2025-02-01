#include <stdio.h>
#include <stdlib.h>

#define N 5  // Number of vertices

int visited[N];  // Track visit order (0 = unvisited)
int count = 0;   // Global counter for marking visit order
int pushOrder[N], popOrder[N], pushIndex = 0, popIndex = 0;

// Depth-First Search function
void DFS(int **graph, int v) {
    visited[v] = ++count;  // Mark vertex with encounter number
    pushOrder[pushIndex++] = v; // Store push order
    
    for (int w = 0; w < N; w++) {  
        if (graph[v][w] == 1 && visited[w] == 0) {  // If w is adjacent and unvisited
            DFS(graph, w);
        }
    }
    
    popOrder[popIndex++] = v; // Store pop order when backtracking
}

int main() {
    int **graph;  

    // Allocate memory for adjacency matrix
    graph = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        graph[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // Take adjacency matrix input from user
    printf("Enter adjacency matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform DFS for each unvisited node
    for (int v = 0; v < N; v++) {
        if (visited[v] == 0) {
            DFS(graph, v);
        }
    }

    // Display Push Order (order of first visit)
    printf("Push Order: ");
    for (int i = 0; i < pushIndex; i++) {
        printf("%d ", pushOrder[i]);
    }
    printf("\n");

    // Display Pop Order (order of completion)
    printf("Pop Order: ");
    for (int i = 0; i < popIndex; i++) {
        printf("%d ", popOrder[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
