#include"ring.h"

//初始化循环链表
ring* InitRing(ring* head,int size)
{
	//开辟首元结点空间
	head = (ring*)malloc(sizeof(ring));
	head->data = 1;
	head->next = NULL;
	
	ring* temp = head;//创建临时指针
	
	for (int i = 1; i < size; i++)
	{
		ring* body = (ring*)malloc(sizeof(ring));//待初始的节点
		//初始化
		body->data = i + 1;
		body->next = NULL;
		//建立与上一个节点的连接
		temp->next = body;
		//temp始终指向最后一个节点
		temp = body;
	}
	//首尾相连
	temp->next = head;
	return head;
}

void printRing(ring* head)
{
	int i = 0;
	ring* temp = head;
	for ( i=0;temp->next!=head;i++)
	{
		printf("第%d个节点：%d\n", i + 1, temp->data);
		temp = temp->next;
	}
	printf("第%d个节点：%d\n", i+1, temp->data);

}






