//implementing queue using linked lists 
#include <stdio.h> 
#include <stdlib.h> 

//defining struct 
struct node{
    int data; 
    struct node* link;
}*queueFRONT; 

//function to enqueue elements 
void ENqueue(struct node** queueFRONT, int value){
    //checking if queue is empty 
    if(*queueFRONT==NULL){
        *queueFRONT=(struct node*)malloc(sizeof(struct node));
        if(queueFRONT==NULL){
            printf("Error");
        }
        else{
            (*queueFRONT)->data=value;
            (*queueFRONT)->link=NULL;
            printf("First element successfully queued.\n");
        }
    }

    else{
        struct node* ptr=*queueFRONT;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        //on the last element, where we want to enqueue
        struct node* queueREAR=(struct node*)malloc(sizeof(struct node));
        if(queueREAR==NULL){
            printf("Error");
        }
        else{
            queueREAR->data=value;
            ptr->link=queueREAR;
            queueREAR->link=NULL;
            printf("Element successfully enqueued.\n");
        }
        
    }
}

//function to dequeue 
void DEqueue(struct node** queueFRONT){
    struct node* ptr=(*queueFRONT)->link;
    printf("%d\t", (*queueFRONT)->data);
    //(*queueFRONT)->link=NULL;
    free(*queueFRONT);
    *queueFRONT=ptr;
}

int main(){
    ENqueue(&queueFRONT, 1);
    ENqueue(&queueFRONT, 2);
    ENqueue(&queueFRONT, 3);

    DEqueue(&queueFRONT);
    DEqueue(&queueFRONT);
    DEqueue(&queueFRONT);

    return 0;
}