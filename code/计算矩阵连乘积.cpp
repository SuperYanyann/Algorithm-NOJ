//#include <iostream>
//
//using namespace std;
//
//int lenOfMat[11][2];
//int recordOfMat[11][11];
//int numOfMAt=0;
//
//int countMulOfMat()
//{
//	for (int i=0;i<numOfMAt;i++)
//		recordOfMat[i][i]=0;
//	for (int t=2;t<=numOfMAt;t++)
//	{
//		int j=0;
//		for (int i=1;i<=numOfMAt-t+1;i++)
//		{
//			j=i+t-1;
//			recordOfMat[i][j]=1000000;
//			for(int k=i;k<=j-1;k++)
//			{
//				int temp=recordOfMat[i][k]+recordOfMat[k+1][j]
//				         +lenOfMat[i][1]*lenOfMat[k][1]*lenOfMat[j][2];
//                if (temp < recordOfMat[i][j])
//				{
//					recordOfMat[i][j] = temp;
//					cout << i << " , " << j << "red=" << temp << endl;
//				}
//			}
//		}
//	}
//
//	return recordOfMat[1][numOfMAt];
//}
//
//int main()
//{
//	cin >> numOfMAt;
//	for (int i=1;i<=numOfMAt;i++)
//		cin >> lenOfMat[i][1] >> lenOfMat[i][2];
//	int maxLen=countMulOfMat();
//	cout << maxLen << endl;
//	cin >> maxLen;
//	return 0;
//}

#include <iostream>
#include <cstdio>
using namespace std;
int colsOfMAt[20];
int lenOfMat[20][2];
int recordOfMat[20][20];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lenOfMat[i][0]>>lenOfMat[i][1];
	}
	colsOfMAt[0]=lenOfMat[1][0];
	for(int i=1;i<=n;i++)
		colsOfMAt[i]=lenOfMat[i][1];

	for(int i=1;i<=n;i++) recordOfMat[i][i]=0;
	for(int r=2;r<=n;r++){
		for(int i=1;i+r-1<=n;i++){
			int j=i+r-1;

			recordOfMat[i][j]=recordOfMat[i][i]+recordOfMat[i+1][j]+colsOfMAt[i-1]*colsOfMAt[i]*colsOfMAt[j];

			for(int k=i+1;k<j;k++){
				int temp= recordOfMat[i][k] + recordOfMat[k+1][j] + colsOfMAt[i-1]*colsOfMAt[k]*colsOfMAt[j];
				if(temp<recordOfMat[i][j]) recordOfMat[i][j]=temp;
			}
		}
	}
	cout<<recordOfMat[1][n]<<endl;

	return 0;
}
