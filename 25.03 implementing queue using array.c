//program to implement queue using an array 
//creating queue, enqueue and dequeue functions 
#include <stdio.h>
#include <stdlib.h>

struct QUEUE{
    int size; 
    int front; 
    int rear;
    int* queueARRAY;
}*queue1;

struct QUEUE* CREATEqueue(int size){
    queue1=(struct QUEUE*)malloc(sizeof(struct QUEUE*));

    if(queue1==NULL){
        printf("ERROR");
    }

    else{
        queue1->size=size;
        queue1->front=-1;
        queue1->rear=-1;
        queue1->queueARRAY=(int* )malloc(sizeof(int)*size);
    }//end if

    return queue1; 
}//end function

//checking if queue is full 
int queueFULL(struct QUEUE* queue1){
    if(queue1->rear==(queue1->size-1)){
        //printf("Queue is FULL");
        return 1;
    }

    else{
        //printf("Queue isn't full");
        return 0;
    }//end if
}

//enqueue function 

void ENqueue(struct QUEUE* queue1, int value){
    //checking if queue is empty 
    int full=queueFULL(queue1);
    if(full==1){
        printf("Queue is full");
    }

    else{
        queue1->queueARRAY[queue1->rear]=value; 
        queue1->rear+=1;
    }
}

//dequeue function

void DEqueue(struct QUEUE* queue1){
    while(queue1->front!=queue1->rear){
    printf("%d\n", queue1->queueARRAY[queue1->front]); 
    queue1->front+=1; 
    }
    free(queue1->queueARRAY);
}

int main(){
    queue1=CREATEqueue(3);
    ENqueue(queue1, 1);
    ENqueue(queue1, 2);
    ENqueue(queue1, 3);

    DEqueue(queue1);
    return 0;
}