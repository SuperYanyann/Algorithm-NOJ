#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace::std;
typedef struct Node{
	int x;
	int y;
	int num;
}Node;

string str;
bool state[210][210];
int dir[8][2]={{2,1},{1,2}, {2,-1},{1,-2},{-2,-1},{-1,-2}, {-2,1},{-1,2}};
int begin_X,begin_Y,end_X,end_Y;
queue<Node> q;
bool islegal(int x,int y){
	if(x>=1 && x<=200 && y>=1 && y<=200) return true;
	return false;
}
int search(){
	Node temp1,temp2;
	temp1.x=begin_X;
	temp1.y=begin_Y;
	temp1.num=0;
	q.push(temp1);
	state[begin_X][begin_Y]=true;
	while(!q.empty()){
		temp1=q.front();
		q.pop();
		if(temp1.x==end_X && temp1.y==end_Y) return temp1.num;
		for(int i=0;i<8;i++){
			int a=temp1.x+dir[i][0];
			int b=temp1.y+dir[i][1];
			if(islegal(a,b)&&state[a][b]==false){
				temp2.x=a;
				temp2.y=b;
				temp2.num=temp1.num+1;
				q.push(temp2);
				state[a][b]=true;
			}
		}
	}
	return -1;
}


int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>begin_X>>begin_Y>>end_X>>end_Y;
		while(!q.empty()) q.pop();
		memset(state,0,sizeof(state));
		cout<<search()<<endl;
	}
	return 0;
}