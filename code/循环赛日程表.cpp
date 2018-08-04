#include <iostream>
#include <math.h>
using namespace std;


int powOftwo(int a, int b){
	if (b == 0) return 1;
	else{
		int n = 1, temp = a;
		while (n < b){
			temp = temp*a;
			n++;
		}
		return temp;
	}
}
int main()
{
	int texty[129][129]; //don't use the first row and the first cir
	int powOfPeople;
	cin >> powOfPeople;
	//int countOfProple = 6;
	//int countOfProple = (int)pow(2.0, (double)powOfPeople);
	int numOfPeo = powOftwo(2, powOfPeople);
	//creatTable(powOfPeople,RobinTable);
	for (int i = 1; i <= numOfPeo; i++)
		texty[1][i] = i;

	int m = 1;
	for (int s = 1; s <= powOfPeople; s++)
	{
		numOfPeo /= 2;
		for (int t = 1; t <= numOfPeo; t++)
		{
			for (int rowT = m + 1; rowT <= 2 * m; rowT++)
			{
				for (int cilT = m + 1; cilT <= 2 * m; cilT++)//  
				{
					texty[rowT][cilT + (t - 1)*m * 2] = texty[rowT - m][cilT + (t - 1)*m * 2 - m];//  
					cout << "(" << rowT << "," << cilT + (t - 1)*m * 2 << ")" << endl;
					texty[rowT][cilT + (t - 1)*m * 2 - m] = texty[rowT - m][cilT + (t - 1)*m * 2];// 
					cout << "(" << rowT << "," << cilT + (t - 1)*m * 2 - m << ")" << endl;
				}

			}
		}
		m *= 2;
	}

	numOfPeo = powOftwo(2, powOfPeople);
	for (int i = 1; i < numOfPeo; i++)
	{
		for (int j = 1; j <=numOfPeo; j++)
		{
			cout << texty[i][j] << " ";
		}
		cout << endl;
	}
	cin >> m;
	return 0;
}

