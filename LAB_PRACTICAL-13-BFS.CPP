#include<iostream>
#define size 50
using namespace std;
int q[size],front=-1,rear=-1;
void insert(int num)
{
	if(rear==49)
	{
		cout<<"overflow";
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
		q[rear]=num;
	}
	else
	{
		rear=rear+1;
		q[rear]=num;
	}
}
int deletion()
{
	
	int temp=q[front];
    if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=front+1;
	}
	return temp;
}
int main()
{
	int n,m,k,g[50][50],i,j,v,q[10],visited[50],visit[50];
	cout<<"Enter number of vertices";
	cin>>n;
	cout<<"Enter number of edges";
	cin>>m;
	for(i=1;i<=50;i++)
	{
		visited[i]=0;
		visit[i]=0;
	}
	cout<<"Edges"<<" ";
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		g[i][j]=1;
	}
	cout<<"Enter initial vertex";
	cin>>v;
	cout<<"Visited vertices:";
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j=1;j<=n;j++)
		{
			if(g[v][j]==1 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				insert(j);
			}
		}
		v=deletion();
		cout<<v<<" ";
		k++;
		visit[v]=0;
		visited[v]=1;
	}

}