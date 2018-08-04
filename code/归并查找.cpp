#include <iostream>

using namespace std;

int arrayOfsort[10000];
int lengthOfArray = 0;

void merge_exchange(int* dataArray, int* textArray, int beginOfSort, int endOfSort,int midOfSort)
{
	int pointer1 = beginOfSort;
	int pointer2 = midOfSort + 1;
	int i = 0;


	while (pointer1 <= midOfSort && pointer2 <= endOfSort)
	{
		if (dataArray[pointer1] <= dataArray[pointer2])
		{
			textArray[i] = dataArray[pointer1];
			i++;
			pointer1++;

		}
		else
		{
			textArray[i] = dataArray[pointer2];
			i++;
			pointer2++;

		}
     }
	while (pointer1 <= midOfSort)
	{
		textArray[i] = dataArray[pointer1];
		i++;
		pointer1++;
	}
	while (pointer2 <= endOfSort)
	{
		textArray[i] = dataArray[pointer2];
		i++;
		pointer2++;
	}

	for (int j = 0; j < i; j++)
		dataArray[beginOfSort + j] = textArray[j];

}

void merge_sort(int* textArray,int* tempArray,int beginArray,int endArray)
{
	if (beginArray < endArray)
	{
		int midArray = (beginArray + endArray) / 2;
		merge_sort(textArray, tempArray,beginArray, midArray);
		merge_sort(textArray, tempArray, midArray+1, endArray);
		merge_exchange(textArray,tempArray, beginArray, endArray,midArray);

	}
}



int main()
{
	cin >> lengthOfArray;
	for (int i = 0; i < lengthOfArray; i++)
		cin >> arrayOfsort[i];

	int tempArray[10000];
	merge_sort(arrayOfsort,tempArray,0,lengthOfArray-1);
	for (int i = 0; i < lengthOfArray; i++)
		cout << arrayOfsort[i] << endl;

	return 0;
}
```