//#include <iostream>
//#include <queue>
//#include<string>
//
//using namespace std;
//string str[12];
//char mapOfMaze[150];
//int fatherPoint[150];
//queue<int> queOfStep;
//int cun=1;
//int beginPoint=0;
//int endPoint=0;
//
//int movePoint(int point,int dir)
//{
//	int row = point/12;
//	int col = point%12;
//    if(dir == 0)
//		row-=1;
//	else if(dir == 1)
//		row+=1;
//	else if(dir == 2)
//		col-=1;
//	else if(dir == 3)
//		col+=1;
//
//	return 12*row+col;
//}
//
//bool isNew(int point)
//{
//    int row=point/12;
//	int col=point%12;
//	if(row<0 || row>11 || col<0 || col>11)
//		return false;
//	if(mapOfMaze[point] != 'X')
//		return false;
//	if(fatherPoint[point] != 0)
//		return false;
//	return true;
//}
//
//bool mouseRun()
//{
//	queOfStep.push(beginPoint);
//    int frontPoint=0;
//	int tempPoint=0;
//
//	while(!queOfStep.empty())
//	{
//		frontPoint=queOfStep.front();
//		queOfStep.pop();
//
//		for(int i=0;i<4;i++)
//		{
//			tempPoint=movePoint(frontPoint,i);
//			if(isNew(tempPoint))
//			{
//				//cout << tempPoint/12+1 << " , " <<tempPoint%12 <<endl;
//				queOfStep.push(tempPoint);
//				fatherPoint[tempPoint]=frontPoint;
//				if (tempPoint == endPoint)
//					{return true;
//				     //cout << "*******" <<endl;
//				     break;
//				    }
//			}
//		}
//	}
//
//	return false;
//}
//
//int main()
//{
//	int beginPoint_X=0,beginPoint_Y=0;
//	int endPoint_X=0,endPoint_Y=0;
//	char judegPoint;
//	int pointTemp=0;
//	cin >> beginPoint_X >> beginPoint_Y >> endPoint_X >>endPoint_Y;
//	//int wallPoint[53]={14,15,16,17,18,19,21,
//	//                   26,28,31,32,33,34,35,
//	//                   38,40,43,47,
//	//				   50,52,53,54,55,56,58,59,
//	//                   62,
//	//                   74,75,76,78,80,81,82,83,
//	//                   86,90,91,92,
//	//                   98,99,100,101,102,104,105,106,107,
//	//                   112,117,119,
//	//				   128,129} ;
//	//for (int i=0;i<53;i++)
//	//	mapOfMaze[wallPoint[i]]=1;
//	beginPoint=(beginPoint_X-1)*12+beginPoint_Y;
//	endPoint=(endPoint_X-1)*12+endPoint_Y;
//	for(int i=0;i<12;i++) 
//		  cin >> str[i];
//	for(int i=1;i<=12;i++)
//		for(int j=1;j<=12;j++)
//				mapOfMaze[(i-1)*12+j]=str[i-1][j-1];
// /*   for(int i=0;1<12;i++)
//		for(int j=1;j<13;j++)
//		{
//			pointTemp=i*12+j;
//			cin >> judegPoint;
//			if(judegPoint=='X')
//				mapOfMaze[pointTemp]=0;
//			else
//				mapOfMaze[pointTemp]=1;
//		}*/
//	
//	
//	if(mouseRun())
//		while (fatherPoint[endPoint]!=beginPoint)
//		{
//			//cout << endPoint/12+1 <<" , " << endPoint%12 << endl;
//			endPoint=fatherPoint[endPoint];
//			cun++;
//		}
//
//	//cout <<"//////////////"<< endl;
//	cout << cun << endl;
//	//cin >> cun ;
//
//	return 0;
//
//}

#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
typedef struct Node{
	int x;
	int y;
	int num;
}Node;

string str[12];
char mapOfMaze[13][13];
bool usedPoint[13][13];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int sx,sy,tx,ty;
queue<Node> q;
bool islegal(int x,int y){
	if(mapOfMaze[x][y]=='.' && x>=1 && x<=12 && y>=1 && y<=12) return true;
	return false;
}
int bfs(){
	Node temp1,temp2;
	temp1.x=sx;
	temp1.y=sy;
	temp1.num=0;
	q.push(temp1);
	usedPoint[sx][sy]=true;
	while(!q.empty()){
		temp1=q.front();
		q.pop();
		if(temp1.x==tx && temp1.y==ty) return temp1.num;
		for(int i=0;i<4;i++){
			int a=temp1.x+dir[i][0];
			int b=temp1.y+dir[i][1];
			if(islegal(a,b)&&usedPoint[a][b]==false){
				temp2.x=a;
				temp2.y=b;
				temp2.num=temp1.num+1;
				q.push(temp2);
				usedPoint[a][b]=true;
			}
		}
	}
	return -1;
}
int main(){
	cin>>sx>>sy>>tx>>ty;
	for(int i=0;i<12;i++) cin>>str[i];
	for(int i=1;i<=12;i++)
		for(int j=1;j<=12;j++)
			mapOfMaze[i][j]=str[i-1][j-1];
	cout<<bfs()<<endl;
	return 0;
}
