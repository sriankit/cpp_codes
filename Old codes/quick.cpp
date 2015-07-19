#include<iostream>
#include<conio.h>
using namespace std;
void QuickSort(int *array,int from,int to);
int main()
{
    int n,a[20],i;
    cout<<"Enter number of elements -\n";
    cin>>n;
    cout<<"Enter the elements -\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    QuickSort(a,0,n-1);
    cout<<"Sorted list is -\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    getch();
    return 0;
}
void QuickSort(int *array,int from,int to)
{
        if(from>=to)return;
        int pivot=array[from];
        int i=from,j,temp;
        for(j=from+1;j<=to;j++)
        {
                if(array[j]<pivot)
                {
                        i=i+1;
                        temp=array[i];
                        array[i]=array[j];
                        array[j]=temp;
                }
        }
        temp=array[i];
        array[i]=array[from];
        array[from]=temp;
        QuickSort(array,from,i-1);
        QuickSort(array,i+1,to);
}
