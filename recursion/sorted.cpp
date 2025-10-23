#include <iostream>
using namespace std;

bool is_sorted(int arr[], int n)
{
    if(n==1 || n==0)
    {
        return true;
    }

    if(arr[0]<=arr[1] && is_sorted(arr+1,n-1))
    {
        return true;
    }

    return false;
}


int main()
{
    int arr[]= {1,2,3,4,4,5};
    int n= sizeof(arr)/4;
    cout<<is_sorted(arr,n);
    return 0;
}