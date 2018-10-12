#include<iostream>
using namespace std;
struct node
{
	int value;
	node *prev;
	node *next;
}*start;
void createNode_beg(int val)
{
	node *temp = new node;
	temp->value = val;
	if(start == NULL)
	{
		temp->prev = NULL;
		temp->next = NULL;
		start = temp;
	}
	else
	{
		temp->prev = NULL;
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
}
void createNode_end(int val)
{
	node *temp = new node;
	temp->value = val;
	temp->next = NULL;
	if(start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		node *last = new node;
		last = start;
		while(last->next != NULL)
		{
			last = last->next;
		}
		temp->prev = last;
		last->next = temp;
	}
}
void ins_beg(int val)
{
	node *temp = new node;
	temp->value = val;
	temp->prev = NULL;
	temp->next = start;
	start->prev = temp;
	start = temp;
}
void ins_end(int val)
{
	node *last = new node;
	last = start;
	while(last->next != NULL)
	{
		last = last->next;
	}
	node *temp = new node;
	temp->value = val;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}
void ins_after(int val,int given)
{
	node *ptr = new node;
	ptr = start;
	while(ptr->value != given)
	{
		ptr = ptr->next;
	}
	if(ptr->next == NULL)
	{
		ins_end(val);
	}
	else
	{
		node *temp = new node;
		temp->value = val;
		temp->prev = ptr;
		temp->next = ptr->next;
		ptr->next->prev = temp;
		ptr->next = temp;
	}
}
void ins_bef(int val,int given)
{
	node *ptr = new node;
	ptr = start;
	while(ptr->value != given)
	{
		ptr = ptr->next;
	}
	if(ptr->prev == NULL)
		ins_beg(val);
	else
	{
		node *temp = new node;
		temp->value = val;
		temp->next = ptr;
		temp->prev = ptr->prev;
		ptr->prev->next = temp;
		ptr->prev = temp;
	}
}
void ins_sort(int val)
{
	node *ptr = new node;
	ptr = start;
	while(ptr != NULL && ptr->value < val)
	{
		ptr = ptr->next;
	}
	if(ptr== NULL) 
		ins_end(val);
	else if(ptr->prev==NULL)
	{
		ins_beg(val);
	}
	else
	{
		node *temp = new node;
		temp->value = val;
		temp->prev = ptr->prev;
		temp->next = ptr;
		ptr->prev->next = temp;
		ptr->prev = temp;
	}
}
void del_beg()
{
	node *ptr = new node;
	ptr = start;
	if(ptr->next == NULL) //if there is only one element in the list
		start = NULL;
	else
	{
		start = ptr->next;
		ptr->next->prev = NULL;
		ptr->next = NULL;
	}
	delete ptr;
}
void del_end()
{
	node *ptr = new node;
	ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	node *str = new node;
	str = ptr;
	if(str->prev == NULL)
		start = NULL;
	else
	{
		str->prev->next = NULL;
		str = ptr->prev;
		ptr->prev = NULL;
	}
	delete ptr;
}
void del_ele(int val)
{
	node *ptr = new node;
	ptr = start;
	while(ptr->value != val)
		ptr = ptr->next;
	if(ptr->next == NULL)
		del_end();
	else if(ptr->prev == NULL)
		del_beg();
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ptr->prev = NULL;
		ptr->next = NULL;
		delete ptr;
	}
}
void display()
{
	node *temp = new node;
	temp = start;
	cout<<"The list is\n";
	while(temp != NULL)
	{
		cout<<temp->value<<"\t";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	int go,choice,give;
	cout<<"To enter list in FIFO manner (i.e. 1 , 2 , 3 , 4 , ....) , press 1 and to create list in LIFO ";
	cout<<"manner(i.e. ....., 4 , 3, 2 , 1) press 2 \n";
	cin>>choice;
	cout<<"Enter the values in the doubly linked list, to stop entering values, press -1\n";
	cin>>go;
	switch(choice)
	{
		case 1:
			while(go != -1)
			{
				createNode_end(go);
				cin>>go;
			}
			break;
		case 2:
			while(go != -1)
			{
				createNode_beg(go);
				cin>>go;
			}
			break;	
	}
	display();
	cout<<"To insert element at the beginning, press 1\n";
	cout<<"To insert element at the end, press 2\n";
	cout<<"To insert after an element, press 3\n";
	cout<<"To insert before an element, press 4\n";
	cout<<"To insert an element and get the result sorted after insertion, press 5\n";
	cout<<"To delete element at beginning, press 6\n";
	cout<<"To delete element at end, press 7\n";
	cout<<"To specify an element for deletion, press8\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter value of element that you want to insert at the beginning\n";
			cin>>go;
			ins_beg(go);
			break;
		case 2:
			cout<<"Enter value of element that you want to insert at the end\n";
			cin>>go;
			ins_end(go);
			break;
		case 3:
			cout<<"Enter value of element that you want to insert and value of element before which you want it inserted\n";
			cin>>go>>give;
			ins_after(go,give);
			break;
		case 4:
			cout<<"Enter value of element that you want to insert and value of element before which you want it inserted\n";
			cin>>go>>give;
			ins_bef(go,give);
			break;
		case 5:
			cout<<"Enter value of element you want to insert\n";
			cin>>go;
			ins_sort(go);
			break;
		case 6:
			del_beg();
			break;
		case 7:
			del_end();
			break;
		case 8:
			cout<<"Enter the element you want to delete\n";
			cin>>go;
			del_ele(go);
			break;
	}
	display();
	return 0;
}
