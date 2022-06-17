#include "staticlinkedlist.h"


static void ReserveArr(STALL* array);
static int MallocArray(STALL* array);
static int InitArray(STALL* array);
static void printArray(STALL* array, int body);
static void Add_Array(STALL* array, int newelem, int locat, int body);
static void FreeArray(STALL* array, int locat);
static void DelArray(STALL* array, int body, int elem);
static int SearchArray(STALL* array, int body, int elem);
static void AmendArray(STALL* array, int body, int oelem, int nelem);
//功能：静态链表操作一体(静态链表功能调试在此函数中进行)
//返回值：无
void MeasureSTALL()
{
	STALL array[ArraySize];//创建静态链表
	int body = InitArray(array);
	printf("静态链表为：\n");
	printArray(array, body);
	Add_Array(array, 50, 10, body);
	printf("\n添加后的静态链表为：\n");
	printArray(array, body);
	printf("\n删除后的静态链表为：\n");
	DelArray(array, body, 50);
	printArray(array, body);
	printf("\n查找的元素的位置：\n");
	int i=SearchArray(array, body, 3);
	printf("查找元素的游标：%d\n", i);
	printf("\n修改后的静态链表为：\n");
	AmendArray(array, body, 3, 50);
	printArray(array, body);
}



//功能：创建备用链表（备用链表用来连接未使用的空间）
//array：待操作的静态链表
//返回值：无
static void ReserveArr(STALL* array)
{
	for (int i = 0; i < ArraySize; i++)
	{
		array[i].data = -1;
		array[i].next = i + 1;//将每个数组分量通过游标连接起来
	}

	array[ArraySize - 1].next = 0;//最后一个节点的游标指向 0
}

//功能：提取分配空间
//array：待操作的静态链表
//返回值：返回分配的节点的下标
static int MallocArray(STALL* array)
{
	int i = array[0].next;
	if (i==0)
	{
		printf("空间已满\n");
		return -1;
	}
	if (array[0].next)
	{
		array[0].next = array[i].next;
	}

	return i;
}


//功能：初始化静态链表
//array：待操作的静态链表
//返回值：数据链表开始的游标
static int InitArray(STALL* array)
{
	int j = 0;
	ReserveArr(array);//创建备用链表
	int body = MallocArray(array);//分配一个空间
	int tempbody = body;
	for (int i = 1; i < 4; i++)
	{
		j = MallocArray(array);
		array[tempbody].next = j;
		array[j].data = i;
		tempbody = j;
	}
	
	array[tempbody].next = 0;
	return body;
}

//功能：往静态链表中添加元素
//array：目标静态链表  newelem:新元素  locat：添加位置 body:头结点在静态链表中的位置
static void Add_Array(STALL* array,int newelem,int locat,int body)
{
	int tempbody = body;
	for (int i = 1; i < locat; i++)
	{
		if (array[array[tempbody].next].next==0)
		{
			break;
		}
		tempbody = array[tempbody].next;
		
	}
	int insert = MallocArray(array);//申请空间
	//赋值
	array[insert].data = newelem;
	//建立连接
	array[insert].next = array[tempbody].next;
	array[tempbody].next = insert;

}

//功能：释放数据链表中的数据将空间归还给备用链表
//array：待操作的静态链表 locat:操作位置
static void FreeArray(STALL* array,int locat)
{
	array[locat].next = array[0].next;
	array[0].next = locat;
}

//功能：删除链表中的元素
//array：待操作的静态链表 body：数据链表的起始游标 elem：删除的数据
static void DelArray(STALL* array, int body, int elem)
{
	int tempbody = body;
	while (array[tempbody].data!=elem)
	{
		if (!array[tempbody].next)//下一个游标为0表示遍历完链表未找到元素
		{
			printf("链表中不存在此元素\n");
			return;
		}
		tempbody = array[tempbody].next;
	}

	//找到待删除的元素的位置
	int del = tempbody;
	int i = body;
	//找到删除元素的直接前驱元素
	while (array[i].next!=del)
	{
		i = array[i].next;
	}
	//将直接前驱元素和直接后驱元素建立联系
	array[i].next = array[del].next;
	//回收空间
	FreeArray(array, del);
}


//功能：查找静态链表中的元素
//array：待查找的静态链表 body：数据链表的起始游标 elem：查找元素
//返回值：成功返回元素位置，失败返回-1
static int SearchArray(STALL* array, int body, int elem)
{
	int tempbody = body;
	
	while (tempbody!=0)
	{
		if (array[tempbody].data==elem)
		{
			return tempbody;
		}
		tempbody = array[tempbody].next;
	}

	return -1;

}

//功能：更改静态链表中的数据
//array:待操作的链表 body：数据链表的起始游标  oelem:修改的元素  nelem：修改成的元素
static void AmendArray(STALL* array, int body, int oelem, int nelem)
{
	
	int amend = SearchArray(array, body, oelem);
	if (amend==-1)
	{
		printf("未找到需要修改的元素\n");
		return;
	}
	array[amend].data = nelem;
}



//功能：打印静态链表中的数据
//array：待打印的静态链表  body：数据链表的起始游标
static void printArray(STALL* array,int body)
{
	int tempbody = body;
	
	while (array[tempbody].next)
	{
		printf("游标:%d 数据:%d 下一个数据的游标:%d\n", tempbody, array[tempbody].data,array[tempbody].next);
		tempbody = array[tempbody].next;
	}
	printf("游标:%d 数据:%d 下一个数据的游标:%d\n", tempbody, array[tempbody].data, array[tempbody].next);
}



