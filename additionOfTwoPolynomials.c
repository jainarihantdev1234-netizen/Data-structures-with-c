#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int co,exp;
    struct Node* next;
}Node;

void createPolynomial(Node** head,int coef,int exp){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->co = coef;
    temp->exp = exp;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
    }
    else{
        Node* itr = *head;
        while(itr->next != NULL){
            itr = itr->next;
        }
        itr->next = temp;
    }
}

void input(Node** head){
    int co;
    int pow;
    do{
        printf("Enter coefficient and power ");
        scanf("%d%d",&co,&pow);
        createPolynomial(head,co,pow);
    }while(pow!=0);
    return;
}

// Node* addPolynomial(Node** head1,Node** head2){
    
// while(*head1 != NULL && *head2 != NULL){
//     if((*head1)->exp > (*head2)->exp){
//         createPolynomial(head1,(*head1)->co,(*head1)->exp);
//         *head1 = (*head1)->next;
//     }
//     else if ((*head1)->exp < (*head2)->exp){
//         createPolynomial(head2, (*head2)->co, (*head2)->exp);
//         *head2 = (*head2)->next;
//     }
//     else{
//         createPolynomial(head1, (*head1)->co + (*head2)->co, (*head1)->exp);
//         head1 = (*head1)->next;
//         *head2 = (*head2)->next;
//     }
// }

// display(head1);
// }
void display(Node* head){
    while(head != NULL){
        if(head->exp != 0){
            printf("%d x^%d + ",head->co,head->exp);
        }
        else{
            printf("%d \n", head->co, head->exp);
        }
        head = head->next;
    }
}

void addPolynomial(Node **head1, Node **head2)
{
    Node** ptr;
    
    Node* itr1 = *head1;
    Node* itr2 = *head2;

    if((*head1)->exp >= (*head2)->exp){
        ptr = head1;
    }
    else{
        ptr = head2;
    }
    Node* dest = *ptr;

    while(itr1 != NULL && itr2 != NULL){
        if ((itr1)->exp > (itr2)->exp)
        {
            (dest) = (dest)->next;
            itr1 = itr1->next;
        }
        else if ((itr1)->exp < (itr2)->exp)
        {
            (dest) = (dest)->next;
            itr2 = itr2->next;
                }
        else
        {
            (dest)->co = itr1->co+itr2->co;
            (dest) = (dest)->next;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
    }
    display(*ptr);

    
    
}

int main(){
Node* head1 = NULL;
Node* head2 = NULL;

printf("Enter first polunomial \n ");
input(&head1);
printf("Displaying polynomial number 1 : ");
display(head1);

printf("Enter second polunomial \n ");
input(&head2);
printf("Displaying polynomial number 1 : ");
display(head2);

printf("Adding polynomials\n");
addPolynomial(&head1,&head2);
return 0;


}