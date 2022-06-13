#include "linkedlist.h"


//功能：初始化链表(不包含头结点的链表)
//size:链表长度
//返回值：创建完成的链表的头指针地址
link* InitLinked(int size)
{
	link* head = NULL;//创建头指针
	link* temp = (link*)malloc(sizeof(link));//创建首元节点
	//首元节点初始化
	temp->elem = 1;
	temp->next = NULL;
	head = temp;//头指针指向首元节点
	for (int i = 1; i < size; i++)
	{
		link*  a = (link*)malloc(sizeof(link));//开辟空间
		//节点初始化
		a->elem =i+1;
		a->next = NULL;
		//将新建立的节点与temp建立关系
		temp->next = a;
		//使temp指针一直指向新链表的最后一个节点
		temp = a;
	}

	return head;
}


//功能：打印链表中的元素(不包含头结点的链表)
//head：需要打印的链表的头指针
void Displaylist(link* head)
{
	short i = 1;
	link* temp = NULL;
	temp = head;
	while (temp)
	{
		printf("%d=%d\n", i, temp->elem);
		temp = temp->next;
		i++;
	}
	printf("\n");
}


//功能：往链表插入元素(不包含头结点的链表)
//head：头指针  newelem:新数据元素  locat:插入位置
//返回值:新链表头指针
link* Insertlinked(link* head, int newelem, int locat)
{
	link* temp = head;//头指针指向首元节点
	for (int i = 1; i < locat-1; i++)
	{
		if (!temp)
		{
			printf("插入位置有误！\n");
			return head;
		}
		temp = temp->next;
	}
	//创建待插入节点
	link* add = (link*)malloc(sizeof(link));
	//给待插入节点赋值
	add->elem = newelem;
	//建立连接
	add->next = temp->next;
	temp->next = add;

	return head;
}


//功能：删除链表中的元素(不包含头结点的链表)
//head:待删除元素的链表 locat：删除位置
//返回值：返回删除元素后的链表
link* DelLinked(link* head, int locat)
{
	link* temp = head;//创建临时节点指向头指针
	for (int i = 1; i < locat-1; i++)//找到待删除节点的直接前驱节点
	{
		if (!temp)
		{
			printf("删除位置有误！\n");
			return head;
		}
		temp = temp->next;
	}

	link* del = temp->next;//创建一个指针指向被删除的节点，防止丢失
	temp->next = del->next;	//temp->next=temp->next->next;
	free(del);//手动释放空间
	return head;

}


//功能：从链表中查找元素(不包含头结点的链表)
//head：待查找的链表  elem：需要查找的元素
//返回值：查找失败返回 0，查找成功返回元素位置
int SeekLinked(link* head, int elem)
{
	link* temp = head;//创建一个临时指针指向头指针
	int i = 1;
	while (temp!= NULL)
	{
		if (temp->elem == elem)
		{
			return i; //返回元素所在节点位置
		}
		temp = temp->next;	
		i++;
	}

	//执行到此处表示查找失败
	return 0;
}


//功能：更新链表中节点的元素(不包含头结点的链表)
//head：待更新的链表的头结点 newelem：新值 locat：需要更新的节点的位置
//返回值：链表的头结点
link* AmendLinked(link* head, int newelem, int locat)
{
	link* temp = head;//创建一个临时指针指向链表的头指针（首元节点）

	for (int i = 1; i <= locat-1; i++)
	{
		if (!temp) {
			printf("更新节点有误！\n");
			return head;
		}
		temp = temp->next;
		
	}
	temp->elem = newelem;
	return head;
}


//功能：初始化链表(包含头结点)
//size:需要创建的包含头结点的链表的大小
//返回值：创建完成的链表的头结点地址 
link* InitLinked_H(int size)
{
	link* p = (link*)malloc(sizeof(link));//创建一个头结点
	link* temp = p;//声明一个指针指向头结点，用于遍历链表
	for (int i = 1; i < size; i++)
	{
		link* a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}

	return p;
}


