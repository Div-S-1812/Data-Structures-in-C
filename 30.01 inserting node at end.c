//inserting new node at the end 
#include <stdio.h>
#include <stdlib.h>

//defining the structure
struct node{
    int data;
    struct node* next;
}*header;

//function to create the linked list 
void createLIST(int n){
    header=(struct node*)malloc(sizeof(struct node));
    header->next=NULL;

    struct node* ptr;
    
    if(header==NULL){
        printf("Error, memory not allocated");
    }

    else{
        //creating first node 
        printf("Data 1: ");
        scanf("%d", &header->data);
        
        ptr=header;
        
        //creating next nodes
        for(int i=2; i<=n; i++){
            struct node* nextNODE=(struct node*)malloc(sizeof(struct node));
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

//traversing the list 
void dispLIST(struct node* header){
    struct node* ptr=header;

    int count=1;
    printf("\n Linked list: \n");
    while(ptr!=NULL){
        printf("Data %d: %d\n", count, ptr->data);
        count++;
        ptr=ptr->next;
    }
}

//inserting new node at end 
void insertEND(struct node* header){
    struct node* ptr=header; 
    struct node* newNODE=(struct node*)malloc(sizeof(struct node));

    if(newNODE==NULL){
        printf("Error, memory not allocated");
    }

    else{
        printf("New data: ");
        scanf("%d", &newNODE->data);

        newNODE->next=NULL;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        
        ptr->next=newNODE;
    }
}
int main(){
    createLIST(5);

    insertEND(header);
    dispLIST(header);

    return 0;
}