#include <iostream>
#include <vector>

using namespace std;

vector<int> heiOfMiss(100);
vector<int> accuOfMiss(100);
int numOfMiss=1;

int searchMost(int num)
{
	int maxLen=0;
	for (int i=0;i<num;i++)
		accuOfMiss[i]=1;

	for (int i=1;i<num;i++)
	{
		for (int j=0;j<i;j++)
			if (heiOfMiss[i] <= heiOfMiss[j])
			{
				if (accuOfMiss[i] < accuOfMiss[j]+1)
					accuOfMiss[i] = accuOfMiss[j]+1;
			}

		if(accuOfMiss[i]>maxLen)
			maxLen = accuOfMiss[i];
	}

	return maxLen;
}

int main()
{
	while(numOfMiss!=0)
	{
	
		cin >> numOfMiss;
		if (numOfMiss==0)
			break;
		for (int i=0;i<numOfMiss;i++)
			cin >> heiOfMiss[i];
		int maxLength=searchMost(numOfMiss);
		cout << maxLength <<endl;
	}

	//int a=0;
	//cin >> a;


	return 0;
}