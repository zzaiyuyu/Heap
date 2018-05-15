#include "Heap.h"

void TopK(int data[], int len, int top[])
{
	const int MaxLen = 5;
	Heap heap;
	InitHeap(&heap, Less);
	CreateHeap(&heap, data, MaxLen);
	int res = len - MaxLen; //剩余需要处理的元素个数
							//维护一个只有五个数值的堆
	while (res) {
		if (data[len - res] > TopHeap(&heap)) {
			DeleteHeap(&heap);
			InsertHeap(&heap, data[len - res]);
		}
		res--;
	}
	//此时堆元素就是最大的5个元素
	int i = 0;
	for (i = 0; i < 5; i++) {
		top[i] = TopHeap(&heap);
		DeleteHeap(&heap);
	}
}
void testTopK()
{
	/*
	海量数据一次装不到内存里，需要分批处理。
	此时建立堆，或者外部排序解决,假设内存只能装5个数据
	*/
	int data[9] = { 53,17,78,9,45,65,87,23,31 };
	int len = sizeof(data) / sizeof(data[0]);
	int top5[5] = { 0 };
	TopK(data, len, top5);
}
