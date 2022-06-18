#include "line.h"

static line* InitLine(line* head);
static void printLine(line* head);
static line* AddLine(line* head, int newelem, int locat);
static line* DelLine(line* head, int elem);
static int SearchLine(line* head, int elem);
static line* AmendLine(line* head, int newelem, int oldelem);

void measureLine()
{
	line* head = NULL;
		head=InitLine(head);
		printf("初始链表：\n");
		printLine(head);
		head = AddLine(head, 50, 6);
		printf("\n添加操作后的链表：\n");
		printLine(head);
		printf("\n删除操作后的链表：\n");
		head = DelLine(head, 50);
		printLine(head);
		printf("\n查找元素操作：\n");
		int i = SearchLine(head, 3);
		printf("查找元素的位置为：%d\n", i);
		
		printf("\n修改操作后的链表：\n");
		head = AmendLine(head,100,3);
		printLine(head);

}





//功能：初始化双向链表
//返回值：初始化完成的双向链表的头指针
static line* InitLine(line* head)
{
	//创建首元节点
	head = (line*)malloc(sizeof(line));
	head->up = NULL;
	head->rear = NULL;
	head->data = 1;
	line* temp = head;
	for (int i = 2; i <=4; i++)
	{
		//创建并初始化一个新节点
		line* body = (line*)malloc(sizeof(line));
		body->up = NULL;
		body->rear = NULL;
		body->data = i;
		//将新建节点与上个节点建立联系
		temp->rear = body;//直接前驱节点的rear指针指向新节点
		body->up = temp;//新节点的up指针指向直接前驱节点
		temp = temp->rear;
	}


	return head;
 }

//功能：往双向链表中添加元素
//head：待操作的链表的头指针（首元节点） newelem:添加元素 locat：添加位置
//返回值：操作完成的头指针
static line* AddLine(line* head,int newelem,int locat)
{
	line* temp = head;
	//创建待添加的节点
	line* tempbody = (line*)malloc(sizeof(line));
	tempbody->up = NULL;
	tempbody->rear = NULL;
	tempbody->data = newelem;
	if (locat == 1) {
		tempbody->rear = head;
		head->up = tempbody;
		head = tempbody;
	}
	else
	{
		for (int i = 1; i < locat-1; i++)
		{
			if (temp->rear==NULL)
			{
				break;
			}
			temp = temp->rear;
		}
		if (!temp->rear)//插入末尾
		{
			temp->rear = tempbody;
			tempbody->up = temp;
		}
		else//插到中间
		{
			tempbody->rear = temp->rear;
			temp->rear->up = tempbody;
			temp->rear = tempbody;
			tempbody->up = temp;
		}
	
	
		
	}


	return head;
}

//功能：删除链表中的元素
//head：待操作的链表的头指针（首元节点）  elem：删除的元素
//返回值：操作完后的头指针

static line* DelLine(line* head, int elem)
{
	line* temp = head;
	while (temp)//遍历链表
	{
		if (temp->data == elem)//找到该元素
		{
			//if (temp->up==NULL)
				//head = temp->rear;
			if (temp->rear == NULL) {//删除最后的节点
				temp->up->rear = temp->rear;
				
			}
			else if (temp->up == NULL) { //删除首元节点
				temp->rear->up = temp->up;
				head = temp->rear;
			}
			else {
				temp->rear->up = temp->up;
				temp->up->rear = temp->rear;
			}
			free(temp);
			return head;
		}
		temp = temp->rear;
	}

	printf("未找到该元素\n");


	return head;
}


//功能：查找链表中的元素
//head：待查找的链表 elem：查找元素
//返回值:查找成功返回元素位置，失败返回-1
static int SearchLine(line* head, int elem)
{
	line* temp = head;
	int i = 1;
	while (temp)
	{
		if (temp->data == elem)
			return i;
		i++;
		temp = temp->rear;
	}

	printf("未找到该元素\n");
	return -1;


}

//功能：更改链表中的元素
//head：待操作的链表  newelem:更新后的元素  oldelem:更新元素
//返回值：更新完后的链表头指针
static line* AmendLine(line* head, int newelem, int oldelem)
{
	line* temp = head;
	while (temp)
	{
		if (temp->data==oldelem)
		{
			temp->data = newelem;
			return head;
		}

		temp = temp->rear;

	}

	printf("未找到需要修改的元素\n");

	return head;
}


//功能：打印双向链表中的元素
static void printLine(line* head)
{
	line* temp=head;
	int i = 1;
	while (temp!=NULL)
	{
		printf("元素%d:%d<->", i, temp->data);
		i++;
		temp = temp->rear;
	}
}
