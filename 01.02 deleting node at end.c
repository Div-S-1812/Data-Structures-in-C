//deleting a node from begining of linked list 
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
    printf("Enter data 1: ");
    scanf("%d", &headerNODE->data);
    headerNODE->next=NULL;

    //creating nodes 2 to n
    for(int i=2; i<=n; i++){
        nextNODE=(struct node* )malloc(sizeof(struct node));
        if(nextNODE==NULL){
            printf("Error");
        }

        else{
            printf("Enter data %d: ", i);
            scanf("%d", &nextNODE->data);
            nextNODE->next=NULL;

            ptr->next=nextNODE;
            ptr=ptr->next;
        }
    }
   }
}

//function to display list 
void dispLIST(struct node* headerNODE){
    struct node* ptr= headerNODE;
    int count=1; 
    while(ptr!=NULL){
        printf("Data %d: %d\n", count, ptr->data);
        count++;
        ptr=ptr->next;
    }
}

//function to delete node at the end
void deleteEND(struct node* headerNODE){
    struct node* ptr=headerNODE;
    struct node* ptrPREV=NULL;

    while(ptr->next!=NULL){
        ptrPREV=ptr;
        ptr=ptr->next;
    } 
    ptrPREV->next=NULL;
    free(ptr);

}

int main(){
    createLIST(5);
    printf("OG List: \n");
    dispLIST(headerNODE);

    deleteEND(headerNODE);

    printf("New List: \n");
    dispLIST(headerNODE);

}