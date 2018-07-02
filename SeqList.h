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
