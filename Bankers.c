 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define R 3 // Number of resources (A, B, C)

void calculateNeed(int **need, int **max, int **allocation, int P) {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafeState(int *processes, int *avail, int **max, int **alloc, int P) {
    int **need = (int **)malloc(P * sizeof(int *));
    for (int i = 0; i < P; i++)
        need[i] = (int *)malloc(R * sizeof(int));
    
    calculateNeed(need, max, alloc, P);

    int work[R];
    bool *finish = (bool *)calloc(P, sizeof(bool));
    for (int i = 0; i < R; i++) work[i] = avail[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            // Free memory
            for (int i = 0; i < P; i++) free(need[i]);
            free(need);
            free(finish);
            return false; // Unsafe state
        }
    }

    for (int i = 0; i < P; i++) free(need[i]);
    free(need);
    free(finish);
    return true; // Safe state
}

void printMatrix(const char *name, int **mat, int P) {
    printf("%s Matrix:\n", name);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printVector(const char *name, int *vec) {
    printf("%s Vector: ", name);
    for (int i = 0; i < R; i++)
        printf("%d ", vec[i]);
    printf("\n\n");
}

bool requestResources(int process_num, int request[R], int *avail, int **max, int **alloc, int P) {
    int **need = (int **)malloc(P * sizeof(int *));
    for (int i = 0; i < P; i++)
        need[i] = (int *)malloc(R * sizeof(int));

    calculateNeed(need, max, alloc, P);

    printf("Request by process P%d: ", process_num);
    for (int i = 0; i < R; i++) printf("%d ", request[i]);
    printf("\n");

    // Check request <= Need
    for (int i = 0; i < R; i++) {
        if (request[i] > need[process_num][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            for (int i = 0; i < P; i++) free(need[i]);
            free(need);
            return false;
        }
    }

    // Check request <= Available
    for (int i = 0; i < R; i++) {
        if (request[i] > avail[i]) {
            printf("Resources are not available.\n");
            for (int i = 0; i < P; i++) free(need[i]);
            free(need);
            return false;
        }
    }

    // Try allocating temporarily
    for (int i = 0; i < R; i++) {
        avail[i] -= request[i];
        alloc[process_num][i] += request[i];
        need[process_num][i] -= request[i];
    }

    if (isSafeState(NULL, avail, max, alloc, P)) {
        printf("Request can be granted.\n");
        printMatrix("Allocation", alloc, P);
        calculateNeed(need, max, alloc, P);
        printMatrix("Need", need, P);
        printVector("Available", avail);

        for (int i = 0; i < P; i++) free(need[i]);
        free(need);
        return true;
    } else {
        // Rollback allocation
        for (int i = 0; i < R; i++) {
            avail[i] += request[i];
            alloc[process_num][i] -= request[i];
        }
        printf("Request cannot be granted as it leads to unsafe state.\n");
        for (int i = 0; i < P; i++) free(need[i]);
        free(need);
        return false;
    }
}

int main() {
    int P;

    printf("Enter the number of processes: ");
    scanf("%d", &P);

    // Dynamically allocate memory for matrices and vectors
    int **allocation = (int **)malloc(P * sizeof(int *));
    int **max = (int **)malloc(P * sizeof(int *));
    int **need = (int **)malloc(P * sizeof(int *));
    int *available = (int *)malloc(R * sizeof(int));
    int *processes = (int *)malloc(P * sizeof(int));

    for (int i = 0; i < P; i++) {
        allocation[i] = (int *)malloc(R * sizeof(int));
        max[i] = (int *)malloc(R * sizeof(int));
        need[i] = (int *)malloc(R * sizeof(int));
        processes[i] = i;
    }

    printf("Enter Allocation matrix (%d processes, 3 resources A B C):\n", P);
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max matrix (%d processes, 3 resources A B C):\n", P);
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &max[i][j]);

    int total_resources[R] = {10, 5, 7};  // Total system resources (fixed)bool requestResources(int process_num, int request[R], int *avail, int **max, int **alloc, int P) {
    int **need = (int **)malloc(P * sizeof(int *));
    for (int i = 0; i < P; i++)
        need[i] = (int *)malloc(R * sizeof(int));

    calculateNeed(need, max, alloc, P);

    printf("Request by process P%d: ", process_num);
    for (int i = 0; i < R; i++) printf("%d ", request[i]);
    printf("\n");

    // Check request <= Need
    for (int i = 0; i < R; i++) {
        if (request[i] > need[process_num][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            for (int i = 0; i < P; i++) free(need[i]);
            free(need);
            return false;
        }
    }

    // Calculate Available = Total - sum of Allocation
    for (int j = 0; j < R; j++) {
        int sum = 0;
        for (int i = 0; i < P; i++)
            sum += allocation[i][j];
        available[j] = total_resources[j] - sum;
    }

    calculateNeed(need, max, allocation, P);

    printMatrix("Allocation", allocation, P);
    printMatrix("Max", max, P);
    printMatrix("Need", need, P);
    printVector("Available", available);

    if (isSafeState(processes, available, max, allocation, P))
        printf("System is in a safe state.\n\n");
    else
        printf("System is NOT in a safe state.\n\n");

    // Example request from P1 (1,0,2)
    if (P > 1) {
        int req1[R] = {1, 0, 2};
        requestResources(1, req1, available, max, allocation, P);
    }

    // Example request from P4 (3,3,0) only if P > 4
    if (P > 4) {
        int req2[R] = {3, 3, 0};
        requestResources(4, req2, available, max, allocation, P);
    }

    // Example request from P0 (0,2,0)
    if (P > 0) {
        int req3[R] = {0, 2, 0};
        requestResources(0, req3, available, max, allocation, P);
    }

    // Free all allocated memory
    for (int i = 0; i < P; i++) {
        free(allocation[i]);
        free(max[i]);
        free(need[i]);
    }
    free(allocation);
    free(max);
    free(need);
    free(available);
    free(processes);

    return 0;
}

        
	
	
	
