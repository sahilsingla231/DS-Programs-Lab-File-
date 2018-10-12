#include<iostream>
using namespace std;



struct node
{
	int info;
	node *left;
	node *right;
	
};

void search(node *root,int item)
{ 
	node * p,*t;
	
	p=root;
	
	while(p!=NULL && p->info != item)
	{
		t=p;
		
		if(p->info > item)
		{
			p= p->left;
		}
		else
		{
			p=p->right;
		}
	}
	
	if(t->left == p)
	{
		t->left = NULL;
		delete p;
	}
	else if(t->right==p)
	{
		t->right =NULL;
		delete p;
		
	}
	else if(p== NULL)
	{
		cout<<"Item Not Present";
	}
	
}


void preorder(node* root)
{
	if(root !=NULL)
	{
		cout<<root->info<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	
}

void postorder(node* root)
{
	
	if(root !=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		cout<<root->info<<" ";
	}
	
}

void inorder(node* root)
{
	
	if(root !=NULL)
	{
		
		inorder(root->left);
		cout<<root->info<<" ";
		inorder(root->right);
	}
	
}

int main()
{
	node *root,*p,*t,*q;
	root=NULL;
	
	int n;
	cout<<"Enter elements to be inserted in tree n";
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		p=new node();
		
		cin>>p->info;
		
		p->left=NULL;
		p->right=NULL;
		
		if(root == NULL)
		{
			root=p;
		}
		else
		{
			t=root;
			
			while(t!=NULL)
			{
				q=t;
				if(t->info > p->info)
				{
					t= t->left;
				}
				else
				{
					t=t->right;
				}
			}
			
			if(q->info  > p->info )
			{
				q->left=p;
			}
			else
			{
				q->right=p;
				
			}
		}
	}
	
	cout<<"TRAVERSING IN A BST"<<endl;
	cout<<"PREORDER IS"<<endl;
	preorder(root);
	cout<<endl<<"POSTORDER IS"<<endl;
	postorder(root);
    cout<<endl<<"INORDER IS"<<endl;
	inorder(root);
	
	cout<<endl<<endl<<"Enter the item to be found and delete ";
	
	int s;
	cin>>s;
	search(root,s);
	
	cout<<"TRAVERSING IN A BST"<<endl;
	cout<<"PREORDER IS"<<endl;
	preorder(root);
	cout<<endl<<"POSTORDER IS"<<endl;
	postorder(root);
    cout<<endl<<"INORDER IS"<<endl;
	inorder(root);
	
	
	
}
