#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;

}Node;


void insertAtBeg(Node** head,Node** tail){
    int x;
    printf("Enter the value to insert : ");
    scanf("%d",&x);

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = x;

    if((*head) == NULL){
        temp->next = temp;
        temp->prev = temp;
        *head = *tail = temp;
    }
    else{
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
        (*tail)->next = *head;
        temp->prev = *tail;
    }
    return;
}

void deleteAtBeg(Node **head, Node **tail)
{
    

    

    if ((*head) == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }
    else if((*head) == (*tail)){
        (*head) = (*tail) = NULL;
        return;
    }
    else
    {
        (*head) = (*head)->next;
        (*head)->prev = *tail;
        (*tail)->next = (*head);

    }
    return;
}

void insertionAtEnd(Node** head,Node** tail){
    
    if ((*head) == NULL)
    {
        insertAtBeg(&head, &tail);
        return;
    }
    int x;
    printf("Enter the val :");
    scanf("%d", &x);
    
}

void display(Node *head, Node *tail)
{
    if(head == NULL){
        printf("LinkedList is EMpty!\n");
        return;
    }
    else if(head->next->val == head->val){
        printf("%d-><-",head->val);
        return;
    }
    else{
        printf("%d-><-", head->val);
        Node* temp = head->next;
        while(temp != head){
            printf("%d-><-", temp->val);
            temp = temp->next;
        }

    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtBeg(&head, &tail);
    insertAtBeg(&head, &tail);
    insertAtBeg(&head, &tail);
    insertAtBeg(&head, &tail);
    insertAtBeg(&head, &tail);
    deleteAtBeg(&head, &tail);

    display(head,tail);

}