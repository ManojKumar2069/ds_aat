/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(
    struct ListNode* list1,
    int a,
    int b,
    struct ListNode* list2
) {
    struct ListNode* prevA = list1;
    struct ListNode* afterB = list1;

    // Move prevA to node just before index a
    for (int i = 0; i < a - 1; i++) {
        prevA = prevA->next;
    }

    // Move afterB to node just after index b
    for (int i = 0; i <= b; i++) {
        afterB = afterB->next;
    }

    // Connect prevA to list2
    prevA->next = list2;

    // Find tail of list2
    struct ListNode* tail = list2;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Connect tail of list2 to afterB
    tail->next = afterB;

    return list1;
}
