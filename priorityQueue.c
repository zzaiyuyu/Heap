#include "priorityQueue.h"
#include <assert.h>
// 优先级队列初始化 
void PriorityQueueInit(PriorityQueue* q, cmp com)
{
	assert(q);
	InitHeap(&q->_hp, com);
}

// 向队列中插入元素 
void PriorityQueuePush(PriorityQueue* q, DataType data)
{
	InsertHeap(&q->_hp, data);
}
// 删除优先级最高的元素 
void PriorityQueuePop(PriorityQueue* q)
{
	DeleteHeap(&q->_hp);
}

// 获取队列元素个数
int PriorityQueueSize(PriorityQueue* q)
{
	return SizeHeap(&q->_hp);
}

// 检测优先级队列是否为空 
int PriorityQueueEmpty(PriorityQueue* q)
{
	return EmptyHeap(&q->_hp);
}

// 获取堆顶的元素 
DataType PriorityQueueTop(PriorityQueue* q)
{
	return TopHeap(&q->_hp);
}

// 销毁优先级队列 
void PriorityQueueDestroy(PriorityQueue* q)
{
	DestroyHeap(&q->_hp);
}

void testQueue()
{
	PriorityQueue q;
	PriorityQueueInit(&q, Less);
	int arr[9] = { 53,17,78,9,45,65,87,23,31 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++) {
		PriorityQueuePush(&q, arr[i]);
	}
	PriorityQueueTop(&q);
	PriorityQueueSize(&q);
	PriorityQueuePop(&q);
	PriorityQueueTop(&q);
}