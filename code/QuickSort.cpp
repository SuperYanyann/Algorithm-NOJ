/*
//quicksort
1.备份轴记录
2.取两个指针low和high，初始值就是序列的两端下标，保证low<=high
3.移动两个指针
  从high向左找到第一个小于轴的元素, 放在low的位置
  从low向右找到第一个大于轴的元素，放在high的位置
4.重复，直到low=high，
5.把轴放在low所指的位置
6.分别对low所指的位置的左边和右边进行上述的递归
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