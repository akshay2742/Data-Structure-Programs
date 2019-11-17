#include<iostream>
using namespace std;
void merge(int *a, int l, int m, int r)
{
    int i,j,k;

    int n1=m-l+1;
    int n2=r-m;

    int L[n1];
    int R[n2];

    for ( i = 0; i < n1; i++)
    {
        L[i]=a[l+i];
    }

    for ( j = 0; j < n2; j++)
    {
        R[j]=a[m+j+1];
    }

    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
        
        
    }

    while (i<n1)
    {
        a[k]=L[i];
        i++;
        k++;    
    }

    while (j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
    
        
}

void merge_sort(int *a,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;

        merge_sort(a,l,m);
        merge_sort(a,m+1,r);

        merge(a,l,m,r);
    }
}

int main()
{
    int arr[6];
    int i,j;

    cout<<"Enter the elements in the array: \n";
    for ( i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }

    merge_sort(arr,0,5);

    cout<<"Sorted Array is: \n";

    for ( i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}
    
    
    
    

