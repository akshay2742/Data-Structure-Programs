#include<iostream>
using namespace std;

void diagonal(int m,int n,int** arr)
{
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i==j)
            {
                cout<<*(*(arr+i)+j)<<" ";
            }
        }
        
    }
}
void Upper_triangle(int m,int n,int** arr)
{
    int i,j,k;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i<=j)
            {
                cout<<*(*(arr+i)+j)<<" ";
            }
            
        }
        
    }
}

void Lower_triangle(int m,int n,int** arr)
{
    int i,j,k;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i>=j)
            {
                cout<<*(*(arr+i)+j)<<" ";
            }
            
        }
        
    }
}
void enter(int m,int n,int** arr)
{
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cin>>*(*(arr+i)+j);
        }
        
    }
    
}
void display(int m,int n,int** arr)
{
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{

    int** arr=new int*[3];
    
    int i,j;
    for ( i = 0; i < 3; i++)
    {
      arr[i]=new int[3];
    }
    enter(3,3,arr);
    cout<<"\nOriginal Matrix is: \n";
    display(3,3,arr);
    cout<<"\nDiagonals of the Matrix are: ";
    diagonal(3,3,arr);
    cout<<"\nUpper Triangular Matrix: ";
    Upper_triangle(3,3,arr);
    cout<<"\nLower Triangular Matrix: ";
    Lower_triangle(3,3,arr);

}