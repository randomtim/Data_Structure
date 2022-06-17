#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "stdlib.h"
#include "stdio.h"
//单链表
/*
完整的链表构成：
1、头指针：一个普通的指针，特点是永远指向链表第一个节点的位置。
2、节点：链表中的节点又分为头结点、首元节点和其它节点
	头结点：不存任何数据的空节点，通常作为链表的第一个节点。对于链表来说头结点不是必须的
	首元节点：链表中第一个存放数据的节点

链表中有头结点时头指针指向头结点，反之指向首元节点
*/

typedef struct LINK {
	int elem;//数据域，存储数据
	struct LINK* next;//指针域，指向下一个节点
}link;//节点名，每一个节点都是一个link结构体

/*不含头结点的链表的操作*/
link* InitLinked(int size);
void Displaylist(link* head);
link* Insertlinked(link* head, int newelem, int locat);
link* DelLinked(link* head, int locat);
int SeekLinked(link* head, int elem);
link* AmendLinked(link* head, int newelem, int locat);




/*含头结点的链表的操作*/
link* InitLinked_H(int size);
void Displaylist_H(link* head);
link* Insertlinked_H(link* head, int newelem, int locat);
link* DelLinked_H(link* head, int locat);
int SeekLinked_H(link* head, int elem);
link* AmendLinked_H(link* head, int newelem, int locat);


/*链表反转函数*/
link* IterationReverse(link* head);
link* RecursiveReverse(link* head);
link* HeadReverse(link* head);
link* LocalReverse(link* head);


#endif // !_LINKEDLIST_H

