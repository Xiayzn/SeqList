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

