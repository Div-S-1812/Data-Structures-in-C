//priority queue using array 
#include <stdio.h> 
#include <stdlib.h> 

//creating stack that holds array 
struct QUEUE{
    int size; 
    int queueFRONT; 
    int queueREAR;
    int* queueARRAY; 
};

//function to create the queue 
struct QUEUE* CREATEqueue(int size){
   //creating pointer to struct and assigning memory
   struct QUEUE* queue=(struct QUEUE*)malloc(sizeof(struct QUEUE));

   //assign memory of a certain size for the array
   queue->queueARRAY=(int* )malloc(sizeof(int)*size);
   if(queue->queueARRAY==NULL){
    printf("Error");
   }
   else{
    printf("Memory for queue successfully allocated.\n");
    queue->queueFRONT=0; 
    queue->queueREAR=-1;
    return queue;
   }//end if
}//end function

//function to enqueue elements 
void ENqueue(struct QUEUE* queue, int value){
    //check if the queue is full 
    if(queue->queueREAR==(queue->size-1)){
        printf("Queue is full.\n");
    }
    
    else{
        queue->queueARRAY[queue->queueREAR]=value;
        queue->queueREAR+=1;
        if(queue->queueREAR==0){
            printf("First element successfully enqueued.\n");
        }
        else{
        printf("Value successfully enqueued.\n");
        }
    }
}
//function to dequeue elements according to priority 

//main function to implement functions 
int main(){
    struct QUEUE* queue=CREATEqueue(3);
    ENqueue(queue, 3);
    ENqueue(queue, 2);
    ENqueue(queue, 1);
    ENqueue(queue, 0);
    return 0;
}