 #include<iostream>
using namespace std;
class list
{
	struct node
	{
		int data;
		node *next;
	};
	node *head , *tail , *temp;
	public:
		list()
		{
			head = NULL;
			tail = NULL;
		}
		void create_insEnd(int val)
		{
			temp = new node;
			temp->data = val;
			temp->next = head;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp->next = head;
			}
			else
			{
				temp->next = head;
				tail->next = temp;
				tail = temp;
				temp = NULL;
			}
		}
		void create_insBeg(int val)
		{
			temp = new node;
			temp->data = val;
			temp->next = head;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else
			{
				head = temp;
				tail->next = temp;
			}
		}
		void display()
		{
			temp = new node;
			temp = head;
			cout<<"The list is:\n";
			do
			{
				cout<<temp->data<<"\t";
				temp = temp->next;
			}while(temp != head);
			//cout<<head->data;
			cout<<endl;
		}
		void ins_beg(int v)
		{
			temp = new node;
			temp->data = v;
			temp->next = head;
			head = temp;
			tail->next = temp;
		}
		void ins_end(int v)
		{
			temp = new node;
			temp->data = v;
			temp->next = head;
			tail->next = temp;
			tail = temp;
		}
		void ins_bef(int val,int given)
		{
			node *str = new node;
			node *pre = new node;
			pre = NULL;
			temp = new node;
			temp = head;
			while(temp->data != given)
			{
				pre = temp;
				temp = temp->next;
			}
			if(pre == NULL)
			{
				ins_beg(val);
			}
			else
			{
				str->data = val;
				str->next = temp;
				pre->next = str;
			}
		}
		void ins_after(int val,int given)
		{
			node *ptr = new node;
			ptr = head;
			while(ptr->data != given)
			{
				
				ptr = ptr->next;
			}
			temp = new node;
			if(ptr->next == head)
			{
				ins_end(val); 
			}
			else
			{
				temp->data = val;
				temp->next = ptr->next;
				ptr->next = temp;
			}
		}
		void ins_sort(int val)
		{
			node *ptr = new node;
			node *pre = new node;
			pre = NULL;
			ptr = head;
			
			
			do
			{
				
				if(ptr->data > val)
				break;
				pre = ptr;
				ptr = ptr->next;
				
			}while(ptr != head);
			
			
			if(pre == NULL)
				ins_beg(val);
			else if(ptr == head)
				ins_end(val); 
			else
				ins_after(val,pre->data);	
		}
		void del_beg()
		{
			if(head == NULL)
			{
				cout<<"UnderFlow\n";
			}
			else
			{
				tail->next = head->next;
				head->next = NULL;
				delete head;
				head = tail->next;
			}
		}
		void del_end()
		{
			node *pre = new node;
			pre = head;
			temp = new node;
			temp = head;
			while(temp->next != head)
			{
				pre = temp;
				temp = temp->next;
			}
			pre->next = head;
			temp->next = NULL;
			delete temp;
		}
		void del_ele(int val)
		{
			node *pre = new node;
			node *cur = new node;
			cur = head;
			pre = NULL;
			while(cur->data != val)
			{
				pre = cur;
				cur = cur->next;
			}
			if(pre == NULL)
			{
				del_beg();
			}
			else
			{
				pre->next = cur->next;
				cur->next = NULL;
				delete cur;
			}
		}
		void del_pre(int val)
		{
			node *pre; //= new node;
			node *prepre;// = new node;
			node *curr; //= new node;
			curr = head;
			pre = NULL;
			prepre = NULL;
			while( curr->data != val )
			{
				prepre = pre;
				pre = curr;
				curr = curr->next;
			}
			if(pre == NULL && prepre == NULL)
			{
				del_end();
			}
			else if(prepre == NULL && pre == head)
			{
				del_beg();
			}
			else
			{
				prepre->next = pre->next;
				pre->next = NULL;
				delete pre;
			}
		}
		void del_after(int val)
		{
			node *ptr = new node;
			temp = new node;
			temp = head;
			while(temp->data != val)
			{
				temp = temp->next;
			}
			if(temp->next == head)
			{
				del_beg();
			}
			else 
			{
				ptr = temp->next;
				temp->next = ptr->next;
				ptr->next  = NULL;
				delete ptr;
			}
		}
};
int main()
{
	list L;
	int go,choice,val,num;
	cout<<"To enter list in FIFO manner (i.e. 1 , 2 , 3 , 4 , ....) , press 1 and to create list in LIFO ";
	cout<<"manner(i.e. ....., 4 , 3, 2 , 1) press 2 \n";
	cin>>choice;
	cout<<"Enter values in list and to stop entering, press -1\n";
	cin>>go;
	switch(choice)
	{
		case 1:
			while(go != -1)
			{
				L.create_insEnd(go);
				cin>>go;
			}
			break;
		case 2:
			while(go != -1)
			{
				L.create_insBeg(go);
				cin>>go;
			}
			break;
	}
	L.display();
	cout<<"To insert an element at the beginning press 1\n";
	cout<<"To insert an element at the end press 2\n";
	cout<<"To insert an element after an element, press 3\n";
	cout<<"To insert an element before an element press 4\n";
	cout<<"To insert an element and want list sorted even after insertion, press 5\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter value of element you want to insert at the beginning\n";
			cin>>go;
			L.ins_beg(go);
			break;
		case 2:
			cout<<"Enter value of element you want to insert at the end\n";
			cin>>go;
			L.ins_end(go);
			break;
		case 3:
			cout<<"Enter value of element you want to insert and value of element after which you want it inserted\n";
			cin>>val>>num;
			L.ins_after(val,num);
			break;
		case 4:
			cout<<"Enter value of element you want to insert and value of element before which you want it inserted\n";
			cin>>val>>num;
			L.ins_bef(val,num);
			break;
		case 5:
			cout<<"Enter element that you want to insert\n";
			cin>>val;
			L.ins_sort(val);
			break;
	}
	L.display();
	cout<<"To delete elememt at the beginning press 1\n";
	cout<<"To delete element at the end press 2\n";
	cout<<"To specify an element for deletion, press 3\n";
	cout<<"To specify an element whose previous value you want to delete, press 4\n";
	cout<<"To delete an element whose next value you want to delete, press 5\n";
	cin>>go;
	switch(go)
	{
		case 1:
			L.del_beg();
			break;
		case 2:
			L.del_end();
			break;
		case 3:
			cout<<"Enter the value of element you want to delete\n";
			cin>>val;
			L.del_ele(val);
			break;
		case 4:
			cout<<"Enter that element whose previous value you want to delete\n";
			cin>>val;
			L.del_pre(val);
			break;
		case 5:
			cout<<"Enter that element whose next value you want to delete\n";
			cin>>val;
			L.del_after(val);
			break;
	}
	L.display();
	return 0;
}
