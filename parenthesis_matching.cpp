#include<iostream>
#include<string>
using namespace std;
template <class T>
class Stack{
public:
     
     T *S;
     int tos;
     /*contructor of stack class*/
     Stack()
     {
         tos=0;
         
         S=new T[100];
     }
     
     bool isfull()
     {
         if(tos==(100))
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
         if(tos==0)
         {
             
             return true;
         }
         else
         {
            
             return false;
         }
     }
     bool push(T element)
     {
         
        if(!isfull())
         {
             
             S[tos]=element;
             tos++;
             return true;
         }
        else
        {
            return false;
        }
     }
     bool pop()
     {
         if(!isempty())
         {
             tos--;
             return true;
         }
         else
         {
             return false;
         }
     }
     int topel()
     {
         
       if(!isempty())
       {
           return S[tos-1];
       
       }
       else
       {
         return 0;
       }
       
     }
};


bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool ParanthesesBalanced(string exp)
{
	Stack <char> st;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			st.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(st.isempty() || !ArePair(st.topel(),exp[i]))
				return false;
			else
				st.pop();
		}
	}
	return st.isempty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  "; 
	cin>>expression;
	if(ParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}

//using stack.h
#include<iostream>
using namespace std;
#include "stack.h"

bool balanced(string exp)
{
  Stack <char> s;
  //bool res = false;
  int l = exp.length();
  for(int i=0; i<l; i++)
  {
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      s.push(exp[i]);
    else if(exp[i] == ')')
    {
      if(s.top_ele() == '(')
      {
        s.pop();
        //res = true;
      }
      else
        return false;
    }
    else if(exp[i] == ']')
    {
      if(s.top_ele() == '[')
      {
        s.pop();
        //res = true;
      }
      else
        return false;
    }
    else if(exp[i] == '}')
    {
      if(s.top_ele() == '{')
      {
        s.pop();
        //res = true;
      }
      else
        return false;
    }
  }
  if(s.is_empty() == 0)
    return true;
  else
    return false;
  //return res;
}

int main()
{
  string exp;
  cout<<"Enter the expression: ";
  cin>>exp;

  if(balanced(exp) == 1)
    cout<<"Equation is balanced!"<<endl;
  else
    cout<<"Equation is not balanced!"<<endl;

  return 0;
}
