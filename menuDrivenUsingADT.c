#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

struct LL
{
    struct node *head, *tail;
};

struct LL *newLL()
{
    struct LL *temp = (struct LL *)malloc(sizeof(struct LL));
    temp->head = temp->tail = NULL;
    return temp;
}

struct node *newnode(int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = n;
    temp->next = NULL;
    return temp;
}
void insertStart(struct LL *l1, int val)
{
    Node *temp = newnode(val);
    temp->next = l1->head;
    l1->head = temp;

    return;
}

void insertEnd(struct LL *l1, int val)
{
    Node *temp = newnode(val);
    if (l1->head == NULL)
    {
        l1->head = temp;
        return;
    }

    Node *p = l1->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return;
}
void display(struct LL *l1)
{
    Node *temp = l1->head;
    while (temp != NULL)
    {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL");
}

void insertPos(struct LL *l1, int val, int pos)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (pos == 1)
    {
        temp->val = val;
        temp->next = l1->head;
        l1->head = temp;
        return;
    }
    Node *p = l1->head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    temp->val = val;
    temp->next = p->next;
    p->next = temp;

    return;
}
int main()
{
    struct LL *l1 = newLL();
    int ch;
    char opt;
    int pos;
    int n;

    do
    {

        printf("1.Insert at Start.\n2. Insert at end.\n3.Insert at i position.\n4. Display all the elements .\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            insertStart(l1, n);
            break;
        case 2:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            insertEnd(l1, n);
            break;
        case 3:
            printf("Enter Element to insert in the list :  ");
            scanf("%d", &n);
            printf("Enter pos to insert an element : ");
            scanf("%d", &pos);
            insertPos(l1, n, pos);
            break;
        case 4:
            display(l1);
            break;
        default:
            break;
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &opt);
    } while (opt == 'y' || opt == 'Y');
}