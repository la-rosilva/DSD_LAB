#include <stdio.h>

#define N 5  // Number of vertices

int graph[N][N] = { // Adjacency Matrix Representation
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

int visited[N];  // Array to track visit order (0 means unvisited)
int count = 0;   // Global counter for marking visit order
int pushOrder[N], popOrder[N], pushIndex = 0, popIndex = 0;

void DFS(int v) {
    visited[v] = ++count;  // Mark vertex with encounter number
    pushOrder[pushIndex++] = v; // Store push order
    
    for (int w = 0; w < N; w++) {  
        if (graph[v][w] == 1 && visited[w] == 0) {  // If w is adjacent and unvisited
            DFS(w);
        }
    }
    
    popOrder[popIndex++] = v; // Store pop order when backtracking
}

int main() {
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // Perform DFS for each unvisited node
    for (int v = 0; v < N; v++) {
        if (visited[v] == 0) {
            DFS(v);
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

    return 0;
}
