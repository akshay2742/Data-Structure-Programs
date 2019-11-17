#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=(low-1);
    int j,temp;

    for ( j = low; j <= high-1; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}

void quick_sort(int arr[],int low,int high)
{
    if (low<high)
    {
        int p=partition(arr,low,high);

        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
    
}

int main()
{

    int array[10],i;
    cout<<"Enter the Array: \n";
    for ( i = 0; i < 10; i++)
    {
        cin>>array[i];
    }
    
    quick_sort(array,0,9);
    cout<<"Sorted Array: \n";

    for ( i = 0; i < 10; i++)
    {
        cout<<array[i]<<" ";
    }
    
    
}