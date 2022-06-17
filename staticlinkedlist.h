#pragma once
#ifndef _STATICLINKEDLIST_H
#define _STATICLINKEDLIST_H

#define ArraySize 6

//静态链表
//静态链表使用数组申请的物理空间中，存有两个链表，一条连接数据，另一条连接数组中未使用的空间(备用链表)
//建立的数据链表可以存在头结点（即第一个位置不存放数据），也可以不含头结点。含头结点的数据链表执行某些功能时更加方便（比如删除链表中某个元素）
//使用静态链表存储数据，需要预先申请足够大的一整块内存空间，也就是说，静态链表存储数据元素的个数从其创建的那一刻就已经确定，后期无法更改。
//每次向静态链表中添加数据需要先向备用链表申请空间
//每次删除静态链表中的数据需要回收空间到备用链表

typedef struct 
{
	int data;//数据位
	int next;//下个数据位游标
}STALL;
extern void MeasureSTALL();

#endif // !_STATICLINKEDLIST_H
