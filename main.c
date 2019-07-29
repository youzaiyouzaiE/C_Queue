#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

///静态循环队列

typedef struct Queue
{
    int *pBase;
    int front;////头下标
    int rear; //位下标
    int leng;
}QUEUE, *pQueue;

int queueLength;
void init(pQueue pQ , int length);
bool fulled(pQueue pQ );
bool empty(pQueue pQ );
bool enterQueue(pQueue pQ, int value); //入队
bool outQueue(pQueue pQ, int *pOutElementValue); //出队
void showQueue(pQueue pQ);

int main(int argc, char const *argv[])
{
    printf("Hello Queue ! \n");
    QUEUE queue;
    init(&queue, 6);
    enterQueue(&queue, 11);
    enterQueue(&queue, 22);
    enterQueue(&queue, 33);
    enterQueue(&queue, 44);
    enterQueue(&queue, 55);
    enterQueue(&queue, 66);
    enterQueue(&queue, 77);
    enterQueue(&queue, 88);
    showQueue(&queue);
    int outValue;
    outQueue(&queue,&outValue);
    printf(" \n out value is %d \n",outValue);
    showQueue(&queue);
    
    return 0;
}

void init(pQueue pQ , int length){
    pQ->pBase =  (int *)malloc(sizeof(int) *length);
    pQ ->front = 0;
    pQ ->rear = 0;
    pQ ->leng = length;
}


bool fulled(pQueue pQ) {
    if ((pQ ->rear + 1)% pQ->leng == pQ ->front)
    {
        printf("is full , Can 't enter !\n");
        return true;
    } else
    {
         return false;
    }
}

bool empty(pQueue pQ ) {
    if (pQ->front == pQ ->rear)
    {
         printf("is empty , Can 't out!\n");
        return true;
    } else
    {
         return false;
    }
}

bool enterQueue(pQueue pQ, int value)
{
    if ( fulled(pQ))
    {   
        return false;
    }  else
    {
        pQ ->pBase[pQ ->rear] = value;
        pQ ->rear = (pQ ->rear +1)%pQ->leng;
        return true;
    }
}

bool outQueue(pQueue pQ, int *pOutElementValue) {
    if (empty(pQ))
    {
        return false;
    } else
    {
        int value = pQ->pBase[pQ ->front];
        pQ ->front = (pQ ->front +1)%(pQ ->leng);
        *pOutElementValue = value;//此处不能写pOutElementValue = &value; 这样相当于把pOutElementValue的指针指向了value的地址
                                //而value出了域后就释放了！应该把value的值放到 pOutElementValue 的指针里。即 
                                //pOutElementValue的地址 等于value .==> *pOutElementValue = value.
                                //而不是pOutElementValue指向value的地址
    }
}

void showQueue(pQueue pQ) {
    int f = pQ ->front;
    while (f != pQ ->rear)
    {   
        printf("%d ->",pQ ->pBase[f]);
        f = (f+1 )% pQ ->leng;
    }
}

