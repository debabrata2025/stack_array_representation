#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

//isempty
int isEmpty(struct stack *sp){
    if (sp->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
//isfull
int isFull(struct stack *sp){
    if (sp->top == sp->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}
//stack element traversasl
void stackTraversal(struct stack *sp){
    printf("element of the stack from top to bottom are: **(where ) reperesents no item present in the stack)\n");
    for (int i = sp->size-1; i >= 0  ; i--)
    {
        printf("%d\n", sp->arr[i]);
    }
   printf("\n"); 
}
//push recursivly
void push_recursive(struct stack *sp){
    //base case
    if (isFull(sp))
    {
        return;
    }
    int data;
    printf("enter data: \n");
    scanf("%d", &data);
    if (data != -1)
    {
      sp->top++;
      sp->arr[sp->top] = data;
      push_recursive(sp);
    }  
}
//pop  recursively
void pop(struct stack *sp){
    //base case
    if (isEmpty(sp))
    {
        printf("no element to pop\n");
        return;
    }
    int val = sp->arr[sp->top];
    sp->top--;
    printf("%d is popped from the stack\n", val);
    pop(sp);   
}

//stack top
int stackTop(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("stack is underflowing, no item present in the stack\n");
    }else{
        return sp->arr[sp->top];
    }
}

//stack bottom
int stackBottom(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("stack is underflowing, bo item present in the stack\n ");
    }else{
        return sp->arr[0];
    }
}

//peek operation
int peek(struct stack *sp, int position){
    int spIndex = sp->top-position+1;
    if (spIndex < 0)
    {
        printf("not a valid index\n");
    }else{
        return sp->arr[spIndex];
    }
    
}

int main()
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 10;
    sp->arr = (int *) calloc(sp->size, sizeof(int));
    
    if (isEmpty(sp) == 1)
    {
        printf("stack is underflowing || no element to be deleted\n");
    }else{
        printf("stack is not empty");
    }
    if (isFull(sp) == 1)
    {
        printf("stack is overflowing || no element can not be inserted\n");
    }else{
        printf("stack is not full\n");
    }
    //push recursivly
    push_recursive(sp);
    
    //stack element traversal
    stackTraversal(sp);

    //stack top
    printf("%d is present to the top of the stack \n", stackTop(sp));

    //stack bottom
    printf("%d is present to the bottom of the stack \n", stackBottom(sp));

    //peek operation
    int position;
    printf("enter the position that you want to peek\n");
    scanf("%d", &position);
    printf("%d is found at %d position\n", peek(sp, position), position);

    //pop recursivly
    pop(sp);

    return 0;
}
