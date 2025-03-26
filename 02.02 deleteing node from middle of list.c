//deleting a node at the middle of a linked list 
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

//function to delte node from middle of the list 
void deleteMIDDLE(int key, struct node* header){
    struct node* ptrPREV=NULL; 
    struct node* ptr=headerNODE;

    while(ptr!=NULL && ptr->data!=key){
        ptrPREV=ptr; 
        ptr=ptr->next;
    }

    ptrPREV->next=ptr->next; 
    free(ptr);

}

int main(){
    createLIST(5);
    printf("OF LIST: \n"); 
    dispLIST(headerNODE); 
    deleteMIDDLE(6, headerNODE);
    printf("NEW LIST: \n"); 
    dispLIST(headerNODE);

    return 0;
}