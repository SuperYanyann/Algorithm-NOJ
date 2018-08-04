
//#include "stdafx.h"
#include <iostream>
//#include <vector>

using namespace std;

//vector<int> arrayOfSearch(10000);
//vector<int> arrayOfOutput(10000);
int arrayOfSearch[10000];
int arrayOfOutput[10000];

bool BinarySearch(int beginOfSearch, int endOfSearch, int temp)
{
	if (temp == arrayOfSearch[beginOfSearch] || temp == arrayOfSearch[endOfSearch])
		return true;
	if (beginOfSearch > endOfSearch)
		return false;
	int middleOfssearch = (beginOfSearch + endOfSearch) / 2;
	if (temp == arrayOfSearch[middleOfssearch])
		return true;
	else if (temp > arrayOfSearch[middleOfssearch])
		BinarySearch(middleOfssearch + 1, endOfSearch, temp);
	else if (temp < arrayOfSearch[middleOfssearch])
		BinarySearch(beginOfSearch, middleOfssearch - 1, temp);

}
void main()
{
	int lengthOfArray;
	int lengthOfSearch;
	cin >> lengthOfArray;
	for (int i = 0; i < lengthOfArray; i++)
		cin >> arrayOfSearch[i];
	cin >> lengthOfSearch;
	for (int j = 0; j < lengthOfSearch; j++)
	{
		int temp2;
		cin >> temp2;
		if (BinarySearch(1, lengthOfArray, temp2))
			arrayOfOutput[j] = 1;
		else
		    arrayOfOutput[j] = 0;
	}

	for (int k = 0; k < lengthOfSearch; k++)
	{
		if (arrayOfOutput[k] == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return;
}