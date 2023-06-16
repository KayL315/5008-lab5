/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rest = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    int size, num;
    printf("Input list size: ");
    scanf("%d", &size);

    printf("Input elements of the array:\n");
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        scanf("%d", &num);
        insert(&head, num);
    }

    printf("\nThe list:\n");
    printList(head);

    Node* reversedHead = reverseLinkedList(head);

    printf("\nThe reversed list:\n");
    printList(reversedHead);

    return 0;
}
