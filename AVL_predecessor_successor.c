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
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicates not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

// Function to find the maximum value in a subtree (Predecessor helper)
struct Node* findMax(struct Node* node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

// Function to find the minimum value in a subtree (Successor helper)
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to find predecessor and successor
void findPredecessorSuccessor(struct Node* root, int key, struct Node** pred, struct Node** succ) {
    if (root == NULL)
        return;

    if (root->key == key) {
        // Predecessor: Max value in left subtree
        if (root->left != NULL)
            *pred = findMax(root->left);

        // Successor: Min value in right subtree
        if (root->right != NULL)
            *succ = findMin(root->right);

        return;
    }

    if (key < root->key) {
        *succ = root;
        findPredecessorSuccessor(root->left, key, pred, succ);
    } else {
        *pred = root;
        findPredecessorSuccessor(root->right, key, pred, succ);
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

    // Finding Predecessor and Successor
    struct Node* pred = NULL;
    struct Node* succ = NULL;
    printf("\n\nEnter a key to find its predecessor and successor: ");
    scanf("%d", &key);

    findPredecessorSuccessor(root, key, &pred, &succ);

    if (pred)
        printf("Predecessor of %d is %d\n", key, pred->key);
    else
        printf("No Predecessor found for %d\n", key);

    if (succ)
        printf("Successor of %d is %d\n", key, succ->key);
    else
        printf("No Successor found for %d\n", key);

    return 0;
}
