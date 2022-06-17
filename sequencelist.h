#pragma once
#ifndef _SEQUENCELIST_H
#define _SEQUENCELIST_H
#include "stdlib.h"
#include "stdio.h"
//顺序表
typedef struct TABLE {
	int* head;
	int length;//记录当前顺序表的长度
	int size;//记录顺序表的分配的存储容量
}table;


extern void measureSEL();

#endif // !_SEQUENCELIST_H
