#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
void InsertAtBeginning(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;     }
void InsertAtEnd(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL; 
    if (*head_ref == NULL) { 
        *head_ref = new_node;
        return;     }
    while (last->next != NULL) { 
        last = last->next;
    }
    last->next = new_node;  }
void InsertAfter(struct node* head, int position) {
    struct node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position does not exist!\n");
            return;     }   }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &new_node->data);
    new_node->next = temp->next;  
    temp->next = new_node;       }
void DeleteFromBeginning(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty!\n");
        return;     }
    struct node* temp = *head_ref; 
    *head_ref = (*head_ref)->next;  
    free(temp);     }
void DeleteFromEnd(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty!\n");
        return; }
    struct node* temp = *head_ref;
    if (temp->next == NULL) { 
        free(temp);
        *head_ref = NULL;
        return; }
    while (temp->next->next != NULL) {  
        temp = temp->next;
    }
    free(temp->next); 
    temp->next = NULL;  }
void DeleteFromPosition(struct node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty!\n");
        return;     }
    struct node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next;  
        free(temp);
        return;     }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;  }
    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist!\n");
        return;     }
    struct node* next_node = temp->next->next;
    free(temp->next);
    temp->next = next_node; }
void PrintList(struct node* node) {
    if (node == NULL) {
        printf("List is empty!\n");
        return; }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;  }
    printf("NULL\n");   }
int main() {
    struct node* head = NULL;
    int ch, data, position;
    do {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after a Given Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from a Given Position\n");
        printf("7. Print Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                InsertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                InsertAtEnd(&head, data);
                break; 
            case 3:
                printf("Enter the position after which to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAfter(head, data);
                break;
            case 4:
                DeleteFromBeginning(&head);
                break;
            case 5:
                DeleteFromEnd(&head);
                break;
            case 6:
                printf("Enter the position from which to delete: ");
                scanf("%d", &position);
                DeleteFromPosition(&head, position);
                break;
            case 7:
                printf("The linked list is: ");
                PrintList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                break;   }
    } while (ch != 8);
    printf("The code is executed by MAYANK MAURYA");
    printf("2300971640048\n");
    return 0;       }
