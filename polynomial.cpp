#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        int power;
        Node* next;

        Node()
        {
            next==NULL;
        }
};
class polynomial
{
    public:
        Node* head;
        Node* tail;

        polynomial()
        {
            head=NULL;
            tail=NULL;
        }

        void enter_poly(int d,int p)
        {
            Node* new_node=new Node();

            new_node->data=d;
            new_node->power=p;

            if (head==NULL)
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
        void enter_poly_tail(int d,int p)
        {
            Node* new_node1=new Node();

            if (head==NULL)
            {
                head=new_node1;
            }
            else
            {
                tail->next=new_node1;
                tail=tail->next;
            }
        }
        
        
        void traverse()
        {
            Node* temp=head;
            cout<<"Polynomial is: \n";
            while (temp!=NULL)
            {
                cout<<temp->data<<"x^"<<temp->power<<endl;
                temp=temp->next;
            }
            
        }

};
void merge(polynomial list1,polynomial list2)
{
    list1.tail->next=list2.head;
    list1.tail=list2.tail;
}
void add_polynomial(polynomial list1,polynomial list2)
{
    Node* temp=list1.head;
    Node* temp1=list2.head;
    while (temp!=NULL)
    {
        Node* temp1=list2.head;
        while (temp1!=NULL)
        {
            if (temp->power==temp1->power)
            {
                temp->data+=temp1->data;
                if (temp1==list2.head)
                {
                    Node* p=list2.head;
                    list2.head=list2.head->next;
                    delete p;
                }
                else
                {
                    Node* r=list1.head;
                    Node* s=list2.head;

                    while (r!=NULL)
                    {
                        while (s!=NULL )
                        {
                            if (r->next->power!=s->next->power)
                            {
                                s=s->next;
                            }
                            else
                            {
                                break;
                            }
                              
                        }
                        Node* q=s->next;
                        s->next=q->next;
                        delete q;
                        r=r->next;
                    }   
                }
            }
            temp1=temp1->next;
            }
            temp=temp->next;
    }
}

int main()
{
    polynomial p,p1;
    p.enter_poly(4,2);
    p.enter_poly(3,1);
    p.enter_poly(6,3);
    p1.enter_poly(5,3);
    p1.enter_poly(6,2);
    
    add_polynomial(p,p1);
    merge(p,p1);
    
    p.traverse();
    
    

}