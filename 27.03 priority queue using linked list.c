//implementing priority queue using linked list 
#include <stdio.h> 
#include <stdlib.h> 

//defining struct to hold nodes 
struct node{ 
    int data; 
    struct node* link;
}queueFRONT;

//enqueuing data in queue 
void ENqueue(struct node** queueFRONT, int value){
    //checking if queue is empty 
    if((*queueFRONT)==NULL){
        printf("Queue is empty");
        (*queueFRONT)=(struct node*)malloc(sizeof(struct node));
        if((*queueFRONT)==NULL){
            printf("Error: mem not assigned");
        }

        else{
            (*queueFRONT)->data=value; 
            (*queueFRONT)->link=NULL;
            printf("First element successfuly enqueued");
        }//end if
    }

    else{
        struct node* ptr=(*queueFRONT);
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        //now at last node, where we want to enqueue 
        struct node* queueREAR=(struct node*)malloc(sizeof(struct node));
        if(queueREAR==NULL){
            printf("Error");
        }
        else{
            queueREAR->data=value;
            ptr->link=queueREAR;
            queueREAR->link=NULL;
        }//end if
    }//end if 
}//end function 

//dequeuing according to priority 
void DEqueue(struct node** queueFRONT){
    //find if queue is empty 
    if((*queueFRONT)==NULL){
        printf("Error");
    }
    else{
        //find maximum element 
        struct node* ptr1=(*queueFRONT);
        struct node* ptr2=(*queueFRONT)->link; 
        while(ptr1->link==NULL || ptr2->link==NULL){
            if(ptr1->data>=ptr2->data){
                ptr2=ptr2->link;
            }
        }//end while
    }//end if
}//end function

//implementing in int main 
int main(){

    return 0;
}