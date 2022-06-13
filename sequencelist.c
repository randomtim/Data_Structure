#include"sequencelist.h"

void fillSEL(table t);
table InitTable(int size);
void printSEL(table t);
table Add_TABLE(table t, int elem, int locat);
table Del_TABLE(table t, int locat);
int Search_TABLE(table t, int elem);
table Amend_TABLE(table t, int elem, int newelem);
//return:初始化的结构体
table InitTable(int size)//顺序表初始化
{
	table t;
	t.head = (int*)malloc(size * sizeof(int));//构建一个大小为size的空的顺序表
	if (!t.head)//初始化失败
	{
		printf("初始化失败！\n");
		exit(0);
	}
	
	t.size = size;
	t.length = 0;
	return t;
}


void printSEL(table t)//打印顺序表中的元素
{
	printf("顺序表中的数为：\n");
	for (int i = 0; i < t.length; i++)
	{
		printf("%d\n", t.head[i]);
	}

	
}


void fillSEL(table t)//填充顺序表
{
	for (int i = 0; i < t.size; i++)
	{
		t.head[i] = t.size - i;
		t.length++;
	}
	printf("length=%d\n", t.length);
}


void measureSEL()//顺序表操作一体化
{
	table t=InitTable(7);
	for (int i = 0; i < t.size; i++)
	{
		t.head[i] = t.size - i;
		t.length++;
	}
	printf("length=%d\n", t.length);
	printSEL(t);
}

//功能：给顺序表中插入值
//elem 需要插入的数 
//locat 插入位置
table Add_TABLE(table t,int elem,int locat)
{
	//判断插入位置是否存在问题
	if (locat>t.length||locat<1)
	{
		printf("插入位置错误!\n");
		return t;
	}
	
	if (t.length==t.size)//如果顺序表已经满员，扩充空间
	{
		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
		if (!t.head)
		{
			printf("存储空间分配失败!\n");
		}
		t.size++;//分配成功，顺序表容量加1
	
	}
	//将原表从插入位置整体后移
	for (int i = t.length-1; i >=locat-1; i++)
	{
		t.head[i + 1] = t.head[i];
	}
	//后移完成后在需要插入的位置直接插入新值
	t.head[locat - 1] = elem;
	//添加了新值，长度增加
	t.length++;
	
	return t;
}



//功能：删除顺序表中的某个值
//locat:需要删除元素的位置
table Del_TABLE(table t,int locat)
{
	//判断需要删除的元素的位置是否正确
	if (locat>t.length||locat<1)
	{
		printf("删除元素位置错误!\n");
		return t;
	}

	//删除操作——即从删除位置开始，后面的元素整体前移一位
	for (int i = locat-1; i < t.length-1; i++)
	{
		t.head[i] = t.head[i + 1];
	}
	t.length--;

	return t;

}

//功能：查找顺序表中的元素
//elem:需要查找的元素
//返回值：成功——查找元素的位置
//		  失败——0
int Search_TABLE(table t,int elem)
{
	for (int i = 0; i < t.length; i++)//顺序查找法  O(n)
	{
		if (t.head[i]==elem)
		{
			return i + 1;
		}
	}


	return 0;

}

//功能：直接修改顺序表中的值
//elem:需要修改的值
//newelem:需要修改成的值
table Amend_TABLE(table t, int elem, int newelem)
{
	int locat = Search_TABLE(t, elem);
	if (!locat)
	{
		printf("未找到需要替换的元素!\n");
		return t;
	}
	t.head[locat - 1] = newelem;

	return t;
}


