#include <stdio.h>
#define OK 0
#define ERROR 1

typedef int Data;
typedef int Status;
typedef struct Node {
    Data data;
    struct Node *next;
}Node;
typedef struct {
    int length;
    Node *node;
}SingleLinkedList;

Status initLinkedList(SingleLinkedList *list); //初始化单链表
Status insertNode(SingleLinkedList *list, int index, Data data); //插入数据到单链表中
void printList(SingleLinkedList list); //输出单链表

int main() {
    SingleLinkedList list;
    initLinkedList(&list);
    insertNode(&list, 0, 5);
    insertNode(&list, 1, 4);
    printList(list);
    return 0;
}

Status initLinkedList(SingleLinkedList *list) {
    list->length = 0;
    Node node = {
        0,
        NULL
    };
    list->node = &node;
    return OK;
}

Status insertNode(SingleLinkedList *list, int index, Data data) {
    if (index>list->length) {
        return ERROR;
    }
    Node node = {
        data,
        NULL
    };
    if (index == 0) {
        list->node = &node;
        list->length++;
        return OK;
    }
    Node *curNode = list->node;
    Node *pNode = curNode;
    for (int i=1; i<index; i++) {
        pNode = curNode->next;
    }
    if (pNode) pNode->next = &node;
    Node *nextNode = index > list->length-1 ? NULL : curNode;
    node.next = nextNode;
    curNode->next = &node;
    list->length++;
    return OK;
}

void printList(SingleLinkedList list) {
    printf("length: %d\n", list.length);
    if (list.length == 0) {
        printf("None");
        return;
    }
    Node *curNode = list.node;
    for (int i=0; i<list.length; i++) {
        printf("index: %d, data: %d\n",i, curNode->data);
        curNode = curNode->next;
    }
}