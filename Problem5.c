#include <stdio.h>
#include <stdlib.h>

/* Linked list node */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

/* Insert at end */
void insertEnd(struct Node** head, int data) {
    struct Node* nn = createNode(data);

    if (*head == NULL) {
        *head = nn;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
}

/* Display list */
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* GCD function */
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/* Insert GCD nodes */
void insertGCD(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        int g = gcd(curr->data, curr->next->data);

        struct Node* nn = createNode(g);
        nn->next = curr->next;
        curr->next = nn;

        curr = nn->next;
    }
}

/* Main function */
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 18);
    insertEnd(&head, 6);
    insertEnd(&head, 10);
    insertEnd(&head, 3);

    printf("Original List:\n");
    display(head);

    insertGCD(head);

    printf("\nList after inserting GCDs:\n");
    display(head);

    return 0;
}
