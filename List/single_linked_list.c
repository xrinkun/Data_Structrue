#include <stdio.h>
#define OK 0
#define ERROR 1

typedef int Data;
typedef int Status;
typedef struct Node {
    Data data;
    Node *next;
};
typedef struct {
    int length;
    Node *node;
}SingleLinkedList;

Status initLinkedList(SingleLinkedList *list);
Status insertNode(SingleLinkedList *list, Data data);

int main() {
    SingleLinkedList list;
    initLinkedList(&list);
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

Status insertNode(SingleLinkedList *list, Data data) {
    Node node = {
        data,
        NULL
    };
    Node *pNode = list->node;
    pNode->next = &node;
    list->node->next = pNode;
    list->length++;
    return OK;
}