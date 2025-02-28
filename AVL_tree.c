#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int height(struct Node *N) {
    return (N == NULL) ? 0 : N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node* N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node* insert(struct Node* root, int key) {
    struct Node* new_node = newNode(key);
    struct Node* parent = NULL;
    struct Node* current = root;
    
    // Step 1: Normal BST insertion (iterative)
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return root;  // Duplicate keys not allowed
    }

    // Insert new node
    if (parent == NULL) 
        return new_node;  // Tree was empty
    if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;

    // Step 2: Backtracking to update heights and rebalance
    current = root;
    struct Node* stack[100];  // Stack for backtracking
    int top = -1;
    
    while (current != NULL) {
        stack[++top] = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    while (top >= 0) {
        struct Node* node = stack[top--];
        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        // Perform rotations
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    
    return root;
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int key;
    char choice;
    
    printf("Enter values to insert into AVL tree (Enter 'n' to stop):\n");
    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &key) != 1) break;
        root = insert(root, key);
        printf("Do you want to enter more (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
            break;
    }
    
    printf("\nPreorder traversal of the AVL tree: \n");
    preOrder(root);
    return 0;
}
