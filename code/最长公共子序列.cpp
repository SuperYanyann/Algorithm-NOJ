#include <iostream>
#include <vector>
#include <string>

using namespace std;

string array1;
string array2;
int relaMatrix[200][200];

int lcsLength()
{
	int lenOfA1=array1.length();
	int lenOfA2=array2.length();
	for (int i=0;i<=lenOfA2;i++)
		relaMatrix[0][i]=0;
	for (int i=0;i<=lenOfA1;i++)
		relaMatrix[i][0]=0;

	for (int i=1;i<=lenOfA1;i++)
		for (int j=1;j<=lenOfA2;j++)
		{
			if (array1[i-1] == array2[j-1])
				relaMatrix[i][j]=relaMatrix[i-1][j-1]+1;
			else
			{
				if (relaMatrix[i-1][j] >= relaMatrix[i][j-1])
					relaMatrix[i][j]=relaMatrix[i-1][j];
				else
					relaMatrix[i][j]=relaMatrix[i][j-1];
			}
		}

		return relaMatrix[lenOfA1][lenOfA2];
}

int main()
{
	cin >> array1;
	cin >> array2;
	int maxLength=lcsLength();
	cout << maxLength <<endl;
	cin >> maxLength;

	return 0;
}

