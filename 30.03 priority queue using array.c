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
   struct QUEUE* queue=(struct QUEUE*)malloc(sizeof(struct QUEUE* ));

   if(queue==NULL){
    printf("Error");
   }
   else{
    printf("Memory for queue successfully allocated.\n");
    queue->size=size;

    //assign memory of a certain size for the array
    queue->queueARRAY=(int* )malloc(sizeof(int)*size);

    queue->queueFRONT=0; 
    queue->queueREAR=0;
   }//end if

   return queue;

}//end function

//function to check if queue is empty 
int queueEMPTY(struct QUEUE* queue){
    if(queue->queueFRONT==queue->queueREAR){
        //printf("Queue is empty");
        return 0;
    }
    else if(queue->queueREAR==(queue->size-1) && queue->queueARRAY[queue->queueREAR]==NULL){
        //printf("Queue is full");
        return 1;
    }

    else{
        return 2;
    }
}

//function to enqueue elements 
void ENqueue(struct QUEUE* queue, int value){
    //check if queue is empty 
    int full = queueEMPTY(queue);
    if(full==1){
        printf("Queue is full.\n");
    }

    else if(full==0){
        queue->queueARRAY[queue->queueREAR]=value;
        printf("First element has been enqueued. Front pointer: %d, rear pointer: %d.\n", queue->queueFRONT, queue->queueREAR);
        queue->queueREAR++;
    }

    else{
        queue->queueARRAY[queue->queueREAR]=value;
        printf("Element has been enqueued. Front pointer: %d, rear pointer: %d.\n", queue->queueFRONT, queue->queueREAR); 
        queue->queueREAR++; 
    }
}//end function 

//function to dequeue elements according to priority 
void DEqueue(struct QUEUE* queue){
    //dequeue largest element first, arrange the queue is descending order using selection sort. 
    for(int i=queue->queueFRONT; i<=queue->queueREAR; i++){
        int indexMAX=i; 
        for(int j=i+1; j<=queue->queueREAR; j++){
            if(queue->queueARRAY[indexMAX]<=queue->queueARRAY[j]){
                indexMAX=j;
            }

            else{
                continue;
            }//end if
        }//end for
        int temp=queue->queueARRAY[i];
        queue->queueARRAY[i]=queue->queueARRAY[indexMAX];
        queue->queueARRAY[indexMAX]=temp;
    }//end for

    //now dequeue the entire queue
    while(queue->queueFRONT!=queue->queueREAR){
        printf("%d\n", queue->queueARRAY[queue->queueFRONT]); 
        queue->queueFRONT+=1; 
    }
}//end function 

//main function to implement functions 
int main(){
    struct QUEUE* queue=CREATEqueue(5);
    ENqueue(queue, 17);
    ENqueue(queue, 22);
    ENqueue(queue, 10);
    ENqueue(queue, 34); 
    ENqueue(queue, 41); 

    DEqueue(queue);
    return 0;
}