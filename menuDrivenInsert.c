#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

void insertStart(Node **head, int va)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    temp->val = va;
    temp->next = *head;
    *head = temp;

    return;
}
void insertEnd(Node **head, int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (*head == NULL)
    {
        temp->val = val;
        *head = temp;
        (*head)->next = NULL;
        return;
    }
    Node *p = *head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    temp->val = val;
    p->next = temp;
    temp->next = NULL;
    return;
}
void insertPos(Node **head, int val, int pos)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (pos == 1)
    {
        temp->val = val;
        temp->next = *head;
        *head = temp;
        return;
    }
    Node *p = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    temp->val = val;
    temp->next = p->next;
    p->next = temp;

    return;
}
void insertAfterK(Node **head, int val, int k)
{
    struct node *temp = *head;
    while (temp->val != k && temp->next != NULL)
    {
        temp = temp->next;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->val = val;
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}
void insertBeforeK(Node **head, int val, int k)
{
    struct node *temp = *head;
if((*head)->val == k){
         struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->val = val;
    newnode->next = *head;
    *head = newnode;
    return;
    }
    while (temp->next->val != k && temp->next->next != NULL)
    {
        temp = temp->next;
    }
    

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->val = val;
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}
void display(Node **head)
{

    Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteStart(struct node **head){
    if(*head == NULL){
        return;
    }
    *head = (*head)->next;
    return;
}
void deleteEnd(struct node **head){
    struct node *temp = *head;
    if(temp == NULL){
        return;
    }
    if(temp->next == NULL){
        deleteStart(head);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return;
}

void deleteAfterK(struct node **head){
if(*head == NULL){
    return;
}
Node *itr = *head;

}
int main()
{
    Node *head = NULL;
    int ch;
    char opt;
    int pos;
    int n;
    do
    {
        printf("1.Insert at Start.\n2. Insert at end.\n3.Insert at i position.\n4. Insert after k    .\n5. Insert before k.\n6. Display all the elements .\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            insertStart(&head, n);
            break;
        case 2:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            insertEnd(&head, n);
            break;
        case 3:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            printf("Enter pos to insert an element : ");
            scanf("%d", &pos);
            insertPos(&head, n, pos);
            break;
        case 4:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            printf("Enter pos after which you have to an element : ");
            scanf("%d", &pos);
            insertAfterK(&head, n, pos);
            break;
        case 5:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            printf("Enter pos before which you have to an element : ");
            scanf("%d", &pos);
            insertBeforeK(&head, n, pos);
            break;   
        case 6:
            display(&head);
            break;

        default:
            break;
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &opt);
    } while (opt == 'y' || opt == 'Y');
}