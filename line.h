#ifndef _LINE_H
#define _LINE_H
#include "stdlib.h"
#include "stdio.h"
//双向链表：链表中各节点的逻辑是双向的（通常头指针只设置一个）
//

typedef struct LINE {
	struct LINE* up;//指向直接前驱
	int data;//数据域
	struct LINE* rear;//指向直接后驱
}line;

extern void measureLine();


#endif // !_LINE_H

