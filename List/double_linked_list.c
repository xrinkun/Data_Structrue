#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1

typedef int Data;
typedef int Status;
typedef struct Node{
    struct Node *prevNode;
    Data data;
    struct Node *nextNode;
}Node;
typedef struct {
    int length;
    Node *head;
}List;

List* createList(); //创建一个双链表
Status printList(List list); //输出列表
Status insertIntoList(List *list, Data data, int index); //插入数据
Status deleteItemFromList(List *list, int index); //删除数据
Data getDataByIndex(List *list, int index); //根据索引获取数据

int main() {
    List *list = createList();
    insertIntoList(list, 10, 0);
    insertIntoList(list, 20, 1);
    insertIntoList(list, 30, 2);
    deleteItemFromList(list, 0);
    deleteItemFromList(list, 1);
    Data data = getDataByIndex(list, 0);
    printf("Data is: %d\n", data);
    printf("====================\n");
    printList(*list);
    return 0;
}

List* createList() {
    List *list = (List *)malloc(sizeof(List));
    list->length = 0;
    list->head = NULL;
    return list;
}

Status printList(List list) {
    printf("length: %d\n", list.length);
    Node *node = list.head;
    for (int i=0; i<list.length; i++) {
        printf("index:%d data: %d addr: %p\n", i, node->data, node);
        if (node->nextNode) node = node->nextNode;
    }
}

Status insertIntoList(List *list, Data data, int index) {
    if (index > list->length || index < 0) return ERROR;
    Node *pNode = NULL;
    Node *curNode = NULL;
    Node *nNode = NULL;
    for (int i=0; i<=index; i++) {
        if (i == 0) {
            curNode = list->head;
            nNode = curNode?curNode:NULL;
        } else {
            pNode = curNode;
            curNode = curNode->nextNode;
            nNode = curNode?curNode->nextNode:NULL;
        }
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->prevNode = pNode;
    newNode->data = data;
    newNode->nextNode = curNode;
    if (pNode) {
        pNode->nextNode = newNode;
    }
    if (nNode) {
        nNode->prevNode = newNode;
    }
    if (index == 0) {
        list->head = newNode;
    }
    list->length++;
    return OK;
}

Status deleteItemFromList(List *list, int index) {
    if (index >= list->length || index < 0) return ERROR;
    Node *node = NULL;
    for (int i=0; i<=index; i++) {
       if (i == 0) {
           node = list->head;
       } else {
           node = node->nextNode;
       }
    }
    Node *pNode = node->prevNode;
    Node *nNode = node->nextNode;
    if (pNode) {
        pNode->nextNode = nNode;
    }
    if (nNode) {
        nNode->prevNode = pNode;
    }
    if (index == 0) {
        list->head = nNode;
    }
    free(node);
    list->length--;
    return OK;
}

Data getDataByIndex(List *list, int index) {
    if (index >= list->length || index < 0) {
        printf("index Error!");
        exit(-1);
    }
    Node *node = NULL;
    for (int i=0; i<=index; i++) {
        if (i == 0) node = list->head;
        else {
            if (!node->nextNode) {
                printf("prev: %p cur: %p next: %p\n", node->prevNode, node, node->nextNode);
                printf("function getData unknow error");
                exit(-1);
            }
            node = node->nextNode;
        }
    }
    return node->data;
}