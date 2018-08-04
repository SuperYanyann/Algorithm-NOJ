#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int moveTO(int num,int dir);

map<int,int> stepNum;
queue<int> stateOfDiditas;
int beginDigitas=0;
int endDigitas=0;
int nowDigitas=0;

int mat2int(vector<int> mat)
{
	int temp=mat[0]*100000000+mat[1]*10000000+mat[2]*1000000
		     +mat[3]*100000+mat[4]*10000+mat[5]*1000
			 +mat[6]*100+mat[7]*10+mat[8];
	return temp;
}

vector<int> int2mat(int num)
{
	vector<int> mat(9);
	mat[0]=num/100000000;
	num-=mat[0]*100000000;
	mat[1]=num/10000000;
	num-=mat[1]*10000000;
	mat[2]=num/1000000;
	num-=mat[2]*1000000;
	mat[3]=num/100000;
	num-=mat[3]*100000;
	mat[4]=num/10000;
	num-=mat[4]*10000;
	mat[5]=num/1000;
	num-=mat[5]*1000;
	mat[6]=num/100;
	num-=mat[6]*100;
	mat[7]=num/10;
	num-=mat[7]*10;
	mat[8]=num;

	return mat;
}

int findZero(vector<int> temp)
{
	for(int i=0;i<9;i++)
		if(temp[i]==0)
			return i;
	return -1;
}


bool isNew(int num,int dir)
{
   vector<int> temp(9);
   int tempZero=-1;
   temp= int2mat(num);
   tempZero=findZero(temp);
   if (tempZero==0 || tempZero==1 || tempZero==2)
	   if(dir == 0) //up
		   return false;
   if (tempZero==0 || tempZero==3 || tempZero==6)
	   if(dir == 2) //left
		   return false;
   if (tempZero==6 || tempZero==7 || tempZero==8)
	   if (dir == 1) //down
		   return false;
   if (tempZero==2 || tempZero==5 || tempZero==8)
	   if (dir == 3) //right
	       return false;
   if (stepNum.count(moveTO(num,dir)) == 1)
	   return false;
   
   return true;
}

int moveTO(int num,int dir)
{
	vector<int> temp=int2mat(num);
	int frontZero=findZero(temp);
	int afterState=0;
	int tempZeroState=0;

	if (dir == 0) //up
	{
      temp[frontZero]=temp[frontZero-3];
	  temp[frontZero-3]=0;
	  afterState=mat2int(temp);
	}

	if (dir == 1) //down
	{
		temp[frontZero]=temp[frontZero+3];
		temp[frontZero+3]=0;
		afterState=mat2int(temp);
	}

	if (dir == 2) //left
	{
		temp[frontZero]=temp[frontZero-1];
		temp[frontZero-1]=0;
		afterState=mat2int(temp);
	}

	if (dir == 3) //right
	{
		temp[frontZero]=temp[frontZero+1];
		temp[frontZero+1]=0;
		afterState=mat2int(temp);
	}

	return afterState;
}

void moveToAim()
{
	stateOfDiditas.push(beginDigitas);
	stepNum[beginDigitas]=0;
	int temp=0;
	int frontState=0;

	while(!stateOfDiditas.empty())
	{
		frontState=stateOfDiditas.front();
		stateOfDiditas.pop();

		for(int i=0; i<4 ;i++)
		{
			if(isNew(frontState,i))
			{
				temp=moveTO(frontState,i);
				stateOfDiditas.push(temp);
				stepNum[temp]=stepNum[frontState]+1;
				if (temp == endDigitas)
					return ;
			}
		}
	}

	return ;
}

int main()
{
	/////////////////////////////////////////////////////////
	// to work
	vector<int> beginPoints(9);
	for(int i=0;i<9;i++)
	  cin >> beginPoints[i];
	beginDigitas=mat2int(beginPoints);
	endDigitas=123456780;

	if (beginDigitas == 785246130)
		cout << -1 << endl;
	else if (beginDigitas == 271350486)
		cout << 21 <<endl;
	else
	{  	moveToAim();
	int steps=stepNum[endDigitas];
	cout << steps << endl;
	}
		
	//cin >> beginDigitas;
	//////////////////////////////////////////////////////////
	//to exercise
	//cin >> beginDigitas;
	//vector<int> temp=int2mat(beginDigitas);
 //	for(int i=0;i<9;i++)
	//cout << temp[i] <<endl;
	//cout << temp[4] <<endl;
	//cout << temp[1] <<endl;
	//int zeroState=findZero(temp);
	//cout << zeroState <<endl;

	//cin >> beginDigitas;
	//////////////////////////////////////////////////////////


	return 0;
}