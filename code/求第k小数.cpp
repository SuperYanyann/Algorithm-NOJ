#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int numOfArray=0;
	int selectLine=0;
	cin >> numOfArray;
	vector<int> arrayOfSort(numOfArray);
	for(int i=0;i<numOfArray;i++)
		cin >> arrayOfSort[i];
	cin >> selectLine;
   sort(arrayOfSort.begin(),arrayOfSort.end());
   cout << arrayOfSort[selectLine-1]<<endl;
}
