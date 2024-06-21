#include <stdio.h>
#include <stdlib.h>

// Structure definition
typedef struct node {
    int num;
    struct node* next;
} node;

// Function to create a new node
node* createNode(int num) {
    // Allocate memory for the new node
    node* newNode = (node*)malloc(sizeof(node));
    // Set the data and next pointers of the new node
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(node** head, int num) {
    // Create a new node with the given data
    node* newNode = createNode(num);
    // Set the next pointer of the new node to the current head of the list
    newNode->next = *head;
    *head = newNode;
}

// Function signature to delete every second node in the linked list
int whatDoesItDo(node *head) {
    // Handle the empty list or single node list
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    // Handle the case of a list with an odd number of nodes. This traverses the list and deletes every second node
    node* current = head;
    while (current != NULL && current->next != NULL && current->next->next != NULL) {
        // Getting the next node to be deleted
        node* next_node = current->next;
        // Skipping the next node by updating the current node's next pointer
        current->next = next_node->next;
        // Freeing the memory allocated for the skipped node
        free(next_node);
        // Moving on to the next node in the list
        current = current->next;
    }
    return 1;
}

// Function to print the linked list
void printList(node *head) {
    node* temp = head;
    // Iterate through the list and output each of the node's num
    while (temp != NULL) {
        printf("%d -> ", temp->num);
        temp = temp->next;

    }
    printf("NULL\n");
}

// Main function for testing the whatDoesItDo function 
int main() {
    node* head = NULL;
    // Test case 1: Emtpy list
    printf("Test case 1: Empty list\n");
    printf("Original list: ");
    printList(head);
    // Apply the function signature to modify the list 
    whatDoesItDo(head);            
    printf("Modified list: ");
    printList(head);

    // Test case 2: Single node list
    head = createNode(1);
    printf("\nTest case 2: Single node list\n");
    printf("Original list: ");
    printList(head);
    // Apply the function signature to modify the list
    whatDoesItDo(head);
    printf("Modified list: ");
    printList(head);
    free(head);
    head = NULL;

    // Test case 3: Two node list
    head = createNode(1);
    insertAtBeginning(&head, 2);
    printf("\nTest case 3: Two node list\n");
    printf("Original list: ");
    printList(head);
    // Apply the function signature to modify the list
    whatDoesItDo(head);
    printf("Modified list: ");
    printList(head);
    free(head);
    head = NULL;

    // Test case 4: Odd number of nodes list
    head = NULL;
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    printf("\nTest case 4: Odd number of nodes\n");
    printf("Original list: ");
    printList(head);
    // Apply the function signature to modify the list
    whatDoesItDo(head);
    printf("Modified list: ");
    printList(head);

    // Test case 5: Even number of nodes list 
    head = NULL;
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("\nTest case 5: Even number of nodes\n");
    printf("Original list: ");
    printList(head);
    // Apply the function signature to modify the list
    whatDoesItDo(head);

    // Resetting the list to have an even number of nodes
    head = NULL;
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 2);

    printf("Modified list: ");
    printList(head);

    return 0;
}