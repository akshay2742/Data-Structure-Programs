#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
        Node()
        {
            next=NULL;
        }
};

class O_linked_list
{
    public:
        Node* head;
        Node* tail;

        O_linked_list()
        {
            head=NULL;
            tail=NULL;
        }

        void add_node(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;
            if (head==NULL)
            {
                head=new_node;
                tail=new_node;
            }
            else if (head->data > d)
            {
                new_node->next=head;
                head=new_node;
            }
            else
            {
                Node* temp=head;
                while (temp->data > d)
                {
                    temp=temp->next;
                }
                new_node->next=temp->next;
                temp->next=new_node;
                
            }  
        }

        void delete_node(int d)
        {
            Node* temp=head;
            if (head==NULL)
            {
                cout<<"list is empty";
            }
            else if (head->data==d)
            {
                Node* temp=head;
                head=head->next;
                delete temp;
            }
            else
            {
                Node* temp=head;
                while ( temp->next!=NULL && temp->next->data!=d)
                {
                    temp=temp->next;
                }
                Node* p=temp->next;
                temp->next=p->next;
                delete p;
            }
           
            

        }

        void display()
        {
            Node* temp=head;
            cout<<"Ordered list is: ";
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            
        }

};

int main()
{
    O_linked_list list;

    list.add_node(8);
    list.add_node(2);
    list.add_node(4);
    list.add_node(3);
    list.add_node(1);
    list.delete_node(4);
    list.display();
}