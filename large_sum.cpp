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
    int top,i,j,num,num1,n,q,r,p;
    int carry=0;
    cout<<"\nEnter the size of first Number";
    cin>>num;
    cout<<"\n\nEnter the size of second Number";
    cin>>num1;
    stack <int> s(num);
    stack <int> s1(num1);
    stack <int> s2(num+num1);

    
    

    cout<<"\n\nEnter the Number 1: \n";
    while (!s.full())
    {
        cin>>n;
        s.push(n);
    }

    cout<<"\n\nEnter the Number 2: \n";
    while (!s1.full())
    {
        cin>>q;
        s1.push(q);
    }

    while (!s.empty() && !s1.empty()) 
    {
        r=s.top_element() + s1.top_element()+carry;
        p=r%10;
        carry=r/10;
        s2.push(p);
        s.pop();
        s1.pop();
    }
    while (!s.empty())
    {
        r=s.top_element()+carry;
        p=r%10;
        carry=r/10;
        s2.push(p);
        s.pop();
    }
    while (!s1.empty())
    {
        r=s1.top_element()+carry;
        p=r%10;
        carry=r/10;
        s2.push(p);
        s1.pop();
    }
    if(carry)
    {
        s2.push(carry);
    }

    cout<<"\n\nThe Sum of the Two Numbers is: ";    
    while (!s2.empty())
    {
        top=s2.top_element();
        cout<<top;
        s2.pop();
    }
    
}