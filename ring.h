#ifndef _RING_H
#define _RING_H

#include <stdio.h>
#include <stdlib.h>

//循环链表——首尾节点相连

typedef struct RING {
	int data;//数据域
	struct RING* next;//指针域 指向下一个节点
}ring;

ring* InitRing(ring* head, int size);
void printRing(ring* head);

#endif // !_RING_H

