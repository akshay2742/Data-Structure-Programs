#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
void string_reverse(string s)
{
    if (s.size()==0)
    {
        return ;
    }
    
    string_reverse(s.substr(1));
    cout<<s[0];

    
    
    
}

int main()
{
    string s="akshay";
    string_reverse(s);

    
}