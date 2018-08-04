#include <iostream>
#include <vector>
using namespace std;
vector<int> selectOfPro(20);
vector<int> weightOfPro(20);
vector<int> valueOfPro(20);
vector<int> outPut(20);
int nowWeight=0;
int nowValux=0;
int maxValse=0;
int numOfProject=0;
int capaOfPac=0;
void checkmax(int capaOfpack,int numOfPro)
{
   nowWeight=0;
   nowValux=0;
   for (int i=0;i<numOfPro;i++)
   {
	   if (selectOfPro[i] == 1)
	   {
		   nowWeight=nowWeight+weightOfPro[i];
		   nowValux=nowValux+valueOfPro[i];
	   }
   }

   if (nowWeight <= capaOfpack)
	   if (nowValux > maxValse)
		   maxValse = nowValux;
}

void searchForPack(int nowNum,int numOfPro,int capaOfPack)
{
   if(nowNum>numOfPro)
	   checkmax(capaOfPack,numOfPro);
   else
   {
	   selectOfPro[nowNum]=0;
	   searchForPack(nowNum+1,numOfPro,capaOfPack);
	   selectOfPro[nowNum]=1;
	   searchForPack(nowNum+1,numOfPro,capaOfPack);
   }
}





int main()
{
	int numOfExercise=0;
	while (1)
	{
		cin >> numOfProject;
		cin >> capaOfPac;
		if (numOfProject == 0 && capaOfPac ==0)
			break;
		if (numOfProject == 0 && capaOfPac !=0)
			maxValse=0;
		else{
		for (int i=0;i < numOfProject;i++)
			cin >> weightOfPro[i];
		for (int j=0;j< numOfProject;j++)
			cin >> valueOfPro[j];
		searchForPack(0,numOfProject,capaOfPac);
		outPut[numOfExercise]=maxValse;
		}
		numOfExercise++;
	}

	for (int i=0;i<numOfExercise;i++)
		cout << outPut[i] << endl;

	return 0;
}	