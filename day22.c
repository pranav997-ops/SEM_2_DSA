Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure for a linked list node
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

// Function to insert a node at the end of the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    // Traverse the list and increment the counter for each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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
    int n, value;
    struct Node* head = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Read the elements and append them to the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    // Print the list (matching your example output)
    traverseAndPrint(head);
    
    // If you need the program to output the count instead, 
    // you would replace the traverseAndPrint call with this:
    // printf("Total nodes: %d\n", countNodes(head));

    // Free the dynamically allocated memory
    freeList(head);

    return 0;
}