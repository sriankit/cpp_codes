#include<iostream>
 
using namespace std;
int a[100]={0,0,1,1,1,1,1,1,2,3};
 
int leftfn(int start, int last, int k)
{
    int mid = (last+start)/2,left=start;
    if(start!=last)
    {
    if(k-a[mid]>0)
        left = leftfn(mid+1,last,k);
    else
        left = leftfn(start,mid-1,k);
    }
    return left;
}
 
int rightfn(int start, int last, int k)
{
    cerr << start << " " << last << " " << k << endl;
    int mid = (last+start)/2,right=start;
    if(start!=last)
    {
    if(k-a[mid]>=0)
        right = rightfn(mid+1,last,k);
    else
        right = rightfn(start,mid-1,k);
    }
    return right;
}
 
int main()
{
    int i,k,n;
//    for(i=0;i<10;i++)
//        cin >> a[i];
    cin >> k;
    n = 10;
    int x = rightfn(0,n-1,k)- leftfn(0,n-1,k);
    for(i=0;i<10;i++)
        cout << a[i] <<endl;
    cout << x << endl;
}