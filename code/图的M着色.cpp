#include <iostream>

using namespace std;

int cun=0;
int pointOfMap[20];
int linkPoint[20][20];
int numOfPoint=0;
int numOfEdge=0;
int numOfColor=0;
 
bool canPlace(int m,int color)
{
	for (int i=0;i<m;i++)
		if((linkPoint[m][i]==1)&&(pointOfMap[i]==color))
			return false;
	return true;
}

void MColoeOfMap(int m)
{
   if(m>=numOfPoint)
   {
	   cun++;
	   return ;
   }

   else
   {
	   for(int i=1;i<=numOfColor;i++)
		   if (canPlace(m,i))
	       {
	          pointOfMap[m]=i;
			  MColoeOfMap(m+1);
			  pointOfMap[m]=0;
	       }

   }

   return ;
}

int main()
{
	int tempRow=0;
	int tempCol=0;

	cin >> numOfPoint >> numOfEdge >> numOfColor;
	for(int m=0;m<numOfPoint;m++)
		for(int n=0;n<numOfPoint;n++)
			linkPoint[m][n]=0;

	for (int i=0; i<numOfEdge ;i++)
	{
		cin >> tempRow >> tempCol;
		linkPoint[tempRow][tempCol]=1;
		linkPoint[tempCol][tempRow]=1;
	}

	MColoeOfMap(0);
	cout << cun << endl;

	//cin >> cun;
	return 0;

}