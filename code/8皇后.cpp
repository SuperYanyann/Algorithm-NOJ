#include <iostream>

using namespace std;

int N=8;
int queenList[10];
int flag=0;
void output(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			if(j==queenList[i]) cout<<"A";
			else cout<<".";
		cout<<endl;
	}
	//cout<<endl;
}

void Search(int r){
	if(r==N){
		cout <<"No "<< ++flag<<":" << endl;
		if (flag!=92)
		{output();
		//cout << endl;
		}
		else
		 output();
		return;
	}
	for(int i=0;i<N;i++){
		queenList[r]=i;
		int ok=1;

		for(int j=0;j<r;j++){
			if(queenList[r]==queenList[j] || r+queenList[r]==j+queenList[j] ||
				r-queenList[r]==j-queenList[j]){
					ok=0;
					break;
			}
		}
		if(ok) Search(r+1);
	}
}
int main()
{
	Search(0);
	//int a;
	//cin >> a;
	return 0;
}