/**
* 类名:demo4
* 描述:链表实现增删改
* 当前用户:21204
* 当前时间:2024/6/26:16:59
*/
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入新节点
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 在链表尾部插入新节点
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删除链表中第一个匹配的节点
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// 打印链表中的所有元素
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // 在链表头部插入元素
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    // 打印链表
    printf("List after inserting at head: ");
    printList(head);

    // 在链表尾部插入元素
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    // 打印链表
    printf("List after inserting at tail: ");
    printList(head);

    // 删除链表中的元素
    deleteNode(&head, 3);
    deleteNode(&head, 6);  // 尝试删除不存在的元素

    // 打印链表
    printf("List after deleting elements: ");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
