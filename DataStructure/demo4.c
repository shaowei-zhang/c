/**
* 类名:demo4
* 描述: 队列实现增删改
* 当前用户:21204
* 当前时间:2024/6/26:16:59
*/
#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义队列结构
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 初始化队列
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// 检查队列是否为空
int isEmpty(Queue* q) {
    return q->size == 0;
}

// 入队操作
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// 出队操作
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "队列为空，无法出队\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

// 显示队列中的所有元素
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("队列为空\n");
        return;
    }
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("队列中的元素: ");
    displayQueue(&q);

    printf("出队元素: %d\n", dequeue(&q));

    printf("队列中的元素: ");
    displayQueue(&q);

    return 0;
}
