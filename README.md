# SeqList
//静态顺序表

//SeqList.h
#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#pragma once
#include<stdio.h>
#define MAX_SIZE 10 
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size; // 顺序表中有效元素的个数 
}SeqList, *PSeqList;


void SeqListInit(PSeqList ps);//初始化
void SeqListPushBack(PSeqList ps, DataType data);//尾插
void SeqListPopBack(PSeqList ps);//尾删
void SeqListPushFront(PSeqList ps, DataType data);//头插
void SeqListPopFront(PSeqList ps);//头删
void SeqListInsert(PSeqList ps, size_t pos, DataType data);// 任意位置中插入值为data的元素 
void SeqListErase(PSeqList ps, size_t pos);// 删除任意位置中的元素
void SeqListRemove(PSeqList ps, DataType data);// 删除顺序表中值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data);// 删除顺序表中所有值为data的元素 


int SeqListEmpty(PSeqList ps);// 判断顺序表是否为空 
int SeqListSize(PSeqList ps);// 获取顺序表中元素的个数 
void PrintSeqList(PSeqList ps);// 打印顺序表中的元素 

// 在顺序表中查找值为data的元素，返回该元素在顺序表中的下标 
int SeqListFind(PSeqList ps, DataType data);

// 用冒泡排序对顺序表中的元素进行排序 
void BubbleSort(int* array, int size);

// 用选择排序对顺序表中的元素进行排序 
void SelectSort(int* array, int size);

// 选择排序优化---一次找出最大最小元素所在的位置 
void SelectSort_OP(int* array, int size);

#endif //__SEQLIST_H__


//SeqList.c

#include "SeqList.h"

void PrintSeqList(PSeqList ps)
{
	int i = 0;
	//顺序表为空
	if (NULL == ps)
		return;
	
	for (i = 0; i < ps->_size;i++)
	{
		printf("%d ",ps->_array[i]);
	}
	printf("\n");
}
void SeqListInit(PSeqList ps)
{
	if (NULL == ps)
		return;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)
{
	//顺序表为空
	if (NULL == ps)
		return;
	//顺序表满了
	if (MAX_SIZE == ps->_size)
		return;

	ps->_array[(ps->_size)++] = data;
}

void SeqListPopBack(PSeqList ps)
{
	//顺序表为空
	if (NULL == ps)
		return;
	//数组无元素
	if (0 == ps->_size)
		return;

	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)
{
	int i = 0;
	//顺序表为空
	if (NULL == ps)
		return;
	//顺序表满了
	if (MAX_SIZE == ps->_size)
		return;

	for (i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}

	ps->_array[0] = data;
	++ps->_size;

}

void SeqListPopFront(PSeqList ps)
{
	int i = 0;
	//顺序表为空
	if (NULL == ps)
		return;
	//数组无元素
	if (0 == ps->_size)
		return;

	for (i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	--ps->_size;
}

void SeqListInsert(PSeqList ps, size_t pos, DataType data)
{
	int i = 0;
	//顺序表为空
	if (NULL == ps)
		return;
	//  顺序表满了                
	if (MAX_SIZE == ps->_size)
		return;
	//顺序表没有元素
	if (ps->_size == 0)
	{
		if (1 == pos)
		{
			ps->_array[pos - 1] = data;
			ps->_size++;
			return;
		}
		else
			return;
	}
	//pos位置超出范围
	if (pos > (ps->_size+1))
		return;

	//pos在头部、中间位置
	for (i = ps->_size; i >= pos; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}

	//尾部也能处理
	ps->_array[pos-1] = data;
	ps->_size++;
}

void SeqListErase(PSeqList ps, size_t pos)
{
	int i = 0;
	//空顺序表
	if (NULL == ps)
		return;
	//元素个数为0        //pos 位置超出范围
	if (0 == ps->_size || pos > ps->_size)
		return;
	
	for (i = pos - 1; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	--ps->_size;
}

int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	//空顺序表
	if (NULL == ps)
		return -1;
	//顺序表无元素
	if (0 == ps->_size)
		return -1;
	
	for (i = 0; i < ps->_size; ++i)
	{
		if (data == ps->_array[i])
			return i;
	}

	return -1;
}

void SeqListRemove(PSeqList ps, DataType data)
{
	int i = 0;
	//空顺序表
	if (NULL == ps)
		return;
	//顺序表无元素
	if (0 == ps->_size)
		return;
	
	for (i = 0; i < ps->_size; ++i)
	{
		int j = 0;
		if (data == ps->_array[i])
		{
			for (j = i; j < ps->_size - 1; ++j)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			--ps->_size;
			return;
		}
	}
	//该元素不存在
}

void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int count = 0;
	int i = 0;
	//空顺序表
	if (SeqListEmpty(ps))
		return;
	//顺序表无元素
	if (0 == ps->_size)
		return;

	for (i = 0; i < ps->_size; ++i)
	{
		if (data == ps->_array[i])
			++count;
		else
			ps->_array[i - count] = ps->_array[i];
	}

	ps->_size = ps->_size - count;
	//该元素不存在
}
int SeqListEmpty(PSeqList ps)
{
	return NULL == ps;
}

int SeqListSize(PSeqList ps)
{
	return ps->_size;
}

void BubbleSort(int* array, int size)
{
	int Max = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < size - 1; i++)
	{
		int IsChange = 0;//升序
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				int temp = 0;
				temp = array[j-1];
				array[j - 1] = array[j];
				array[j] = temp;
				IsChange = 1;
			}

		}
	}
}

void SelectSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	int Max = 0;
	int MaxPos = 0;
	for (i = 0; i < size - 1; ++i)
	{
		//找到最大元素
		MaxPos = 0;
		Max = array[0];
		for (j = 0; j < size - i; ++j)
		{
			if (array[j] > Max)
			{
				Max = array[j];
				MaxPos = j;
			}

		}

		if (MaxPos != size - 1 - i)
		{
			int temp = 0;
			temp = array[MaxPos];
			array[MaxPos] = array[size - 1 - i];
			array[size - 1 - i] = temp;
		}

	}
}

void SelectSort_OP(int* array, int size)
{
	int i = 0;
	int j = 0;
	int Max = 0;
	int Min = 0;

	int MaxPos = 0;
	int MinPos = 0;

	for (i = 0; i <= size/2; ++i)
	{
		//找到最大元素
		MaxPos = 0;
		Max = array[0];
		
		MinPos = i;
		Min = array[i];
		for (j = 0; j < size - i; ++j)
		{
			if (array[j] > Max)
			{
				Max = array[j];
				MaxPos = j;
			}

		}

		if (MaxPos != size - 1 - i)
		{
			int temp1 = 0;
			temp1 = array[MaxPos];
			array[MaxPos] = array[size - 1 - i];
			array[size - 1 - i] = temp1;
		}


		for (j = i; j < size - 1; ++j)
		{
			if (Min > array[j])
			{
				Min = array[j];
				MinPos = j;
			}

		}

		if (MinPos != i)
		{
			int temp2 = 0;
			temp2 = array[MinPos];
			array[MinPos] = array[i];
			array[i] = temp2;
		}

	}
}


//test.c
#include "SeqList.h"

void PrintSeqList(PSeqList ps);

void TestSeqListInit()
{
	SeqList s;
	SeqListInit(&s);
}

void TestSeqListPushBack()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(NULL, 1);
	SeqListPushBack(&s, 1);
	PrintSeqList(&s);

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 0);

	PrintSeqList(&s);
}

void TestSeqListPushFront()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(NULL, 1);//空
	SeqListPushFront(&s, 1);
	PrintSeqList(&s);

	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	PrintSeqList(&s);

	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 7);
	SeqListPushFront(&s, 8);
	SeqListPushFront(&s, 9);
	SeqListPushFront(&s, 0);
    PrintSeqList(&s);

	SeqListPushFront(&s, 0);//满

}

void TestSeqListPopFront()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPopFront(NULL);
	SeqListPopFront(&s);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);

	SeqListPopFront(&s);
	PrintSeqList(&s);
}

void TestSeqListInsert()
{
	SeqList s;
	SeqListInit(&s);
	SeqListInsert(NULL, 1, 1);//空顺序表
	SeqListInsert(&s, 5, 1);//位置超出范围

	SeqListInsert(&s, 1, 1);//头
	PrintSeqList(&s);

	SeqListInsert(&s, 2, 2);
	SeqListInsert(&s, 3, 3);//尾
	SeqListInsert(&s, 2, 5);//中间
	SeqListInsert(&s, 2, 4);
	SeqListInsert(&s, 2, 6);
	SeqListInsert(&s, 2, 7);
	SeqListInsert(&s, 2, 8);
	SeqListInsert(&s, 2, 9);
	SeqListInsert(&s, 2, 0);
	PrintSeqList(&s);

	SeqListInsert(&s, 1, 1);//满
}

void TestSeqListErase()
{
	SeqList s;
	SeqListInit(&s);
	SeqListErase(NULL, 1);
	SeqListErase(&s, 1);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);

	SeqListErase(&s, 3);
	SeqListErase(&s, 4);

	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);

	SeqListErase(&s, 2);
	PrintSeqList(&s);
}

void TestSeqListFind()
{
	SeqList s;
	SeqListInit(&s);
	SeqListFind(NULL, 1);
	SeqListFind(&s,1);

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("%d\n",SeqListFind(&s, 1));
	printf("%d\n", SeqListFind(&s, 2));

}

void TestSeqListRemove()
{
	SeqList s;
	SeqListInit(&s);
	SeqListRemove(NULL, 1);
	SeqListRemove(&s,  1);

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListRemove(&s, 1);
	//SeqListRemove(&s, 2);
	SeqListRemove(&s, 4);
	SeqListRemove(&s, 5);
}

void TestSeqListRemoveAll()
{
	SeqList s;
	SeqListInit(&s);
	SeqListRemoveAll(NULL, 3);
	SeqListRemoveAll(&s, 3);

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListRemoveAll(&s, 3);
}
void TestSeqListEmpty()
{
	SeqListEmpty(NULL);
}

void TestSeqListSize()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("%d\n", SeqListSize(&s));
}

void TestBubbleSort()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);

	BubbleSort(s._array, SeqListSize(&s));
	PrintSeqList(&s);

}
void TestSelectSort()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);

	SelectSort(s._array, SeqListSize(&s));
	PrintSeqList(&s);

}
void TestSelectSort_OP()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);

	SelectSort_OP(s._array, SeqListSize(&s));
	PrintSeqList(&s);

}
int main()
{
	//TestSeqListInit();
	//TestSeqListPushBack();
	//TestSeqListPushFront();
	//TestSeqListPopFront();
	//TestSeqListInsert();
	//TestSeqListErase();
	//TestSeqListFind();
	//TestSeqListRemove();
	//TestSeqListRemoveAll();
	//TestSeqListEmpty();
	//TestSeqListSize();
	//TestBubbleSort();
	//TestSelectSort();
	TestSelectSort_OP();
	return 0;
}
