#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 0
#define ERROR 1

typedef int Data;
typedef int Status;
typedef struct {
    Data data[MAXSIZE];
    int length;
}List;

void createList(List *list); //创建新的线性表
void addNodeToList(List *list, int index, Data data); //增加节点到线性表
void printList(List list); //打印所有的列表节点
Status removeItem(List *list, int index); //删除一个元素
Status insertItem(List *list, int index, Data data); //插入一个元素
Data getItem(List *list, int index); //获取一个元素

int main(void) {
    printf("main function\n");
    List list;
    createList(&list);
    addNodeToList(&list, 0, 1);
    addNodeToList(&list, 1, 2);
    addNodeToList(&list, 2, 3);
    addNodeToList(&list, 3, 4);
    removeItem(&list, 1);
    insertItem(&list, 1, 10);
    insertItem(&list, 1, 11);
    printList(list);
    Data getData = getItem(&list, 2);
    printf("getItem: %d\n", getData);
    printf("main function end\n");
    return 0;
}

void createList(List *list) {
    for (int i=0; i<MAXSIZE; i++) {
        list->data[i] = -1;
    }
    list->length = 0;
}

void addNodeToList(List *list, int index, Data num) {
    printf("addNodeToList\n");
    list->data[index] = num;
    list->length++;
    printf("addNodeEdd\n");
}

Status removeItem(List *list, int index) {
    if (index+1 > list->length) return ERROR;
    for (int i=index; i<list->length; i++) {
        if (i+2<=list->length) {
            list->data[i] = list->data[i+1];
        } else {
            list->data[i] = 0;
        }
    }
    list->length--;
    return OK;
}

Status insertItem(List *list, int index, Data data) {
    if (list->length+1>MAXSIZE) return ERROR;
    if (index>list->length || index<0) return ERROR;
    for (int i=list->length-1; i>=index; i--) {
        if (i-1>=0) list->data[i] = list->data[i-1];
    }
    list->data[index] = data;
    list->length++;
    return OK;
}

Data getItem(List *list, int index) {
    if (index<0 || index>list->length-1) return ERROR;
    return list->data[index];
}

void printList(List list) {
    printf("start\n");
    for (int i = 0; i<MAXSIZE; i++) {
        printf("index: %d, data: %d\n",i, list.data[i]);
    }
    printf("length is: %d\n", list.length);
    printf("end\n");
}