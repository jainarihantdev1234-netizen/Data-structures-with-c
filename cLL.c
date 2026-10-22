// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node{
//     int val;
//     struct Node* next;

// }Node;

// void insertAtHead(Node **head, Node **tail,int x)
// {
//     // int x;
//     // printf("ENter value : ");
//     // scanf("%d",&x);
//     Node* temp = (Node*)malloc(sizeof(Node));
//     temp->val = x;
//     temp->next = NULL;
// // 
//     if(*head == NULL){
//         *head = *tail = temp;
//         (*tail)->next  = *head;
//     }
//     else{
//         temp->next = *head;
//         *head = temp;
//         (*tail)->next = *head;
//     }
// }

// void insertAtEnd(Node** head,Node** tail){
//     int x;
//     printf("ENter value for end: ");
//     scanf("%d", &x);
//     Node *temp = (Node *)malloc(sizeof(Node));
//     temp->val = x;
//     temp->next = NULL;

//     if (*head == NULL)
//     {
//         *head = *tail = temp;
//         (*tail)->next = *head;
//     }
//     else
//     {
//         (*tail)->next = temp;
//         *tail = temp;
//         (*tail)->next = *head;
//     }
// }

// void insertAtK(Node **head, Node **tail)
// {
//     int k;
//     printf("Enter position to insert the value : ");
//     scanf("%d", &k);
//     int x;
//     printf("ENter value : ");
//     scanf("%d", &x);
//     Node *temp = (Node *)malloc(sizeof(Node));
//     temp->val = x;
    

//     if(k == 1 || *head ==  NULL){
//         insertAtHead(&head,&tail);
//         return;
//     }
//     else
//     {
//         int traversed = 0;
//         Node* itr = *head;
//         for(int i = 1;(i <k - 1) && (itr != *head);i++){
//             itr = itr->next;
//             traversed = 1;
//         }
//         if(itr == *head && traversed == 1){
//             printf("Invalid Position\n");
//             return;
//         }
//         temp->next = itr->next;
//         itr->next = temp;
//     }
// }

// void display(Node* head,Node* tail){
    
//     if(head == tail){
//         printf("%d ->",head->val);
//     }else{
        
//             Node* itr = head;
//             while(itr != tail){
//                 printf("%d -> ",itr->val);
//                 itr = itr->next;
//             }
            
//             printf("%d ->",itr->val);
        
//     }
//     return;
// }


// void deleteAtBeginning(Node** head,Node** tail){
//     if(*head == NULL){
//         printf("List is Empty\n");
//         return;
//     }
//     *head = (*head)->next;
//     (*tail)->next = *head;

// }

// // void deleteAtEnd(Node** head,Node** tail){
// //     if (*head == NULL)
// //     {
// //         printf("List is Empty\n");
// //         return;
// //     }
// //     Node*
// // }
// int main(){
//     Node* head = NULL;
//     Node* tail = NULL;
    
//     insertAtHead(&head, &tail,20);
//     display(head,tail);

//     return 0;

// }

// // int * ans = x;
// // int **ans = &x;