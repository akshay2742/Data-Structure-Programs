#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cctype>
using namespace std;
int prec(char c)
{
    if (c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else
        return -1;
}
void infix_to_postfix(string s)
{
    std:: stack <char> st;
    int i;
    char p;
    string a;
    int l= s.length();
    for(i=0;i<l;i++)
    {
        
        if(isdigit(s[i]))
        {
            
            a+=s[i];
        }
        else if (s[i]=='(' )
        {
            
            st.push(s[i]);
            
        }
        else if (s[i]==')')
        {
            while(st.top()!='(')
            {
                p=st.top();
                st.pop();
                a=a+p;
            }
            if(!st.empty())
            {
                
                st.pop();
                
            }
            
        }
        else
        {
             while(prec(s[i]) < prec(st.top())) 
            { 
                char ch = st.top(); 
                st.pop(); 
                a+= ch; 
            } 
            st.push(s[i]);
        }
        
        
    }
    cout<<a<<endl;
}
int main()
{
    string exp = "(((2+3*4/8)+5)*6)";
     
    infix_to_postfix(exp);
    
    return 0; 
}

//using stack.h
#include<iostream>
using namespace std;
#include "stack.h"

int precedence(char s)
{
  if(s == '^')
    return 1;
  else if(s == '*' || s == '/')
    return 2;
  else if(s == '+' || s == '-')
    return 3;
  else if(s == '(' || s == ')')
    return 4;
  else
    return -1;
}

void infix_postfix(string exp)
{
  Stack <char> s;
  s.push('N');
  int l = exp.length();
  for(int i=0; i<l; i++)
  {
    if(exp[i] == '(')
      s.push(exp[i]);
    else if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
      cout<<exp[i];
    else if(exp[i] == ')')
    {
      while(s.top_ele() != '(')
      {
        char element = s.top_ele();
        cout<<element;
        s.pop();
      }
    }
    else
    {
      if(s.top_ele() == 0)
        s.push(exp[i]);
      else
      {
        int p = precedence(exp[i]);
        if(p < precedence(s.top_ele()))
          s.push(exp[i]);
        else
        {
          char c = s.top_ele();
          s.pop();
          cout<<c;
          s.push(exp[i]);
        }
      }
    }
  }
  while(s.top_ele() != 'N')
  {
    char ele = s.top_ele();
    if(ele != '(')
      cout<<ele;
    s.pop();
  }
}

int main()
{
  string exp;
  cout<<"Enter expression: ";
  cin>>exp;

  cout<<"Postfix expression: ";
  infix_postfix(exp);

  return 0;
}
