#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
class Node{
   public:
       int pow;
       int coeff;
       Node *next;



};
class poly{
public:
    Node *head, *tail;
    poly(){

      head=NULL;
      tail=NULL;
    }

    void create_node(int c,int p){
        Node* temp=new Node;
        temp->coeff=c;
        temp->pow=p;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }

    }


void show()
{
    Node* node=head;
  while(node!= NULL)
    {
    cout<<node->coeff<<"x^"<<node->pow;
    node = node->next;
    if(node!= NULL)
        cout<<" + ";
    }
}


};

void polyadd(poly p1,poly p2,poly p3){

  Node *poly1=p1.head;
  Node *poly2=p2.head;
  Node *poly3=p3.head;

    while(poly1->next!=NULL && poly2->next!=NULL)
    {


        // If power of 1st polynomial is greater then 2nd, then store 1st as it is
        // and move its pointer
        if(poly1->pow > poly2->pow)
        {

            poly3->pow = poly1->pow;

            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;


        }

        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is
        // and move its pointer
        else if(poly1->pow < poly2->pow)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then add their coefficients
        else
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node

        poly3->next=new Node();
        poly3 = poly3->next;


    }

    while(poly1!=NULL || poly2!=NULL)
    {
        if(poly1!=NULL)
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2!=NULL)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly3=new Node();
        poly3 = poly3->next;


    }


}

int main(){
    poly p1,p2,p3;


    p1.create_node(5,2);
    p1.create_node(4,1);
    p1.create_node(2,0);

    // Create second list of 5x^1 + 5x^0
    p2.create_node(7,1);
    p2.create_node(8,0);

    p3.create_node(NULL,NULL);








    cout<<"1st number: ";
    p1.show();
cout<<"\n";
    cout<<"2nd number: ";
    p2.show();

    // Function add two polynomial numbers
    polyadd(p1,p2,p3);

    // Display resultant List
   cout<<"\nadded polynomial: ";
    p3.show();

}

