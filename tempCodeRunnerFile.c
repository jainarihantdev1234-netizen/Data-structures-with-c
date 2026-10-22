#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

Node* insertStart(Node* head,int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    
        temp->val = val;
        temp->next = head;
        head = temp;
    
    return head;

}
int main(){
Node* head = NULL;
head = insertStart(head,5);
printf("%d",head->val);
}