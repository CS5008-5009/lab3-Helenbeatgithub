#include <stdio.h>
#include <stdlib.h>

struct doubleNode{
    int value;
    struct doubleNode* next;
    struct doubleNode* prev;
};

void printList(struct doubleNode* node){
    while (node != NULL){
        if (node->next != NULL){
            printf("%d->", node->value);
        } else {
            printf("%d", node->value);
        }
        node = node->next;
    }
    printf("\n");
}

int search(struct doubleNode* l, int target){
    int count = 0;
    while (l != NULL){
        if(target == l->value){
            return count;
        }
        l=l->next;
        count++;
    }
    return -1;
}

void insert(struct doubleNode** head_ref, int target, int position){
    struct doubleNode* new_node = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    new_node->value = target;
    new_node->next = NULL;
    new_node->prev = NULL;

    struct doubleNode* l = *head_ref;

    if(position == 0) {  // insert at the beginning
        new_node->next = l;
        if(l != NULL)
            l->prev = new_node;
        *head_ref = new_node;
    }
    else {
        for(int i = 0; i < position; i++) {
            if(l->next == NULL || i == position - 1) { // we've arrived at the insertion point
                new_node->next = l->next;  // point new node to the node at current position
                new_node->prev = l;        // make new node point to previous node
                if (l->next != NULL)
                    l->next->prev = new_node;  // make next node point to new node
                l->next = new_node;            // make previous node point to new node
                break;
            }
            l = l->next; // traverse the list
        }
    }
}

struct doubleNode* getNode(struct doubleNode* head, int target) {
    while(head != NULL) {
        if(head->value == target)
            return head;
        head = head->next;
    }
    return NULL;
}

void deleteNode(struct doubleNode** head_ref, int target) {
    struct doubleNode* del = getNode(*head_ref, target);

    if (*head_ref == NULL || del == NULL)
        return;

    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;

    if (del == *head_ref)
        *head_ref = del->next;

    free(del);
}

void deleteHead(struct doubleNode** head_ref) {
    if (*head_ref == NULL)
        return;

    struct doubleNode* next_node = (*head_ref)->next;

    if (next_node != NULL)
        next_node->prev = NULL;

    free(*head_ref);
    *head_ref = next_node;
}

void deleteLast(struct doubleNode** head_ref) {
    if (*head_ref == NULL)
        return;

    struct doubleNode* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    if (last->prev != NULL)
        last->prev->next = NULL;
    else
        *head_ref = NULL;

    free(last);
}

int main(){
    struct doubleNode* head = NULL;
    insert(&head, 23, 0);
    insert(&head, 52, 1);
    insert(&head, 19, 2);
    insert(&head, 9, 3);
    insert(&head, 100, 4);
    
    printList(head);

    //search
    printf("Please input the value that you want to search: ");
    int target;
    scanf("%d", &target);
    int s = search(head, target);
    printf("Position: %d\n", s);

    //insert
    printf("Please input the value that you want to insert: ");
    int position;
    scanf("%d", &target);

    printf("Please input the position where you want to insert: ");
    scanf("%d", &position);
    insert(&head, target, position);
    printList(head);

    // delete
    printf("please input the value you want to delete:");
    scanf("%d", &target);
    deleteNode(&head, target);
    printList(head);

    //delete head
    printf("Delete head of the linked list\n");
    deleteHead(&head);
    printList(head);

    //delete the last element
    printf("Delete the last element of the linked list\n");
    deleteLast(&head);
    printList(head);

    return 0;
}
