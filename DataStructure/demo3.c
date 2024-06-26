/**
* 类名:demo4
* 描述: 栈实现增删改
* 当前用户:21204
* 当前时间:2024/6/26:16:59
*/
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// 初始化栈
void initStack(Stack *stack) {
    stack->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
}

// 检查栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 入栈操作
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        // 栈满时扩容
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (stack->data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    stack->data[++stack->top] = value;
}

// 出栈操作
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// 获取栈顶元素
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// 打印栈内元素
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// 释放栈内存
void freeStack(Stack *stack) {
    free(stack->data);
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack elements: ");
    printStack(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Stack elements after pop: ");
    printStack(&stack);

    freeStack(&stack);

    return 0;
}
