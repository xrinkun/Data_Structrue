#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef int Data;
typedef struct {
    Data data[MAXSIZE];
    int top;
    int length;
}Stack;

Stack* initStack(); //初始化栈
Status printStack(Stack *stack); //输出栈
Status push(Stack *stack, Data data); //栈尾Push
Data pop(Stack *stack); //弹出
Status clearStack(Stack *stack); //清空栈

int main() {
    Stack *stack = initStack();
    push(stack, 10);
    push(stack, 11);
    push(stack, 12);
    printStack(stack);
    return 0;
}

Stack* initStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->length = 0;
    return stack;
}

Status printStack(Stack *stack) {
    if (stack->top == -1) {
        printf("empty stack\n");
        return OK;
    }
    for (int i=0; i<=stack->top; i++) {
        printf("index:%d data:%d\n", i, stack->data[i]);
    }
    return OK;
}

Status push(Stack *stack, Data data) {
    if (stack->top+1 >= MAXSIZE) {
        printf("full stack\n");
        return ERROR;
    }
    stack->data[++stack->top] = data;
    return OK;
}

Data pop(Stack *stack) {
    if (stack->top == -1) {
        printf("empty stack\n");
        exit(-1);
    }
    Data data = stack->data[stack->top--];
    printf("pop: %d\n", data);
    return data;
}

Status clearStack(Stack *stack) {
    for (int i=stack->top; i>-1; i--) {
        stack->data[i] = 0;
        stack->top--;
    }
    return OK;
}