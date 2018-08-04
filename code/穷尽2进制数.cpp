#include <iostream>
using namespace std;
int outputOfArray[15000000];
void exhaustive(int num,int limitNum)
{
	if(num>limitNum)
	{
		for(int i=1;i<=limitNum;i++)
			cout << outputOfArray[i] ;
		cout << endl;
	}

	else
	{
		outputOfArray[num]=0;
		exhaustive(num+1,limitNum);
		outputOfArray[num]=1;
		exhaustive(num+1,limitNum);
	}
}

int main()
{
   int countOfNum=0;
   cin >> countOfNum;
   exhaustive(1,countOfNum);

   return 0;
   
}
