#include<iostream>
using namespace std;
template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node()
        {
            next=NULL;
            prev=NULL;
        }
};
template <class T>
class DLLlinkedlist
{
    Node<T>* head;
    Node<T>* tail;
    public:
        DLLlinkedlist()
        {
            head=NULL;
            tail=NULL;
        }
        void add_to_head(T d)
        {
            Node<T>* new_node=new Node<T>();
            new_node->data=d;
            new_node->prev=NULL;
            if(head==NULL)
            { 
              head=new_node;
              tail=new_node;     
            }
            else
            {
                head->prev=new_node;
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
                new_node1->prev=tail;
                tail->next=new_node1;
                tail=tail->next;
            }
            
            
        }
        void  add_to_nth(T d,int n)
        {
            Node<T>* new_node=new Node<T>();
            new_node->data=d;
            new_node->next=NULL;
            if(head==NULL)
            {
                head=new_node;
                tail=new_node;
            }
            else
            {
                int i=1;
                Node<T>* temp=head;
                while (temp!=NULL && i<n)
                {
                    temp=temp->next;
                    i++;
                }
                if(temp->next==NULL)
                {
                    new_node->data=d;
                    new_node->next=NULL;
                    new_node->prev=tail;
                    tail->next=new_node;
                    tail=tail->next;
                }
                else
                {
                    temp->next->prev=new_node;
                    new_node->next=temp->next;
                    temp->next=new_node;
                    new_node->prev=temp;
                }
                
                
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
        void reverse_traverse()
        {
            if(head==NULL)
            {
                cout<<"List Is Empty.\n";
            }
            else
            {
                Node<T>* temp=tail;
                cout<<"The Linked list is :\n";
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->prev;
                }
            }
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
                head->next->prev=NULL;
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
        bool search(T n)
	    {
		    Node<T> *temp;
		    temp=head;
		
		    while(temp!=NULL)
		    {
			    if(temp->info == element)
				    return true;
			    temp = temp->next;
	    	} 
		    return false;		
	    }
    
        void ispalindrome()
        {
            Node<T>* temp=head;
            Node<T>* temp1=tail;
            int count=0;
            while (temp!=NULL && temp1!=NULL)
            {
                if(temp->data==temp1->data)
                {
                    temp=temp->next;
                    temp1=temp1->prev;
                    count=1;
                }
                else
                {
                    count=0;
                    break;
                }
                
            }
            if(count==1)
            {
                cout<<"\nis palindrome";
            }
            else
            {
                cout<<"\nnot a palindrome";
            }
            
            
        }
       
        void del_after_Nth(int n)
        {
            int i=1;
            Node<T>* temp;
            temp=head;
            if (temp==NULL)
            {
                cout<<"List is empty";
                return;
            }
            else
            {
                    while(temp->next!=NULL && i<n-1)
                    {
                        temp=temp->next;
                        i++;
                    }
                    if(temp->next==NULL)
                    {
                        delete(tail);
                        temp->next=NULL;
                        tail=temp;
                        
                    }
                    else if (temp->next==tail)
                    {
                        delete(tail);
                        temp->next=NULL;
                        tail=temp;
                        
                    }
                    else
                    {
                        temp->next->next->prev=temp;
                        temp->next=temp->next->next;
                    }
                    

                
                
            }
            
        }
            
            
};
int main()
{
    int n,q;
    int e;
    char a='y';
    DLLlinkedlist<int> list;
    while(1)
    {
        if(a=='y')
        {
            cout<<"1. Add the element at the head\n"
                <<"2. Add the element at the tail\n"
                <<"3. Delete the element from the head\n"
                <<"4. Delete the element from the tail\n"
                <<"5. Search the element in the linked list\n"
                <<"6. Traverse the linked list\n"
                <<"7. Add the element at Nth position\n"
                <<"8. Print reverse linked list\n"
                <<"9. Check is palindrome\n"
                <<"10. Delete a node after a Nth position\n";
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
                    if(list.search(n)==1)
					{
						cout<<"\nElement is Present in List\n";
					}
					else
						cout<<"\nElement is not present in the List\n";
						break;

                case 6:
                    list.traverse();
                    break;

                case 7:
                    cout<<"Enter the position to which you want to add: ";
                    cin>>n;
                    cout<<"Enter the element you want to add: ";
                    cin>>e;
                    list.add_to_nth(e,n);
                    list.traverse();
                    break;

                case 8:
                    list.reverse_traverse();
                    break;

                case 9:
                    list.ispalindrome();
                    break;
                case 10:
                    cout<<"Enter the position after which you want to delete: ";
                    cin>>n;
                    list.del_after_Nth(n);
                    list.traverse();

                    
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
