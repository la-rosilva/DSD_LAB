#include <stdio.h>
#include <limits.h>

#define N 3  // Change this for different problem sizes

// Swap function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse function to reverse part of an array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Generate next lexicographical permutation (returns 1 if next permutation exists, else 0)
int nextPermutation(int arr[], int n) {
    int k = -1, l;

    // Step 1: Find largest k such that arr[k] < arr[k+1]
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            k = i;
            break;
        }
    }

    // If no such k exists, this was the last permutation
    if (k == -1) {
        reverse(arr, 0, n - 1);
        return 0;
    }

    // Step 2: Find largest l such that arr[l] > arr[k]
    for (l = n - 1; l > k; l--) {
        if (arr[l] > arr[k]) {
            break;
        }
    }

    // Step 3: Swap arr[k] and arr[l]
    swap(&arr[k], &arr[l]);

    // Step 4: Reverse sequence after k
    reverse(arr, k + 1, n - 1);

    return 1;  // Indicates a new permutation was generated
}

// Calculate cost for a given assignment permutation
int calculateCost(int costMatrix[N][N], int perm[]) {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost += costMatrix[i][perm[i]];  // Worker i assigned to Task perm[i]
    }
    return cost;
}

// Solve the assignment problem using brute force (iterative approach)
void solveAssignmentProblem(int costMatrix[N][N]) {
    int perm[N];  // Array to store the current permutation
    int minCost = INT_MAX;  // Initialize minimum cost to a large value
    int bestPerm[N];  // Store the best assignment

    // Step 1: Initialize permutation {0, 1, 2, ..., N-1}
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }

    // Step 2: Generate all permutations and find the minimum cost
    do {
        int cost = calculateCost(costMatrix, perm);

        // If a better (lower cost) assignment is found, update minCost
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < N; i++) {
                bestPerm[i] = perm[i];
            }
        }

    } while (nextPermutation(perm, N));  // Generate next permutation iteratively

    // Step 3: Print result
    printf("Minimum Cost: %d\n", minCost);
    printf("Optimal Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i, bestPerm[i]);
    }
}

// Main function
int main() {
    // Example cost matrix
    int costMatrix[N][N] = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };

    // Solve the assignment problem using brute force
    solveAssignmentProblem(costMatrix);

    return 0;
}
