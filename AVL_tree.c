#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

// Function to get the height of a node
int height(Node *node) {
    return node ? node->height : 0;
}

// Function to update the height of a node
void updateHeight(Node *node) {
    if (node)
        node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}

// Function to get the balance factor of a node
int getBalance(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right Rotation (for Left Heavy case)
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left Rotation (for Right Heavy case)
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance the node
Node* balanceNode(Node *node) {
    updateHeight(node);
    int balance = getBalance(node);

    // Left Heavy (Right Rotation)
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left-Right Case (Left-Right Rotation)
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Heavy (Left Rotation)
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right-Left Case (Right-Left Rotation)
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Iterative AVL Tree Insertion
Node* insert(Node *root, int key) {
    if (!root) return createNode(key);

    Node *stack[100];  // Explicit stack for iterative traversal
    int top = -1;
    Node *curr = root, *parent = NULL;

    while (curr) {
        stack[++top] = curr;  // Store the path
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else
            return root;  // Duplicate keys are not allowed
    }

    // Insert new node
    if (key < parent->key)
        parent->left = createNode(key);
    else
        parent->right = createNode(key);

    // Rebalance while traversing back
    while (top >= 0) {
        stack[top] = balanceNode(stack[top]);
        if (top > 0) {
            if (stack[top - 1]->left == stack[top])
                stack[top - 1]->left = stack[top];
            else
                stack[top - 1]->right = stack[top];
        }
        top--;
    }

    return stack[0];  // New root of AVL tree
}

// In-order traversal (for debugging)
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Driver code to take user input
int main() {
    Node *root = NULL;
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
