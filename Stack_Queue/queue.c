#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef struct {
    int data[MAXSIZE];
    int length;
}Queue;

Queue* initQueue(); //初始化队列
void addData(Queue *q, int data); //添加数据
int popData(Queue *q); //弹出数据
void printQueue(Queue q); //打印数据

int main() {
    Queue *q = initQueue();
    addData(q, 1);
    addData(q, 2);
    addData(q, 3);
    popData(q);
    popData(q);
    printQueue(*q);
    return 0;
}

Queue* initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = 0;
    return q;
}

void addData(Queue *q, int data) {
    if (q->length >= MAXSIZE) {
        printf("full Queue\n");
        exit(-1);
    }
    q->data[q->length++] = data;
}

int popData(Queue *q) {
    if (q->length == 0) {
        printf("empty queue\n");
        exit(-1);
    }
    int temp = q->data[0];
    for (int i=0; i<q->length-1; i++) {
        q->data[i] = q->data[i+1];
    }
    q->length--;
    printf("pop data: %d\n",temp);
    return temp;
}

void printQueue(Queue q) {
    if (q.length==0) {
        printf("empty Queue\n");
        exit(-1);
    }
    for (int i=0;i<q.length;i++) {
        printf("index: %d, data: %d\n", i, q.data[i]);
    }
}

