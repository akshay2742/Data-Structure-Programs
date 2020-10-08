#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            next=NULL;
        }
};
class clinked_list
{
    public:
        Node* head;
        Node* tail;

        clinked_list()
        {
            head=NULL;
            tail=NULL;
        }

        void add_to_start(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;
            if (head==NULL)
            {
                head=new_node;
                tail=new_node;
                new_node->next=tail;
                new_node->prev=tail; 
                
            }
            else
            {
               new_node->next=head;
               head->prev=new_node;
               new_node->prev=tail;
               head=new_node;
                tail->next=head;
            }
        }
        void add_to_tail(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;
            if (head==NULL)
            {
                head=new_node;
                tail=new_node;
                new_node->next=head;
                new_node->prev=tail;
            }
            else
            {
                tail->next=new_node;
                
                new_node->next=head;
                new_node->prev=tail;
                head->prev=new_node;
                tail=new_node;
               
            }
            
        }

        void traverse()
        {
            Node* temp=head;
            do
            {
                cout<<temp->data<<"\n";
                temp=temp->next;
            } while (temp!=head);
            
        }

        void reverse_traverse()
        {
            Node* temp=tail;
            do
            {
                cout<<temp->data<<"\n";
                temp=temp->prev;
            } while (temp!=tail);
            
        }

};

int main()
{
    clinked_list list;

    list.add_to_start(9);
    list.add_to_start(4);
    list.add_to_start(2);
    list.add_to_start(1);
    list.add_to_tail(15);
    cout<<"Traversal of list:\n";
    list.traverse();
    cout<<"Reverse Traversal of list:\n";
    list.reverse_traverse();
}

