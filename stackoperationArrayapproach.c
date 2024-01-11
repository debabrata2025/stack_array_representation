// array repreaentation of stack
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
//stack is empty or not
int isEmpty(struct stack *sp){
    if (sp->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
//stack is full or not
int isFull(struct stack *sp){
    if (sp->top == sp->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}
//push operation
void push(struct stack *sp, int elem){
    if (isFull(sp))
    {
        printf("stack is overflowing %d can not be pushed\n", elem);
    }else{
        sp->top++;
        sp->arr[sp->top] = elem;
        printf("%d is pushed to the stack\n", elem);
    }  
}
//pop operation
int pop(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("stack is underflowing || no element to be deleted \n");
    }else{
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

//stacktop
int stackTop(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("there is no element in the stack\n");
    }else{
        return sp->arr[sp->top];
    }
}
//stack bottom
int stackBottom(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("there is no element in the stack\n");
    }else{
        return sp->arr[0];
    }
}
//peek operation
int peekStack(struct stack *sp, int postition){
    int arrIndex = sp->top-postition+1;
    if (arrIndex < 0)
    {
        printf("not a valid position\n");
    }else{
        return sp->arr[arrIndex];
    }
    
}

int main()
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 5;
    sp->arr = (int *) malloc(sp->size*sizeof(int));

    if (isEmpty(sp) == 1)
    {
        printf("stack is underflowing\n");
    }else{
        printf("stack is not empty");
    }

    if (isFull(sp) == 1)
    {
        printf("stack is overflowing\n");
    }else{
        printf("stack is not full\n");
    }
    push(sp, 10);
    push(sp, 11);
    push(sp, 12);
    push(sp, 13);
    push(sp, 14);
    push(sp, 15);
    push(sp, 16);


    printf("%d element is present in the top of the stack\n", stackTop(sp));
    printf("%d element is present in the bottom of the stack\n", stackBottom(sp));

    printf("peek operation!!!\n");
    int pos;
    printf("enter the position from where you want to peek eleemnt\n");
    scanf("%d", &pos);
    printf("%d is found at %d position", peekStack(sp, pos), pos);

    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));
    printf("%d is popped from the stack \n", pop(sp));

    return 0;
}