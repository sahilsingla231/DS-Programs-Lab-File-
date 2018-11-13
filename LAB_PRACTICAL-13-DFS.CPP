#include<iostream>
using namespace std;
int top=-1,a[50];
void push(int x)
{
	++top;
	a[top]=x;
}
int pop()
{
	int temp;
	temp=a[top];
	top--;
	return temp;
}
int main()
{
	int n,m,i,j,k,k1,v,g[50][50],visit[50]={0},visited[50]={0};
	cout<<"Enter the number of vertices";
	cin>>n;
	cout<<"Enter number of edges";
	cin>>m;
	cout<<"Edges";
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		g[i][j]=1;
	}
	cout<<"Enter initial Vertex";
	cin>>v;
	cout<<"vertices: ";
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j=n;j>=1;j--)
		{
			if(g[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				push(j);	
			}
		}
		if(top==-1)
		{
			return 0;
		}
		v=pop();
		cout<<v<<" ";
		visit[v]=0;
		visited[v]=1;
	}
}