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

