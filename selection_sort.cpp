#include<iostream>
using namespace std;

void selection_sort(int a[],int n)
{
    int i,j;
    int temp=0;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (a[i]>a[j])
            {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp; 
            }
        }
        
    }
}

void bubble_sort(int a[],int n)
{
    int i,j;
    int temp=0;

    for ( i = 0; i <n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
}

void linear_search(int a[],int size,int n)
{
    int i;
    int count=0;
    for ( i = 0; i < size; i++)
    {
        if (a[i]==n)
        {
            count=1;
            break;
        }
        else
        {
            count=0;
        }
        
        
    }
    if (count==1)
    {
        cout<<"Element is found at index: "<<i;
    }
    else
    {
        cout<<"Element is not found";
    }
}

void binary_search(int a[],int size,int n)
{
    int first,end,mid,i;
    int count=0;

    first=0;
    end=size-1;
    mid=(first+end)/2;
    while ( first<=end)
    {
        if (a[mid]<n)
        {
            first=mid+1;
            mid=(first+end)/2;
        }
        if (a[mid]>n)
        {
            end=mid-1;
            mid=(first+end)/2;
        }
        if (a[mid]==n)
        {
            count=1;
            break;
        }
        
    }
    if (count==1)
    {
        cout<<"Element Found at : "<<mid;
    }
    else
    {
        cout<<"Element not found";
    }
    
    
    
}

int main()
{
    int n=6;
    int a[n];
    int i;
    
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    
    
    cout<<"\n\nSorted Array is: ";
    for ( i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    binary_search(a,n,6);
    
}