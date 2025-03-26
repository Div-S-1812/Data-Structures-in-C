//implementing stack using linked list 
#include <stdio.h>
#include <stdlib.h> 

///defining structure for nodes of linked list 
struct STACK{
    int element; 
    struct STACK* link; 
}*stackHEADER;


//checking if stack is empty
int stackEMPTY(struct STACK* stackHEADER){
    if(stackHEADER==NULL){
        printf("The stack is empty.\n");
        return 1;
    }
    else{
        printf("Stack is not empty.\n");
        return 0;
    }
}

//function to push element onto stack
void stackPUSH(struct STACK** stackHEADER, int element){
        struct STACK* ptr=*stackHEADER;
        struct STACK* newNODE=(struct STACK* )malloc(sizeof(struct STACK));
        
        if(newNODE==NULL){
            printf("WOMP WOMP");
        }
        else{
            newNODE->element=element; 
            newNODE->link=*stackHEADER;
            *stackHEADER=newNODE; 
            printf("Element %d pushed to top of stack.\n", element);           
        }
}

void stackPOP(struct STACK** stackHEADER){
    printf("Element: %d\n", (*stackHEADER)->element);
    struct STACK* ptr=*stackHEADER; 
    *stackHEADER=(*stackHEADER)->link;
    free(ptr);
}

//implementing in main function
int main(){
    stackEMPTY(stackHEADER);

    stackPUSH(&stackHEADER, 3);
    stackPUSH(&stackHEADER, 2);
    stackPUSH(&stackHEADER, 1);

    stackEMPTY(stackHEADER);

    stackPOP(&stackHEADER);
    stackPOP(&stackHEADER);
    stackPOP(&stackHEADER);

    stackEMPTY(stackHEADER);
    return 0;
}