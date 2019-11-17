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