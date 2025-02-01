#include <stdio.h>
#include <stdlib.h>

#define N 5  // Number of vertices

// Queue structure for BFS
typedef struct {
    int items[N];
    int front, rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

// BFS function with adjacency matrix as input
void BFS(int **graph, int start, int *visited) {
    Queue q;
    q.front = 0;
    q.rear = -1;

    visited[start] = 1;  // Mark as visited
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);  // Print the node
        
        for (int w = 0; w < N; w++) {
            if (graph[v][w] == 1 && visited[w] == 0) {
                visited[w] = 1;  // Mark as visited
                enqueue(&q, w);
            }
        }
    }
}

int main() {
    int **graph;  
    int visited[N] = {0};  // Mark all as unvisited

    // Allocate memory for the adjacency matrix
    graph = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        graph[i] = (int *)malloc(N * sizeof(int));
    }

    // Take adjacency matrix input from the user
    printf("Enter adjacency matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform BFS traversal
    printf("BFS Traversal: ");
    for (int v = 0; v < N; v++) {
        if (visited[v] == 0) {
            BFS(graph, v, visited);
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(graph[i]);
    }
    free(graph);

    printf("\n");
    return 0;
}