//功能：打印链表中的元素（链表包含头结点）
//head:需要打印信息的链表的头指针
void Displaylist_H(link* head)
{
	int i = 1;
	link* temp = NULL;
	temp = head;//使temp指针指向头结点
	while (temp->next!=NULL)
	{
		temp = temp->next;
		printf("%d=%d\n", i, temp->elem);
	}
	printf("\n");
}


//功能：往链表中插入元素（含头结点）
//head：待插入元素的链表的头指针 newelem:新数据元素  locat：插入位置
//返回值：返回插入完成后的链表的头指针
link* Insertlinked_H(link* head, int newelem,int locat)
{
	link* temp=head;//创建临时节点
	//找到要插入位置的上一个节点
	for (int i = 1;i < locat; i++)//链表包含头结点
	{
		temp = temp->next;
		if (!temp)
		{
			printf("插入位置有误！\n");
		}
	
	}
	//创建插入节点
	link* c = (link*)malloc(sizeof(link));
	//插入新节点
	c->elem = newelem;
	//建立新连接
	c->next = temp->next;
	temp->next = c;
	return head;//返回插入后的链表的头指针
}


//功能：删除链表中的元素（包含头结点的链表）
//head:待删除元素的链表 locat：删除位置
//返回值：返回删除元素后的链表
link* DelLinked_H(link* head, int locat)
{
	link* temp = head;//创建临时节点指向头结点
	for (int i = 1; i < locat; i++)//找到待删除节点的直接前驱节点
	{
		temp = temp->next;
		if (!temp)
		{
			printf("删除位置有误！\n");
			return head;
		}
	}

	link* del = temp->next;//创建一个指针指向被删除的节点，防止丢失
	temp->next = del->next;	//temp->next=temp->next->next;
	free(del);//手动释放空间
	return head;
}


//功能：从链表中查找元素（包含头结点）
//head：待查找的链表  elem：需要查找的元素
//返回值：查找失败返回 0，查找成功返回元素位置
int SeekLinked_H(link* head, int elem)
{
	link* temp = head;//创建一个临时指针指向头结点
	int i = 1;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		if (temp->elem==elem)
		{
			return i; //返回元素所在节点位置
		}
		i++;
	}

	//执行到此处表示查找失败
	return 0;
}


//功能：更新链表中节点的元素（包含头结点）
//head：待更新的链表的头结点 newelem：新值 locat：需要更新的节点的位置
//返回值：链表的头结点
link* AmendLinked_H(link* head, int newelem, int locat)
{
	link* temp = head;//创建一个临时指针指向链表的头结点
	
	for (int i = 1; i <=locat; i++)
	{
		temp = temp->next;
		if (!temp) {
			printf("更新节点有误！\n");
			return head;
		}
	}
	temp->elem = newelem;
	return head;
}



//1、迭代反转链表
//功能：反转链表（不包含头结点）
//head:需要反转的链表的头指针
//返回值：反转完成的链表的头指针
link* IterationReverse(link* head)
{
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	else
	{
		//定义三个指针
		link* begin = NULL;
		link* mid = head;
		link* end = head->next;
		//一直遍历
		while (1)
		{
			//修改mid节点的指向
			mid->next = begin;
			
			if (end==NULL)
			{
				break;
			}

			//移动指针
			begin = mid;
			mid = end;
			end = end->next;
		}
		head = mid;
		return head;
	}




}


//2、递归反转链表
//功能：反转链表（不包含头结点）
//head：需要反转的链表的头指针
//返回值：反转完成的链表的头指针
link* RecursiveReverse(link* head)
{
	//递归出口
	if (head == NULL || head->next == NULL)
		return head;
	else {
		//一直递归，直到找到出口
		link* newhead = RecursiveReverse(head->next);

		//当逐层退出时，newhead 的指向都不变，一直指向原链表中最后一个节点；
	    //递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。

		//每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
		head->next->next = head;//每层递归，此head指向上一个节点的地址
		head->next = NULL;
		//每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
		return newhead;

	}





}