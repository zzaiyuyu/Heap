#include "Heap.h"

void TopK(int data[], int len, int top[])
{
	const int MaxLen = 5;
	Heap heap;
	InitHeap(&heap, Less);
	CreateHeap(&heap, data, MaxLen);
	int res = len - MaxLen; //ʣ����Ҫ�����Ԫ�ظ���
							//ά��һ��ֻ�������ֵ�Ķ�
	while (res) {
		if (data[len - res] > TopHeap(&heap)) {
			DeleteHeap(&heap);
			InsertHeap(&heap, data[len - res]);
		}
		res--;
	}
	//��ʱ��Ԫ�ؾ�������5��Ԫ��
	int i = 0;
	for (i = 0; i < 5; i++) {
		top[i] = TopHeap(&heap);
		DeleteHeap(&heap);
	}
}
void testTopK()
{
	/*
	��������һ��װ�����ڴ����Ҫ��������
	��ʱ�����ѣ������ⲿ������,�����ڴ�ֻ��װ5������
	*/
	int data[9] = { 53,17,78,9,45,65,87,23,31 };
	int len = sizeof(data) / sizeof(data[0]);
	int top5[5] = { 0 };
	TopK(data, len, top5);
}
