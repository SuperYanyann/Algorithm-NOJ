#include <iostream>
#include <math.h>
#include <vector>
bool turnUpTheCilcle = false;
using namespace std;
int countOfNum=0;
vector<int> arrayOfPrime(30); 

bool isPrime(int n)
{
	int k=n-1;
	for (int i=2;i<=k;i++)
		if (n%i == 0)
			return false;
	return true;
}


void initBegin()
{
	for (int i=0;i<21;i++)
		arrayOfPrime[i]=i;
}

void swapOfPrime(int& a,int& b)
{
	int t=a;
	a=b;
	b=t;
}

void searchOfPrime(int num)
{
	if(!turnUpTheCilcle)
	{
	if (num > 20)
	{
		if(isPrime(arrayOfPrime[1]+arrayOfPrime[20]))
			{
			countOfNum++;
			if(countOfNum == 2)
		      {
				  for (int i=1;i<20;i++)
				  cout << arrayOfPrime[i] << " ";
				  cout << arrayOfPrime[20];
				  cout << endl;
				  turnUpTheCilcle=true;
			  }
		}
		return;
	}
	else
	{
		for (int i=num;i<=20;i++)
		{
			swapOfPrime(arrayOfPrime[num],arrayOfPrime[i]);
			if (isPrime(arrayOfPrime[num-1]+arrayOfPrime[num]))
				searchOfPrime(num+1);
			swapOfPrime(arrayOfPrime[num],arrayOfPrime[i]);
		}
	}
	}

	return ;
}

int main()
{
	initBegin();
	searchOfPrime(2);

	cin >> arrayOfPrime[29];
	return 0;
}