#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL){
        return 0;
    }
    else{
        nn->data=data;
        nn->next=NULL;
    }
    return nn;
};
struct Node* head=NULL;
struct Node* last=NULL;

struct Node* insert_front(int data){
    struct Node* newnode=create_node(data);
    if(head==NULL){
        head=last=newnode;
    }
    else{
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
};

void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

void split(struct Node* head, struct Node** a, struct Node** b) {
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}


void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL)
        return;

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

int main(){
    insert_front(-1);
    insert_front(5);
    insert_front(3);
        insert_front(4);
            insert_front(0);
    display();
    mergeSort(&head);
    printf("\n");
    display();
}
