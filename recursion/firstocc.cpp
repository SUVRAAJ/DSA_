#include<iostream>
using namespace std;


int first_occ(int arr[], int n, int key)
{
    
    if(n==0)
    {
        return -1;
    }

    if(arr[0]==key)
    {
        return 0;
    }

    int c= first_occ(arr+1,n-1,key);
    if(c!=-1)
    {
        return c+1;
    }

    return -1;
}


int last_occ(int arr[], int n, int key)
{
    if(n==0)
    {
        return -1;
    }


    int c= last_occ(arr+1,n-1,key);
    if(c==-1)
    {
        if(arr[0]==key)
        {
            return 0;
        }

        else
        {
            return -1;
        }
    }

    else{
        return c+1;
    }


}

int main()
{
 int a[]= {1,2,3,6,4,5,6};
 int n= sizeof(a)/sizeof(a[0]);
 cout<<first_occ(a,n,6)<<endl;
 cout<<last_occ(a,n,6)<<endl;

}