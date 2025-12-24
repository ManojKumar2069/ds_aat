#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create node */
struct Node* createNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

/* Insert at end (circular) */
void insertEnd(struct Node** head, int data) {
    struct Node* nn = createNode(data);

    if (*head == NULL) {
        *head = nn;
        nn->next = nn;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = nn;
    nn->next = *head;
}

/* Display circular list */
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Split circular linked list */
void splitList(struct Node* head, struct Node** head1, struct Node** head2) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    /* Make first half circular */
    slow->next = *head1;

    /* Make second half circular */
    if (fast->next == head)
        fast->next = *head2;
    else
        fast->next->next = *head2;
}

/* Driver code */
int main() {
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    /* Example: [3,6,1,3,2] */
    insertEnd(&head, 3);
    insertEnd(&head, 6);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 2);

    printf("Original List:\n");
    display(head);

    splitList(head, &first, &second);

    printf("First Half:\n");
    display(first);

    printf("Second Half:\n");
    display(second);

    return 0;
}
