#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Create new node */
struct ListNode* createNode(int val) {
    struct ListNode* nn = (struct ListNode*)malloc(sizeof(struct ListNode));
    nn->val = val;
    nn->next = NULL;
    return nn;
}

/* Insert at end */
void insertEnd(struct ListNode** head, int val) {
    struct ListNode* nn = createNode(val);

    if (*head == NULL) {
        *head = nn;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
}

/* Display list */
void display(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

/* Merge list2 into list1 between a and b */
struct ListNode* mergeInBetween(
    struct ListNode* list1,
    int a,
    int b,
    struct ListNode* list2
) {
    struct ListNode* prevA = list1;
    struct ListNode* afterB = list1;

    /* Move prevA to node before index a */
    for (int i = 0; i < a - 1; i++)
        prevA = prevA->next;

    /* Move afterB to node after index b */
    for (int i = 0; i <= b; i++)
        afterB = afterB->next;

    /* Connect prevA to list2 */
    prevA->next = list2;

    /* Find tail of list2 */
    struct ListNode* tail = list2;
    while (tail->next != NULL)
        tail = tail->next;

    /* Connect tail to remaining list1 */
    tail->next = afterB;

    return list1;
}

/* -------- MAIN FUNCTION -------- */
int main() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    /* list1 = [0,1,2,3,4,5] */
    insertEnd(&list1, 0);
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);
    insertEnd(&list1, 4);
    insertEnd(&list1, 5);

    /* list2 = [1000000,1000001,1000002] */
    insertEnd(&list2, 1000000);
    insertEnd(&list2, 1000001);
    insertEnd(&list2, 1000002);

    printf("List1:\n");
    display(list1);

    printf("\nList2:\n");
    display(list2);

    /* Merge list2 into list1 from index a=3 to b=4 */
    list1 = mergeInBetween(list1, 3, 4, list2);

    printf("\nAfter Merge:\n");
    display(list1);

    return 0;
}
