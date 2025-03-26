//inserting a node in the middle of a linked list with a key 
#include <stdio.h>
#include <stdlib.h>

//defining the structure 
struct node{
    int data;
    struct node* next;
}*headerNODE;

//function to create a linked list
void createLIST(int n){
    headerNODE=(struct node*)malloc(sizeof(struct node));
    if(headerNODE==NULL){
        printf("Error, memory not allocated");
    }

    else{
        struct node* ptr=headerNODE;
        
        //creating first node 
        printf("Data 1: ");
        scanf("%d", &headerNODE->data);
        headerNODE->next=NULL;

        for(int i=2; i<=n; i++){
            struct node* nextNODE=(struct node*)malloc(sizeof(struct node));
            if(nextNODE==NULL){
                printf("Error");
            }
            else{
                printf("Data %d: ", i);
                scanf("%d", &nextNODE->data);
            }

            nextNODE->next=NULL;
            ptr->next=nextNODE;
            ptr=ptr->next;
        }
        
    }

}

//function to traverse a linked list 
void dispLIST(struct node* header){
    struct node* ptr=header;
    int count=1; 
    while(ptr!=NULL){
        printf("Data %d: %d\n", count, ptr->data);
        count++; 
        ptr=ptr->next;
    }
}
//function to insert the node 
void insertMIDDLE(int key, struct node* header){
    struct node* ptrPREV=header;
    struct node* ptr=header->next;
    struct node* newNODE=(struct node*)malloc(sizeof(struct node));
    
    if(newNODE==NULL){
        printf("Error");
    }

    else{
        printf("New data: ");
        scanf("%d", &newNODE->data);

        while(ptrPREV->next!=NULL && ptrPREV->data!=key){
            ptrPREV=ptr;
            ptr=ptr->next;
        }

        ptrPREV->next=newNODE;
        newNODE->next=ptr;

    }


}
int main(){
    createLIST(5);
    printf("Og linked list: \n");
    dispLIST(headerNODE);
    insertMIDDLE(4, headerNODE);
    printf("Updated list: \n"); 
    dispLIST(headerNODE);
    return 0;
}