//linear search for linked list 
#include <stdio.h> 
#include <stdlib.h> 

//defining the structure 
struct node{ 
    int data; 
    struct node* link;
}*headerNODE; 

//function to create linked list 
void createLIST(int n){
    //allocating memory for header node 
    headerNODE=(struct node* )malloc(sizeof(struct node));

    if(headerNODE==NULL){
        printf("Error, memory not allocated"); 
    }

    else
    printf("Enter data 1: ");
    scanf("%d", &headerNODE->data); 

    struct node* newNODE; 
    struct node* ptr=headerNODE; 

    for(int i=2; i<=n; i++){
        newNODE=(struct node* )malloc(sizeof(struct node));
        if(newNODE==NULL){
            printf("Memory not allocated");
        }

        else{
        printf("Enter data %d: ",i); 
        scanf("%d", &newNODE->data); 
        newNODE->link=NULL; 

        ptr->link=newNODE; 
        ptr=ptr->link;
        }
    }
}

//function to carry out linear search 
void linearSEARCH(int key, struct node* headerNODE){
    struct node* ptr=headerNODE; 
    int flag=0, counter=1; 

    while(ptr!=NULL & flag==0){
        if(ptr->data==key){
            printf("%d found at %d node: %d", key, counter, ptr); 
            flag++;
        }
        else{
        ptr=ptr->link;
        counter++;
        }
    }

    if(ptr==NULL){
        printf("%d not found.", key);
    }
}

int main(){
    createLIST(6); 
    linearSEARCH(10, headerNODE);
    return 0;
}