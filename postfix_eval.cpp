#include<iostream>
#include<string>
using namespace std;

class stack
{
    public:
        int index;
        int MAX;
        int* S;

        stack(int n)
        {
            index=0;
            MAX=n;
            S=new int[MAX];
        }

        bool isfull()
        {
            if (index==MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isempty()
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
        bool push(int d)
        {
            if (!isfull())
            {
                S[index]=d;
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
            if (!isempty())
            {
                index--;
                return true;
            }
            else
            {
                return false;
            }
        }

        int topel()
        {
            if (!isempty())
            {
                return S[index-1];
            }
            else
            {
                return 0;
            }
            
            
        }

    

};
void postfixeval(string s)
{
    int len=s.length();
    stack st(len);
    
    int i,p,a,b,c;

    for ( i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            p=s[i]-48;
            st.push(p);
        }
        else
        {
            switch (s[i])
            {
                case '+':
                    if (!st.isempty())
                    {
                        a=st.topel();
                        st.pop();
                        b=st.topel();
                        st.pop();
                        st.push(a+b);
                        break;
                    }

                case '-':
                    if (!st.isempty())
                    {
                        a=st.topel();
                        st.pop();
                        b=st.topel();
                        st.pop();
                        st.push(b-a);
                        break;
                    }
                
                case '*':
                    if (!st.isempty())
                    {
                        a=st.topel();
                        st.pop();
                        b=st.topel();
                        st.pop();
                        st.push(a*b);
                        break;
                    }
                
                case '/':
                    if (!st.isempty())
                    {
                        a=st.topel();
                        st.pop();
                        b=st.topel();
                        st.pop();
                        st.push(b/a);
                        break;
                    }
            }
        }

       
        
        

            
    }
     while (!st.isempty())
        {
            int c=st.topel();
            st.pop();
            cout<<c<<" ";
            
        }
        
}

int main()
{

    string a;
    a="2362/*+4+5*";
    postfixeval(a);
}

//Using stack.h
#include<iostream>
using namespace std;
#include "stack.h"

void postfix_evaluation(string exp)
{
  Stack <int> s;
  int l = exp.length();
  for(int i=0; i<l; i++)
  {
    if(exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '^')
    {
      exp[i] = (int)exp[i]-48;
      s.push(exp[i]);
    }
    else if(exp[i] == '+')
    {
      int ele1 = s.top_ele();
      s.pop();
      int ele2 = s.top_ele();
      s.pop();
      int element = ele1 + ele2;
      s.push(element);
    }
    else if(exp[i] == '-')
    {
      int ele1 = s.top_ele();
      s.pop();
      int ele2 = s.top_ele();
      s.pop();
      int element = ele2 - ele1;
      s.push(element);
    }
    else if(exp[i] == '*')
    {
      int ele1 = s.top_ele();
      s.pop();
      int ele2 = s.top_ele();
      s.pop();
      int element = ele1 * ele2;
      s.push(element);
    }
    else if(exp[i] == '/')
    {
      int ele1 = s.top_ele();
      s.pop();
      int ele2 = s.top_ele();
      s.pop();
      float element = ele2 / ele1;
      s.push(element);
    }
    else if(exp[i] == '^')
    {
      int ele1 = s.top_ele();
      s.pop();
      int ele2 = s.top_ele();
      s.pop();
      int element = 1;
      for(int i=0; i<ele1; i++)
        element *= ele2;
      s.push(element);
    }
  }
  float res = s.top_ele();
  cout<<res;
}

int main()
{
  string exp;
  cout<<"Enter the expression: ";
  cin>>exp;

  cout<<"Result: ";
  postfix_evaluation(exp);

  return 0;
}
