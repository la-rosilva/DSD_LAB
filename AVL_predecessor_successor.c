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

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    
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
    return node;
}

// Function to find the predecessor and successor
void findPreSuc(struct Node* root, struct Node** pre, struct Node** suc, int key) {
    if (root == NULL)
        return;
    
    if (root->key == key) {
        if (root->left != NULL) {
            struct Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            *pre = temp;
        }

        if (root->right != NULL) {
            struct Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            *suc = temp;
        }
        return;
    }

    if (root->key > key) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
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
    
    printf("\n\nEnter key to find predecessor and successor: ");
    scanf("%d", &key);

    struct Node *pre = NULL, *suc = NULL;
    findPreSuc(root, &pre, &suc, key);

    if (pre != NULL)
        printf("Predecessor: %d\n", pre->key);
    else
        printf("No Predecessor\n");

    if (suc != NULL)
        printf("Successor: %d\n", suc->key);
    else
        printf("No Successor\n");

    return 0;
}
