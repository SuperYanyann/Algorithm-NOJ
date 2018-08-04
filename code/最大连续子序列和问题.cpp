#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayNum(1000);
vector<int> sumArray(1000);
int lenOfNum=0;

int findMaxSum()
{
	int maxSum=1;
	sumArray[0]=0;
	for (int i=1 ; i<=lenOfNum ;i++)
	{
		if ((sumArray[i-1]+arrayNum[i]) > arrayNum[i])
			sumArray[i] = sumArray[i-1]+arrayNum[i];
		else
			sumArray[i]=arrayNum[i];
	}

	for (int j=2 ; j<=lenOfNum; j++)
		if (sumArray[j]>maxSum)
			maxSum = sumArray[j];

	return maxSum;
}

int main()
{
	cin >> lenOfNum;
	for (int i=1; i<=lenOfNum;i++)
		cin >> arrayNum[i];
	int maxSum=findMaxSum();
	cout << maxSum << endl;
	//cin >> maxSum;

	return 0;
}