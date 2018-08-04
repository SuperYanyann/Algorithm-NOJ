#include <iostream>
#include <queue>
#include <map>

using namespace std;

queue<int> queOfAQS;
map<int,int> fatherNode;
int countOfQue[10000];
int cun=1;
int beg=0,en=0;

int compute(int m,int i)
{
	if(i==1)
		return m+1;
	if(i==2)
		return m*2;
	if(i==3)
		return m*m;
	else
		return 0;
}

bool isNew(int m)
{
	if ((countOfQue[m] == -1) && (m<=en) )
		return true;
	else
		return false;
}

bool AddMulSqu(int m,int aim)
{
	queOfAQS.push(m);
	countOfQue[m]=0;
	int frontOfQue=0;
	int temp=0;

	while(!queOfAQS.empty())
	{
		frontOfQue=queOfAQS.front();
		queOfAQS.pop();
		for (int i=1;i<=3;i++)
		{
			temp=compute(frontOfQue,i);
			if(temp <= en)
			{if(temp == aim)
			  {
				 countOfQue[temp]=frontOfQue;
				 return true;
			  }
			if(isNew(temp))
			  {
				countOfQue[temp]=frontOfQue;
				queOfAQS.push(temp);
			  }
			}
		}
		
	}

	return false;
}

int main()
{
   cin >> beg >> en;
   for (int i=0;i<en;i++)
	   countOfQue[i]=-1;
   if (AddMulSqu(beg,en))
	   while(countOfQue[en]!=beg)
	   {
		   cun++;
		   en=countOfQue[en];
	   }
  cout << cun <<endl;
  return 0;
}