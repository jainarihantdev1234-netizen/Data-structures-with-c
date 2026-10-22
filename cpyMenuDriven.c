#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct LL{
    struct node *head,*tail;

};
struct LL *newLL(){
    struct LL *l1 = (struct LL*)malloc(sizeof(struct LL));
    l1->head = NULL;
    
    return l1;
}
void insertAtEnd(struct LL *l1,int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(l1->head == NULL){
        l1->head->val = val;
        l1->head->next = NULL;
        return;
    }
    struct node *itr = l1->head;
    while(itr->next != NULL){
        itr = itr->next;
    }
    temp->val = val;
    itr->next = temp;
    temp->next = NULL;
    return;
    
}
void display(struct LL *l1)
{
    struct node *temp = l1->head;
    while (temp != NULL)
    {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){
    struct LL* l1 = newLL();
    printf("Enter number : \n");
    int n;
    scanf("%d",&n);
    insertAtEnd(l1,n);
    display(l1);
    

}