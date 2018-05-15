#pragma once
#include "Heap.h"
typedef struct PriorityQueue
{
	Heap _hp;
}PriorityQueue;

// ���ȼ����г�ʼ�� 
void PriorityQueueInit(PriorityQueue* q, cmp com);

// ������в���Ԫ�� 
void PriorityQueuePush(PriorityQueue* q, DataType data);

// ɾ�����ȼ���ߵ�Ԫ�� 
void PriorityQueuePop(PriorityQueue* q);

// ��ȡ���������ȼ���ߵ�Ԫ�� 
int PriorityQueueSize(PriorityQueue* q);

// ������ȼ������Ƿ�Ϊ�� 
int PriorityQueueEmpty(PriorityQueue* q);

// ��ȡ�Ѷ���Ԫ�� 
DataType PriorityQueueTop(PriorityQueue* q);

// �������ȼ����� 
void PriorityQueueDestroy(PriorityQueue* q);

void testQueue();