#include <stdio.h>
#include <stdlib.h>
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
Status deleteElementByIndex(SingleLinkedList *list, int index); //删除元素
Data getElementByIndex(SingleLinkedList list, int index); //获取元素

int main() {
    SingleLinkedList list;
    initLinkedList(&list);
    insertNode(&list, 0, 5);
    insertNode(&list, 1, 4);
    insertNode(&list, 2, 3);
    deleteElementByIndex(&list, 0);
    Data data = getElementByIndex(list, 0);
    printf("getData: %d\n", data);
    printList(list);
    return 0;
}

Status initLinkedList(SingleLinkedList *list) {
    list->length = 0;
    list->node = NULL;
    return OK;
}

Status insertNode(SingleLinkedList *list, int index, Data data) {
    if (index>list->length) {
        return ERROR;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (index == 0) {
        node->next = list->node ? list->node : NULL;
        list->node = node;
        if (list->node) 
        list->length++;
        return OK;
    }

    Node *curNode = list->node;
    Node *pNode = NULL;

    for (int i=1; i<=index; i++) {
        pNode = curNode;
        curNode = curNode->next;
    }
    if (pNode) pNode->next = node;
    Node *nextNode = index > list->length-1 ? NULL : curNode;
    node->next = nextNode;
    list->length++;
    return OK;
}

Status deleteElementByIndex(SingleLinkedList *list, int index) {
    if (index < 0) return ERROR;
    if (index >= list->length) return ERROR;

    Node *pNode = NULL;
    Node *curNode = list->node;
    Node *nextNode = NULL;

    for (int i=0; i<index; i++) {
        pNode = curNode;
        curNode = curNode->next;
        nextNode = curNode->next;
    }
    if (index==0) {
        nextNode = curNode ? curNode->next : NULL;
        list->node = nextNode;
        free(curNode);
        list->length--;
        return OK;
    }
    pNode->next = nextNode;
    list->length--;
    return OK;
}

Data getElementByIndex(SingleLinkedList list, int index) {
    if (index < 0) {
        printf("index Error!");
        return -1;
    }
    if (index >= list.length) {
        printf("index Error!");
        return -1;
    }

    Node *curNode = NULL;
    
    for (int i=0; i<=index; i++) {
        if (i==0) {
            curNode = list.node;
            continue;
        }
        curNode = curNode->next;
    }
    return curNode->data;
}

void printList(SingleLinkedList list) {
    printf("length: %d\n", list.length);
    if (list.length == 0) {
        printf("None");
        return;
    }
    Node *curNode = NULL;
    for (int i=0; i<list.length; i++) {
        if (i==0) {
            curNode = list.node;
        } else {
            curNode = curNode->next;
        }
        printf("index: %d, data: %d\n",i, curNode->data);
    }
}