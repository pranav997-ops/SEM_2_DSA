Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;        // Temporary node to anchor the merged list
    struct Node* tail = &dummy; // Pointer used to build the new list
    dummy.next = NULL;

    // Traverse both lists and link the smaller node to the tail
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // Advance the tail pointer
    }

    // If there are remaining nodes in either list, attach them directly
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    // Return the actual head of the merged list (skipping the dummy node)
    return dummy.next;
}

// Function to traverse and print the linked list
void traverseAndPrint(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* tail1 = NULL;
    struct Node* list2 = NULL;
    struct Node* tail2 = NULL;

    // Read the first list
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list1 == NULL) {
            list1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    // Read the second list
    if (scanf("%d", &m) != 1) return 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list2 == NULL) {
            list2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Merge the two lists
    struct Node* mergedList = mergeLists(list1, list2);

    // Print the merged list
    traverseAndPrint(mergedList);

    // Free the dynamically allocated memory
    freeList(mergedList);

    return 0;
}