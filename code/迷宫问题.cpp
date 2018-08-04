//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int mazeOfMAp[100][100];
//int visitMaze[100][100]; //the point has been visited
//int numOfMa[2]={0,0};     //  scale of maze
//int parOfMA[4] = {0,0,0,0}; //the begin point and the end point of maze;
//bool canOrnot=false; //to judge whether it can get the end point
//int rowtemp,coltemp;
//int oldrow,oldcol;
//
//
//bool canPlace(int row,int col)
//{
//	if (row>=0 && row<numOfMa[0] && col>=0 && col<numOfMa[1]
//		&& mazeOfMAp[row][col] == 0)
//		return true;
//	else
//		return false;
//}
//
//void searchToEnd(int row,int col)
//{
//	visitMaze[row][col] = 1;
//	//cout << row << " , " << col <<endl;
//	if(!canOrnot)
//	{
//		if(row==parOfMA[2] && row == parOfMA[3])
//			{canOrnot = true;
//		     return ;}
//	    
//		rowtemp=0;
//		coltemp=0;
//		rowtemp=row;   //to left
//		coltemp=col-1;
//		if(visitMaze[rowtemp][coltemp]==0)
//		if (canPlace(rowtemp,coltemp))
//		{
//			//cout << "left" << endl;
//			searchToEnd(rowtemp,coltemp);
//		}
//		rowtemp=row+1;   //to down
//		coltemp=col;
//		if(visitMaze[rowtemp][coltemp]==0)
//		if (canPlace(rowtemp,coltemp))
//		{
//			//cout << "down" << endl;
//			searchToEnd(rowtemp,coltemp);
//		}
//
//		rowtemp=row;   //to right
//		coltemp=col+1;
//		if(visitMaze[rowtemp][coltemp]==0)
//		if (canPlace(rowtemp,coltemp))
//		{
//			//cout << "right" << endl;
//			searchToEnd(rowtemp,coltemp);
//		}
//
//		rowtemp=row-1;   //to up
//		coltemp=col;
//		if(visitMaze[rowtemp][coltemp]==0)
//		if (canPlace(rowtemp,coltemp))
//		{
//			//cout << "up" << endl;
//			searchToEnd(rowtemp,coltemp);
//		}
//	}
//	
//}
//
//int main()
//{
//    cin >> numOfMa[0] >> numOfMa[1] ;
//	cin >> parOfMA[0] >> parOfMA[1] ;
//	cin >> parOfMA[2] >> parOfMA[3] ;
//	for (int i=0 ; i<numOfMa[0] ; i++)
//		for ( int j=0 ; j<numOfMa[1] ; j++)
//			cin >> mazeOfMAp[i][j];
//
//	for (int k=0;k<100; k++)
//		for (int g=0;g<100; g++)
//			visitMaze[k][g]=0;
//
//	searchToEnd(numOfMa[0],numOfMa[1]);
//	if (canOrnot == true)
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//
//	int a=0;
//	cin >> a;
//	return 0;
//
//}





#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int mazeMap[100][100];
int visitMaze[100][100];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int m,n,b_x,b_y,e_x,e_y;
int flag;
void searchMaze(int x,int y){
	visitMaze[x][y]=1;
	if(x==e_x&&y==e_y){
		flag=1;
		return;
	}
	for(int i=0;i<4;i++){
		int temp_x=x+dir[i][0];
		int temp_y=y+dir[i][1];
		if(visitMaze[temp_x][temp_y]) continue;
		if(temp_x<0||temp_x>=m||temp_y<0||temp_y>=n||mazeMap[temp_x][temp_y]==1) continue;
		searchMaze(temp_x,temp_y);
	}
}
int main(){
	cin>>m>>n;
	cin>>b_x>>b_y;
	cin>>e_x>>e_y;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>mazeMap[i][j];
	searchMaze(b_x,b_y);
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

