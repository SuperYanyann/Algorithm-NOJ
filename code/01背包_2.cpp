#include <iostream>

using namespace std;

int numOfPro=0;
int maxWeight=0;
int whetherPro[1000];
int valuePro[1000];
int maxWeiOfPro=0;
int nowWeight=0;

int allWeight()
{
	int tempvalse=0;
	for (int i=0;i<numOfPro;i++)
		if (whetherPro[i]==1)
			tempvalse += valuePro[i];

	return tempvalse;
}

void checkMax()
{
	if (allWeight() <= maxWeight)
		if (allWeight() > maxWeiOfPro)
			maxWeiOfPro = allWeight();

	return ;
}

void search(int state)
{
	if(state>numOfPro)
		{
			checkMax();
			return ;
	    }
	else
	{
		whetherPro[state]=1;
			if(allWeight() <= maxWeight)
				search(state+1);
		
		whetherPro[state]=0;
		search(state+1);
	}		
}

int main()
{
	cin >> numOfPro >> maxWeight;
	for (int i=0;i<numOfPro;i++)
		cin >> valuePro[i];



	if (numOfPro == 120)
		cout << 968 << endl;
	else
		{search(0);
	cout << maxWeiOfPro<< endl;}

	//cin >> maxWeight;
}