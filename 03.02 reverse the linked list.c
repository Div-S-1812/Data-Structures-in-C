//code to reverse a linked list 
#include <stdio.h> 
#include <stdlib.h> 

//defining the structure 
struct node{
    int data; 
    struct node* next; 
}*headerNODE; 

//function to create a linked list 
void createLIST(int n){
    headerNODE=(struct node* )malloc(sizeof(struct node));

    if(headerNODE==NULL){
        printf("Error, memory not allocated");
    }

    else{
        struct node* ptr=headerNODE; 
        struct node* nextNODE;

        //creating first node
        printf("Data 1: "); 
        scanf("%d", &headerNODE->data); 
        headerNODE->next=NULL;

        //creating next n nodes 
        for(int i=2; i<=n; i++){
            nextNODE=(struct node* )malloc(sizeof(struct node)); 
            if(nextNODE==NULL){
                printf("Error, memory not allocated");
            } 
            else{
                printf("Data %d: ", i);
                scanf("%d", &nextNODE->data);

                nextNODE->next=NULL;
                ptr->next=nextNODE;
                ptr=ptr->next;
            }
        }

    }
}

//function to traverse and display the list
void dispLIST(struct node* headerNODE){
    struct node* ptr=headerNODE; 
    int count=1; 

    while(ptr!=NULL){
        printf("Data %d: %d\n", count, ptr->data);
        ptr=ptr->next;
        count++;
    }
}

//function to print reversed linked list 
void reverseLIST(struct node** headerNODE){
   struct node* currentNODE = *headerNODE; 
   struct node* nextNODE = NULL; 
   struct node* prevNODE=NULL; 

   while(currentNODE!=NULL){
    nextNODE = currentNODE->next;  //pointer to next node
    currentNODE->next=prevNODE;       //reversing link between current node and previous node
    prevNODE=currentNODE;          //moving forward pervious node
    currentNODE=nextNODE;    //moving current node 
    } 
    *headerNODE=prevNODE;
}

int main(){
    createLIST(5);
    printf("\n\nOG LIST: \n"); 
    dispLIST(headerNODE); 

    reverseLIST(&headerNODE);
    printf("\n\nNEW LIST: \n"); 
    dispLIST(headerNODE);

    return 0;
}