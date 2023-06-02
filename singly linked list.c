#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int value;
    struct Node* next;
    struct doubleNode* prev;
};


// // doubly linked list
// struct doubleNode{
//     int value;
//     struct doubleNode* next;
//     struct doubleNode* pre;
// };
// //------------doubly

void printList(struct Node* l){
    while (l != NULL){
        if (l->next == NULL){
            printf("%d", l->value);
        }else{
            printf("%d->", l->value);
        }
        l = l->next;
    }
    printf("\n"); // Add a new line at the end for readability
}

int search(struct Node* l, int target){
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

void insert(struct Node* l, int target, int position){
    struct Node* c;
    c = (struct Node*)malloc(sizeof(struct Node));
    c->value = target;
    c->next = NULL;
    
    for (int i = 0; i < position - 2; i ++ )
        l = l->next;
    c -> next = l->next;
    l->next = c;
    
}

void deleteNode(struct Node **head_ref, int target)
{
    struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->value == target) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}



void deleteHead(struct Node** head_ref){
    if (*head_ref == NULL){
        printf("Head is empty due to the list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref) -> next;

    free(temp);
}



void deleteLast(struct Node** head) {
    //list is NULL
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    //head is the only element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }


    //normal linked list
    struct Node* second_last = *head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);

    second_last->next = NULL;
}




int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    
    
    // //------------doubly linked list
    // struct doubleNode* dhead = NULL;
    
    // dhead = (struct doubleNode*)malloc(sizeof(struct doubleNodeNode));
    
    // dhead->value = 55;
    // dhead->pre = NULL;
    // dhead->next = NULL;
    
    
    //--------------
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory has been successfully allocated
    if(head == NULL || second == NULL || third == NULL || fourth == NULL || fifth == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->value = 23;
    head->next = second;
    
    second->value = 52;
    second->next = third;
    
    third->value = 19;
    third->next = fourth;
    
    fourth->value = 9;
    fourth->next = fifth;
    
    fifth->value = 100;
    fifth->next = NULL;
    
    printList(head);
    
    //search
    printf("Please input the value that you want to search: ");
    int target;
    scanf("%d", &target); // Use '%d' and '&target'
    int s = search(head, target);
    printf("Position: %d\n", s);
    
    //insert
    printf("Please input the value that you want to insert: ");
    target;
    int position;
    scanf("%d", &target); // Use '%d' and '&target'
    
    printf("Please input the value that you want to insert at: ");
    scanf("%d", &position); // Use '%d' and '&target'
    insert(head, target, position);
    printList(head);
    
    
    // delete
    printf("please input the value you want to delete:");
    scanf("%d", &target);
    deleteNode(&head, target);
    printList(head);
    
    //delete head
    //delete head
printf("Delete head of the linked list\n");
deleteHead(&head);
printList(head);
    
    //delete the last element
    printf("Delete the last element of the linked list");
    deleteLast(&head);
    printList(head);
    
    // Free the allocated memory
    free(fifth);
    free(fourth);
    free(third);
    free(second);
    free(head);

    return 0;
}
