/**
* 类名:demo4
* 描述: 线性表实现增删改
* 当前用户:21204
* 当前时间:2024/6/26:16:59
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义线性表结构体
typedef struct {
    int *data;      // 动态数组，用于存储线性表元素
    int capacity;   // 线性表的容量
    int size;       // 线性表的当前元素数量
} LinearList;

// 初始化线性表
void initList(LinearList *list, int initialCapacity) {
    list->data = (int *)malloc(initialCapacity * sizeof(int));
    list->capacity = initialCapacity;
    list->size = 0;
}

// 释放线性表的内存
void freeList(LinearList *list) {
    free(list->data);
    list->data = NULL;
    list->capacity = 0;
    list->size = 0;
}

// 扩展线性表的容量
void expandCapacity(LinearList *list) {
    int newCapacity = list->capacity * 2;
    int *newData = (int *)realloc(list->data, newCapacity * sizeof(int));
    if (newData) {
        list->data = newData;
        list->capacity = newCapacity;
    } else {
        fprintf(stderr, "Failed to expand capacity\n");
        exit(EXIT_FAILURE);
    }
}

// 获取线性表中的元素数量
int getSize(LinearList *list) {
    return list->size;
}

// 判断线性表是否为空
bool isEmpty(LinearList *list) {
    return list->size == 0;
}

// 获取指定位置的元素
int get(LinearList *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of range\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

// 在指定位置插入元素
void insert(LinearList *list, int index, int element) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Index out of range\n");
        exit(EXIT_FAILURE);
    }

    if (list->size == list->capacity) {
        expandCapacity(list);
    }

    for (int i = list->size; i > index; --i) {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = element;
    list->size++;
}

// 在线性表末尾添加元素
void add(LinearList *list, int element) {
    insert(list, list->size, element);
}

// 删除指定位置的元素
void removeAt(LinearList *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of range\n");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < list->size - 1; ++i) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

// 打印线性表中的所有元素
void printList(LinearList *list) {
    for (int i = 0; i < list->size; ++i) {
        printf("Element at index %d: %d\n", i, list->data[i]);
    }
}

int main() {
    LinearList list;
    initList(&list, 10);

    add(&list, 1);
    add(&list, 2);
    add(&list, 3);

    printf("List size: %d\n", getSize(&list));
    printList(&list);

    insert(&list, 1, 10);
    printf("After inserting 10 at index 1:\n");
    printList(&list);

    removeAt(&list, 2);
    printf("After removing element at index 2:\n");
    printList(&list);

    freeList(&list);
    return 0;
}
//定义线性表结构体：LinearList 包含一个指向动态数组的指针 data、当前的容量 capacity 和当前元素数量 size。
//
//初始化和释放：
//
//initList：初始化线性表，分配初始容量的动态数组。
//freeList：释放动态数组的内存，重置线性表的属性。
//扩展容量：expandCapacity 用于在容量不足时扩展容量。
//
//基础操作：
//
//getSize 返回线性表中的元素数量。
//isEmpty 判断线性表是否为空。
//get 获取指定位置的元素，若位置越界则打印错误信息并退出程序。
//insert 在指定位置插入元素，必要时扩展容量。
//add 在末尾添加元素。
//removeAt 删除指定位置的元素。
//打印线性表：printList 打印线性表中的所有元素。
//
//示例用法：在 main 函数中展示了如何使用 LinearList 结构体，包括添加、插入和删除元素的操作。
//
//通过这个实现，您可以理解如何在 C 中管理动态内存并实现线性表的基本操作。