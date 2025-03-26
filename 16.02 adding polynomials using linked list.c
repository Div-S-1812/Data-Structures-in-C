//program to create 2 linked lists and add 2 polynomials
#include <stdio.h> 
#include <stdlib.h> 

//defining struct
struct node{
    int coeff; 
    int exp; 
    struct node* link;
};

//function to create linked list, returning pointer to headernode
struct node* createLIST(int n){
    //creating headernode
    struct node* headerNODE=(struct node* )malloc(sizeof(struct node));
    if(headerNODE==NULL){
        printf("Error"); 
        //return 1; 
    }

    else{
        printf("Enter desired coeff: ");
            scanf("%d", &headerNODE->coeff);
            printf("Enter desired exponent: ");
            scanf("%d", &headerNODE->exp);
            headerNODE->link=NULL;

        struct node* ptr=headerNODE; 
        for(int i=2; i<=n; i++){
            struct node* nextNODE=(struct node* )malloc(sizeof(struct node)); 

            if(nextNODE==NULL){
                printf("Error");
                //return 1;
            }

            else{
                printf("Enter desired coeff: ");
                scanf("%d", &nextNODE->coeff);
                printf("Enter desired exponent: ");
                scanf("%d", &nextNODE->exp);
                ptr->link=nextNODE; 
                ptr=ptr->link;
                nextNODE->link=NULL;
            }//end else
        }//end for
    }//end else
    return headerNODE;
}

//displaying the list 
void dispLIST(struct node* headerNODE){
    struct node* ptr=headerNODE;

    //int count=1;
    printf("\n Polynomial: \n");
    while(ptr!=NULL){
        printf("%dx^%d+", ptr->coeff, ptr->exp);
        //count++;
        ptr=ptr->link;
    }
    printf("0");
}

//function to add the polynomials 
void addPOLY(struct node* headerNODE1, struct node* headerNODE2){
    struct node* ptr1=headerNODE1;
    struct node* ptr2=headerNODE2;
    printf("\nSum of 2 polynomials: ");

    while(ptr1!=NULL || ptr2!=NULL){
        if(ptr1->exp==ptr2->exp){
            printf("%dx^%d+", (ptr1->coeff+ptr2->coeff), ptr1->exp);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }

        else if(ptr1->exp>ptr2->exp){
            printf("%dx^%d+", ptr1->coeff, ptr1->exp); 
            ptr1=ptr1->link;
        }

        else if(ptr1->exp<ptr2->exp){
            printf("%dx^%d+", ptr2->coeff, ptr2->exp); 
            ptr2=ptr2->link;
        }

    }//end while
    printf("0");
}

int main(){
    struct node* headerNODE1=createLIST(3);
    struct node* headerNODE2=createLIST(3);

    dispLIST(headerNODE1);
    dispLIST(headerNODE2);

    addPOLY(headerNODE1, headerNODE2);

    return 0;
}