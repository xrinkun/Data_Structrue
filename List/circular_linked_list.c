#include <stdio.h>
#include <stdlib.h>
#define LENGTH 20
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
    insertDataByIndex(list, 2, 0);
    printList(list);
    return 0;
}

cList createList() {
    cList list = malloc(sizeof(Node)*LENGTH);
    list->data = -1;
    list->next = list;
    return list;
}

Status insertDataByIndex(cList list, Data data, int index) {
    if (index<0 && index>LENGTH-1) {
        printf("index out of range");
        return ERROR;
    }
    Node *curNode = list->next;
    Node *prevNode = list;
    Node *nextNode = NULL;
    for (int i=1;i<=index;i++) {
        prevNode = curNode;
        curNode = curNode->next;
        nextNode = curNode->next;
    }
    if (!nextNode) nextNode = list;
    Node *tempNode = (Node *)malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = nextNode;
    prevNode->next = tempNode;
    return OK;
}

Status printList(cList list) {
    Node *curNode = list->next;
    if (curNode == list->next) {
        printf("list is empty");
        return OK;
    }
    while (curNode) {
        printf("data: %d\n", curNode->data);
        curNode = list->next;
        if (curNode == list) break;
    }
    return OK;
}