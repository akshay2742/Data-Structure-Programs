#include<iostream>
using namespace std;
template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;
        Node()
        {
            next=NULL;
        }
};
template <class T>
class linkedlist
{
    Node<T>* head;
    Node<T>* tail;
    public:
        linkedlist()
        {
            head=NULL;
            tail=NULL;
        }
        void add_to_head(T d)
        {
            Node<T>* new_node=new Node<T>();
            new_node->data=d;
            if(head==NULL)
            { 
              head=new_node;
              tail=new_node;     
            }
            else
            {
                new_node->next=head;
                head=new_node; 
                

            }
        }
        void add_to_tail(T d)
        {
            Node<T>* new_node1=new Node<T>();
            new_node1->data=d;
            new_node1->next=NULL;
            if(head==NULL)
            {
                head=new_node1;
                tail=new_node1;
            }
            else
            {
                tail->next=new_node1;
                tail=tail->next;
            }
            
            
        }
         void traverse()
        {
            if(head==NULL)
            {
                cout<<"List Is Empty.\n";
            }
            else
            {
                Node<T>* temp=head;
                cout<<"The Linked list is :\n";
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
        }
        
        int total()
	    {
		Node<t> *temp = head;
		int count =0;
		
		while(temp!=NULL)
		{
			count = count+1;
			temp = temp->next;
			
		}
		
		return count;
	    }
    
        void del_from_head()
        {
            if(head==NULL)
            {
                cout<<"List is empty";
                return;
            }
            else if(head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                Node<T>* temp;
                temp=head;
                head=head->next;
                delete temp;
            }
        }
        void del_from_tail()
        {
            if (head==NULL)
            {
                cout<<"List is empty";
                return;
            }
            else if (head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                Node<T>* tem;
                tem=head;
                while(tem!=NULL)
                {
                    if(tem->next==tail)
                    {
                        delete(tail);
                        tail=tem;
                        tem->next=NULL;
                        break;
                    }
                    tem=tem->next;
                }
            }
        }
        
        void insert_before_pos(T n, int pos)
	    {
		Node<T>* temp = head;
		Node<T>* N = new Node<T>(element);
		
		int index = 0;
		if(head==NULL)
		{
			cout<<"\nInvalid Position";
		}
		
		else
		{
			while(1)
			{
				index++;
				if(index==pos-1)
					break;
				else if(temp->next==NULL || pos<1)
				{
					cout<<"\nInvalid position";
				}
					
				temp=temp->next;
			}
			else
			{
				N->next=temp->next;
				temp->next=N;
			}
		}
		
	}
        void search(T n)
        {
            int k=0;
            Node<T>* temp;
            temp=head;
            if(head==NULL)
            {
                cout<<"List is empty";
                return;
            }
            else
            {
                while (temp!=NULL)
                {
                    if(temp->data==n)
                    {
                        k=1;
                        break;  
                    }
                    temp=temp->next;
                }
                if(k==1)
                {
                    cout<<"element found\n";            
                }
                else
                {
                    cout<<"element not found\n";
                }
            }    
        }
            
            
};
int main()
{
    int n,q,pos;
    char e;
    char a='y';
    linkedlist<char> list;
    while(1)
    {
        if(a=='y')
        {
            cout<<"1. Add the element at the head\n"
                <<"2. Add the element at the tail\n"
                <<"3. Delete the element from the head\n"
                <<"4. Delete the element from the tail\n"
                <<"5. Search the element in the linked list\n"
                <<"6. Traverse the linked list\n";

                <<"7. Inser element befor N pos";

                <<"7. Total number of elements in the linked list\n";

            cout<<"\n\nEnter your choice: ";
            cin>>q;
            switch (q)
            {
                case 1:
                    cout<<"Enter the element you want to add: ";
                    cin>>e;
                    list.add_to_head(e);
                    list.traverse();
                    break;
        
                case 2:
                    cout<<"Enter the element you want to add: ";
                    cin>>e;
                    list.add_to_tail(e);
                    list.traverse();
                    break;
            
                case 3:
                    list.del_from_head();
                    list.traverse();
                    break;

                case 4:
                    list.del_from_tail();
                    list.traverse();
                    break;

                case 5:
                    cout<<"\nEnter the element to be searched ";
                    cin>>n;
                    cout<<endl;
                    list.search(n);
                    break;

                case 6:
                    list.traverse();
                    break;

                
                case 7:
                    cout<<"Enter Element: ";
				    cin>>element;
				    cout<<"\nEnter Position: ";
				    cin>>pos;
				    insert_before_pos(n,pos);
				    break;

                case 7:
                    cout<<"Total number of elements in list is: "<<list.total()<<endl;
                    break;

            }
            cout<<"\n\nDo you want to continue if yes press 'y' ,if no press 'n': ";
            cin>>a;    
        }
        else
        {
            break;
        }
         
    }
    
}