/*

#include<bits/stdc++.h>
using namespace std;

template <class t>
class CDLLNode
{
	public:
	t info;	//template
	CDLLNode*next;
	CDLLNode*prev;
	
	CDLLNode(t element)		//int==t
	{
		info = element;
		next = this;
		prev = this;
	}
	
};

template<class t>
class CDLLList
{
	
	CDLLNode<t> *tail;
	
	public:
	CDLLList()
	{
		tail=0;
	}
	
	void insertatHead(t element)
	{
		CDLLNode<t>* N = new CDLLNode<t>(element);
		//CDLLNode <t>*temp = tail->next;
		
		if(tail==0)
		{
			tail = N;
			tail->next=N;
			tail->prev=tail; 
		}
		
		else
		{
	
			tail->next ->prev=N;
			N->next=tail->next;
			tail->next=N;	
		}	
			
		
	}
	
	void insertatTail(int element)
	{
		CDLLNode<t>*N = new CDLLNode<t>(element);
	//	CDLLNode<t> *temp = tail->next;
		
		if(tail==0)
		{
			tail = N;
			tail->next=N;
			tail->prev=N;
		}
		
		else
		{
			N->next=tail->next;
			tail->next=N;
			N->prev=tail;
			
		}	
		
	}
	
	void traverse()
	{

		CDLLNode<t> *temp= tail->next;
		if(tail==NULL|| temp==NULL)
		{
			cout<<"\nList is Empty\n";
		}
		
		else
		{
			while(temp!=tail)
			{
				cout<<temp->info<<" -> ";
				temp=temp->next;
			}
			
			cout<<tail->info;
		}		
	}
	
	
	bool search(t element)
	{
		CDLLNode<t> *temp= tail->next;
		bool flag = true;
		
		while(temp!=tail)
		{
			if(temp->info==element)
			{
				flag=true;
			}
			temp=temp->next;
		}
		
		if(tail->info==element)
		flag = true;
		return flag;
			
	}
	
	void del()
	{
		if(tail==NULL)	//list is empty
		{
			return;
		}
		
		else if(tail == tail->next)		//list has one element
		{
			delete(tail);
		}
		
		else
		{
			CDLLNode<t> *temp= tail->next;
			tail->next=temp->next;
			tail->next->prev=tail;
			delete(tail);
		}
	}
	
	void delend()
	{
		if(tail==NULL)	//list is empty
		{
			return;
		}
		
		else if(tail == tail->next)		//list has one element
		{
			delete(tail);
		}
		
		else
		{
			temp->next=tail->next;
			delete(tail);
			tail=temp;
			tail->next->prev=tail;
		}
			
	}
	
	void del_after_pos(int pos)
	{
		if(tail==0)
		{
			cout<<"\nList is Empty";	
		}	
		
		else if(tail->next==tail)
		{
			delete(tail);
			tail=0;
		}
		
		else if(tail->next!=tail)
		{
			CDLLNode<t> *pre = tail->next;
			CDLLNode<t> *curt= tail->next;
			int index = 0;
			while(1)
			{
				index++;
				if(index==pos+1)
					break;
				pre = curt;
				curt = curt->next;
			}
			curt->next->prev=pre;
			pre->next=curt->next;
			delete(curt);
		}
	}

	void del_before_pos(int pos)
	{
		
		if(tail==0)
		{
			cout<<"\nList is Empty";	
		}	
		
		else if(tail->next==tail)
		{
			delete(tail);
			tail=0;
		}
		
		else if(tail->next!=tail)
		{
			CDLLNode<t> *pre = tail->next;
			CDLLNode<t> *curt= tail->next;
			int index = 0;
			while(1)
			{
				index++;
				if(index==pos-1)
					break;
				pre = curt;
				curt = curt->next;
			}
			curt->next->prev=pre;
			pre->next=curt->next;
			delete(curt);
		}	
	}
	
	void menu2(t element)
	{
		int option,pos;
	
		do
		{
		
			cout<<"\n\n	***MENU***\n";
			cout<<"Press 1. Inserting an element At Beginning\n";
			cout<<"Press 2. Inserting an element At End\n";
			cout<<"Press 3. For Display of elements\n";
			cout<<"Press 4. For Delete at beginning\n";
			cout<<"Press 5. For Delete at end\n";
			cout<<"Press 6. For Search\n";
			cout<<"Press 7. For Delete after given Position\n";
			cout<<"Press 8. For Delete before given Position\n";
			cout<<"Press 9. Exit\n";
	
		
			cout<<"Enter option: ";
			cin>>option;
	
			switch(option)
			{
			case 1: cout<<"Enter an Element: ";
					cin>>element;
					insertatHead(element);
					break;
			
			case 2: cout<<"Enter an Element: ";
					cin>>element;
					insertatTail(element);
					break;
			
			case 3: traverse();
					break;
				
			case 4: del();
					break;
			
			case 5: delend();
					break;
			
			case 6: cout<<"Element you want to find: ";
					cin>>element;
					if(search(element)==1)
					{
						cout<<"\nElement is Present in List\n";
					}
					else
						cout<<"\nElement is not present in the List\n";
						break;
				
			case 7: cout<<"Enter Position: ";
					cin>>pos;
					del_after_pos(pos);
					break;
					
			case 8: cout<<"Enter Position: ";
					cin>>pos;
					del_before_pos(pos);
					break;
			
			case 9: cout<<"\n\nExiting\n";
					exit(0);
		
		
			default:cout<<"\nInvalid input\n";
	      			break;
			
			}
			
		}while(option!=7);
	}
	
};

void menu1()
{
	cout<<"\n\n\tTYPES\n";
	cout<<"1. Int \n";
	cout<<"2. Char \n";
	cout<<"3. Float\n";
	cout<<"4. Long \n";
	cout<<"Enter Choice: ";
	
}

int main()
{

	int opt,me1;
	char choice;
	
	menu1();
	cin>>me1;
	cout<<endl;
	
	if(me1 == 1)
	{
		int element;
		CDLLList < int > DL;
		DL.menu2(element);
	}
	
	else if(me1 == 2)
	{
		char element;
		CDLLList <char> DL;
		DL.menu2(element);
	}
	
	else if(me1 == 3)
	{
		float element;
		CDLLList < float > DL;
		DL.menu2(element);	
	}
	
	else if(me1 == 4)
	{
		long element;
		CDLLList <long> DL;
		DL.menu2(element);
	}
	
	else 
	{
		cout<<"\nInvalid input";	
	}
	
	return 0;
}



*/
