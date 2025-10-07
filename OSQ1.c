#include <stdio.h>
#include <stdlib.h>

struct mab {
    int offset;
    int size;
    int allocated;
    struct mab *next;
    struct mab *prev;
};

typedef struct mab Mab;
typedef Mab* MabPtr;

typedef enum {
    FIRST_FIT,
    BEST_FIT,
    WORST_FIT
} AllocationPolicy;

MabPtr memChk(MabPtr head, int size, AllocationPolicy policy) {
    MabPtr current = head;
    MabPtr candidate = NULL;

    switch (policy) {
        case FIRST_FIT:
            while (current != NULL) {
                if (!current->allocated && current->size >= size) {
                    return current; // first fit found
                }
                current = current->next;
            }
            break;

        case BEST_FIT:
            while (current != NULL) {
                if (!current->allocated && current->size >= size) {
                    if (candidate == NULL || current->size < candidate->size) {
                        candidate = current; // better fit found
                    }
                }
                current = current->next;
            }
            return candidate;
            break;

        case WORST_FIT:
            while (current != NULL) {
                if (!current->allocated && current->size >= size) {
                    if (candidate == NULL || current->size > candidate->size) {
                        candidate = current; // bigger block found
                    }
                }
                current = current->next;
            }
            return candidate;
            break;

        default:
            printf("Unknown allocation policy\n");
            return NULL;
    }

    return NULL; // no suitable block found
}

MabPtr memSplit(MabPtr block, int size) {
    if (block->size <= size) {
        return block;
    }

    MabPtr new_block = (MabPtr)malloc(sizeof(Mab));
    if (!new_block) {
        perror("Failed to allocate memory for split");
        return NULL;
    }

    new_block->offset = block->offset + size;
    new_block->size = block->size - size;
    new_block->allocated = 0;
    new_block->next = block->next;
    new_block->prev = block;

    if (block->next != NULL) {
        block->next->prev = new_block;
    }
    block->next = new_block;

    block->size = size;

    return block;
}

MabPtr memAlloc(MabPtr head, int size, AllocationPolicy policy) {
    MabPtr block = memChk(head, size, policy);
    if (block == NULL) {
        printf("No suitable block found for allocation\n");
        return NULL;
    }

    block = memSplit(block, size);
    if (!block) {
        return NULL;
    }

    block->allocated = 1;
    return block;
}

MabPtr memMerge(MabPtr block) {
    if (block == NULL) return NULL;

    while (block->next != NULL && !block->next->allocated) {
        MabPtr next_block = block->next;

        block->size += next_block->size;
        block->next = next_block->next;
        if (next_block->next != NULL) {
            next_block->next->prev = block;
        }
        free(next_block);
    }
    return block;
}

MabPtr memFree(MabPtr block) {
    if (block == NULL) return NULL;

    block->allocated = 0;
    block = memMerge(block);
    if (block->prev != NULL && !block->prev->allocated) {
        block = memMerge(block->prev);
    }
    return block;
}

void printMemory(MabPtr head) {
    MabPtr current = head;
    printf("Memory Blocks:\n");
    while (current != NULL) {
        printf("Offset: %d, Size: %d, %s\n",
               current->offset, current->size,
               current->allocated ? "Allocated" : "Free");
        current = current->next;
    }
    printf("\n");
}

int main() {
    MabPtr head = (MabPtr)malloc(sizeof(Mab));
    head->offset = 0;
    head->size = 1000;
    head->allocated = 0;
    head->next = NULL;
    head->prev = NULL;

    printMemory(head);

    // Use different policies
    AllocationPolicy policy = FIRST_FIT;

    printf("Using First Fit Policy\n");
    MabPtr a = memAlloc(head, 100, policy);
    if (a) printf("Allocated 100 bytes at offset %d\n", a->offset);
    printMemory(head);

    policy = BEST_FIT;
    printf("Using Best Fit Policy\n");
    MabPtr b = memAlloc(head, 200, policy);
    if (b) printf("Allocated 200 bytes at offset %d\n", b->offset);
    printMemory(head);

    policy = WORST_FIT;
    printf("Using Worst Fit Policy\n");
    MabPtr c = memAlloc(head, 50, policy);
    if (c) printf("Allocated 50 bytes at offset %d\n", c->offset);
    printMemory(head);

    memFree(a);
    printf("Freed 100-byte block\n");
    printMemory(head);

    memFree(b);
    memFree(c);
    printf("Freed remaining blocks\n");
    printMemory(head);

    while (head != NULL) {
        MabPtr temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
