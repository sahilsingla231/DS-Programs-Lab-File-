#include<iostream>
using namespace std;

#define MAX 5

int top=-1,stack[MAX];
void push();
void pop();
void display();

int main()
{
    int ch;

    while(1)
    {
        cout<<"\n*** Stack Menu ***";
        cout<<"\n\n1.Push\n2.Pop\n3.Display";
        cout<<"\n\nEnter your choice(1-3):";
        cin>>ch;

        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;

            default: cout<<"\nWrong Choice!!";
        }
    }
}

void push()
{
    int val;

    if(top==MAX-1)
    {
        cout<<"\nStack is full!!";
    }
    else
    {
        cout<<"\nEnter element to push:";
        cin>>val;
        top=top+1;
        stack[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
    cout<<"\nStack is empty!!";
    }
    else
    {
        cout<<"\nDeleted element is %d",stack[top];
        top=top-1;
    }
}

void display()
{
    int i;

    if(top==-1)
    {
       cout<<"\nStack is empty!!";
    }
    else
    {
        cout<<"\nStack is...\n";
        for(i=top;i>=0;--i)
            cout<<"%d\n",stack[i];
    }
}
