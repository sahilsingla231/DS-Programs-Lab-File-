#include<iostream>
using namespace std;
int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;

void create();
void display();
void insert();
void del();

int main()
{
        int choice;
        do{

                cin>>choice;
                switch(choice)
                {
                        case 1:         create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert();
                                        break;

                        case 4:
                                        del();
                                        break;


                }
        }while(choice!=8);
return 0;
}
void create()
{
        cout<<("\nEnter the size of the array elements:\t");
        cin>>n;
        cout<<("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
               cin>>a[i];
        }
}
void display()
{
        int i;
        cout<<("\nThe array elements are:\n");
        for(i=0;i<n;i++){
                 cout<<("%d\t",a[i]);
         }
 }
void insert()
{
    cout<<("\nEnter the position for the new element:\t");
    cin>>pos;
    cout<<("\nEnter the element to be inserted :\t");
    cin>>val;
    for(i=n-1;i>=pos;i--)
        {
                a[i+1]=a[i];
        }
        a[pos]=val;
        n=n+1;
}


void del()
{
        cout<<("\nEnter the position of the element to be deleted:\t");
        cin>>pos;
        val=a[pos];
        for(i=pos;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        n=n-1;
        cout<<("\nThe deleted element is =%d",val);
}

