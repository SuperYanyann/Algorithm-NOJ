/*
//quicksort
1.�������¼
2.ȡ����ָ��low��high����ʼֵ�������е������±꣬��֤low<=high
3.�ƶ�����ָ��
  ��high�����ҵ���һ��С�����Ԫ��, ����low��λ��
  ��low�����ҵ���һ���������Ԫ�أ�����high��λ��
4.�ظ���ֱ��low=high��
5.�������low��ָ��λ��
6.�ֱ��low��ָ��λ�õ���ߺ��ұ߽��������ĵݹ�
*/
#include <iostream>
using namespace std;

int arrayOfSort[10000];
int lengthOfArray;

void quickSort(int* dataArrat, int leftOfArray, int rightOfArray)
{
	if (leftOfArray < rightOfArray)
	{
		int beginOfSort = leftOfArray;
		int endOfSort = rightOfArray;
		int temp = dataArrat[leftOfArray];

		while (beginOfSort < endOfSort)
		{
			while (beginOfSort < endOfSort && dataArrat[endOfSort] >= temp)
				endOfSort--;
			if (beginOfSort < endOfSort)
			{
				dataArrat[beginOfSort] = dataArrat[endOfSort];
				beginOfSort++;
			}

			while (beginOfSort < endOfSort && dataArrat[beginOfSort] < temp)
				beginOfSort++;
			if (beginOfSort < endOfSort)
			{
				dataArrat[endOfSort] = dataArrat[beginOfSort];
				endOfSort--;
			}
		}


		dataArrat[beginOfSort] = temp;
		quickSort(dataArrat, leftOfArray, beginOfSort - 1);
		quickSort(dataArrat, beginOfSort + 1, rightOfArray);
	}
}

	int main()
	{
		cin >> lengthOfArray;
		for (int i = 0; i < lengthOfArray; i++)
			cin >> arrayOfSort[i];
		quickSort(arrayOfSort, 0, lengthOfArray-1);
		for (int j = 0; j < lengthOfArray; j++)
			cout << arrayOfSort[j] << endl;

		return 0;
	}