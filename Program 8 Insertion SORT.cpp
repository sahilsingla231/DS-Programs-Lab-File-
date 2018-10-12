#include<iostream>
using namespace std;

int main()
{
	int i,j,temp,n;
	
	cout<<"Enter number of elements to sort  ";
	cin>>n;
	int  a[n];
	cout<<"Enter elements  ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	//	select(a,n);
	
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	
	
	cout<<"Sorted elements  ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
}

