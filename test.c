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
