
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n)
{
    int temp;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectSort(int arr[],int n)
{
    int temp;
    int minindex;
    for(int i=0;i<n-1;i++)
    {
        minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}

int main()
{
    int arr[]={1,3,63,5,78,9,12,52,8};
    int n=sizeof(arr) / sizeof(int);
    //bubbleSort(arr,n);
    selectSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;

}

