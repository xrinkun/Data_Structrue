#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
}Node, *cList;

cList createList(); //创建链表
Status printList(cList list); //输出链表
Status insertDataByIndex(cList list, Data data, int index); //插入数据到链表

int main() {
    cList list = createList();
    insertDataByIndex(list, 1, 0);
    insertDataByIndex(list, 2, 1);
    insertDataByIndex(list, 3, 2);
    printList(list);
    return 0;
}

cList createList() {
    cList list = (Node *)malloc(sizeof(Node));
    list->data = -1;
    list->next = list;
    return list;
}

Status insertDataByIndex(cList list, Data data, int index) {
    if (index<0) {
        printf("index out of range");
        return ERROR;
    }
    Node *curNode = list;
    Node *prevNode = NULL;
    Node *nextNode = list->next;
    for (int i=1;i<=index;i++) {
        prevNode = curNode;
        curNode = curNode->next;
        nextNode = curNode->next;
    }
    Node *tempNode = (Node *)malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = curNode;
    Node *tailNode = curNode;
    while (1) {
        if (tailNode->next == list) {
            break;
        } else {
            tailNode = tailNode->next;
        }
    }
    tailNode->next = tempNode;
    return OK;
}

Status printList(cList list) {
    Node *curNode = list->next;
    if (list == list->next) {
        printf("list is empty");
        return OK;
    }
    while (curNode != list) {
        printf("data: %d\n", curNode->data);
        curNode = curNode->next;
    }
    return OK;
}