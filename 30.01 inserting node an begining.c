//creating a linked list 
#include <stdio.h>
#include <stdlib.h>

//defining the structure 
    struct node{
        int data;
        struct node* next;
    }*stnode; 

void insertBEGIN(struct node** stnode){
    //struct node* ptr=stnode;
    struct node* newNODE; 
    newNODE=(struct node* )malloc(sizeof(struct node));
    if(newNODE==NULL){
        printf("Mem not allocated");
    }
    else{
        newNODE->next=NULL;
        printf("Enter desired data for new node: "); 
        scanf("%d", &newNODE->data);

        newNODE->next = *stnode;
        *stnode = newNODE;
    }
}

int main(){

    stnode=(struct node*)malloc(sizeof(struct node));  //created a pointer variable 

    //checking id memory is allocated 
    if(stnode == NULL){
        printf("Memory not allocated"); 
    }

    else{
        int n; //number of nodes 
        printf("Enter desired number of nodes: "); 
        scanf("%d", &n);

        //create start of linked list 
        printf("Input data for item 1: "); 
        scanf("%d", &stnode->data); 
        stnode->next=NULL;  //null pointer for link to next node 
        
        struct node* ptr= stnode; 
        struct node* fnnode; 

        //next n nodes 
                
        //for loop to keep adding n nodes 
        for(int i=2; i<=n; i++){
            //allocating space for fnnode
            fnnode=(struct node*)malloc(sizeof(struct node)); 

            //checking if memory is allocated
            if(fnnode == NULL){
                printf("Memory isn't allocated"); 
            }

            else{
                printf("Input data for item %d: ", i); 
                scanf("%d", &fnnode->data); 

                fnnode->next=NULL;
                 
                ptr->next=fnnode;
                ptr=ptr->next;

            }

        }
    }

    //calling insert begin function
    insertBEGIN(&stnode);

    // Displaying the linked list
    struct node* ptr = stnode; // Start from the first node

    while (ptr != NULL) {
        printf("Data: %d\n", ptr->data); // Print current node's data
        ptr = ptr->next; // Move to the next node
    }

    return 0;
}