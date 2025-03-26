//implementing stack using array
#include <stdio.h> 
#include <stdlib.h> 

//defining structure to hold nodes 
struct STACK{
    int size; 
    int top; 
    int* arraySTACK;
}*stack1;

//function to create a stack 
struct STACK* createSTACK(int size){
    stack1 = (struct STACK* )malloc(sizeof(struct STACK)); //assigning memory for stack1
    stack1->size=size;  //assigning size of the stack 
    stack1->top=-1;  //starting index value is -1 
    stack1->arraySTACK=(int* )malloc(size*sizeof(int)); 
    return stack1;
}

//checking is stack is full by checking value of top and last index value 
int stackFULL(struct STACK* stack1){
    int freeELEMENTS=(stack1->size-1)-stack1->top;
    if(freeELEMENTS==0){
        printf("Stack is full\n"); 
        return 1;
    }

    else{
        printf("Stack has %d free elements\n", freeELEMENTS);
        return 0;
    }
}

//pushing an element on stack 
void stackPUSH(struct STACK* stack1, int element){
    stack1->top++; 
    stack1->arraySTACK[stack1->top]=element;
    printf("%d pushed to top of the stack\n", element);
}

//popping an element 
void stackPOP(struct STACK* stack1){
    for(stack1->top; stack1->top!=-1; stack1->top--){
        printf("%d\t\t", stack1->arraySTACK[stack1->top]);
    }
}

//implementing in main function 
int main(){
    createSTACK(3);
    stackPUSH(stack1, 1);
    stackPUSH(stack1, 2);
    stackPUSH(stack1, 3);
    stackFULL(stack1);
    stackPOP(stack1);
    return 0;
}