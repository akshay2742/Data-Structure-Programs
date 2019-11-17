#include<iostream>
using namespace std;
template <class N>
class stack
{
    public:
        int MAX;
        int index;
        N *T;
        

        stack(int n)
        {
            MAX=n;
            index=0;
            T=new N[MAX];

        }

        bool full()
        {   
            //index==MAX bcz when last element enters index increses to MAX
            if (index==MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool empty()
        {
            if (index==0)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

        bool push(N num)
        {


            if (!full())
            {
                T[index]=num;
                index++;
                return true;
            }
            else
            {
                return false;
            }
        }

        bool pop()
        {
            if (!empty())
            {
                index--;
                return true;
            }
            else
            {
                return false;
            }
        }

        int top_element()
        {
            if (!empty())
            {
                return T[index-1];
            }
            else
            {
                return 0;
            }
        } 
        
};

int main()
{
    char dec='y';
    char top,d,num_push,t_element;
    int n,c;
    cout<<"\n\nENTER THE SIZE OF THE STACK: ";
    cin>>n;
    stack <char> s(n);

    cout<<"\n\nENTER THE ELEMENTS IN THE STACK: \n";
    while (!s.full())
    {
        cin>>d;
        s.push(d);
    }
  
    
    while (dec=='y')
    {
        cout<<"\n1. PUSH THE ELEMENT IN THE STACK"
            <<"\n2. POP THE ELEMENT IN THE STACK"
            <<"\n3. CHECK WHETHER STACK IS EMPTY"
            <<"\n4. CHECK WHETHER STACK IS FULL"
            <<"\n5. PRINT TOP ELEMENT";

        cout<<"\nENTER YOUR CHOICE: ";
        cin>>c;
    
        switch (c)
        {
            case 1:
                cout<<"\nENTER THE ELEMENT YOU WANT TO PUSH: ";
                cin>>num_push;
                s.push(num_push);
                while (!s.empty())
                {
                    top=s.top_element();
                    cout<<top<<"\n";
                    s.pop(); 
                }
                break;

            case 2:
                s.pop();
                while (!s.empty())
                {
                    top=s.top_element();
                    cout<<top<<"\n";
                    s.pop(); 
                }
                break;

            case 3:
                if (s.empty())
                {
                    cout<<"\nSTACK IS EMPTY";
                    break;
                }
                else
                {
                    cout<<"\nSTACK IS NOT EMPTY";
                    break;
                }

            case 4:
                if (s.full())
                {
                    cout<<"\nSTACK IS FULL";
                    break;
                }
                else
                {
                    cout<<"\nSPACE IS AVAILABLE";
                    break;
                }
                
            case 5:
                
                t_element=s.top_element();
               
                    cout<<"\n"<<t_element;
                    break;
               
                
        }
        cout<<"\nIF YOU WANT TO CONTINUE(PRESS Y) IF NOT(PRESS N): ";
        cin>>dec;

        
    }

    

}