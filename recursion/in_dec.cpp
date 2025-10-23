#include<iostream>
using namespace std;

void dec_order(int n)
{
    if(n==0)
    {
        return;
    }

    cout<<n;
    dec_order(n-1);
}

int count=1;

void inc_order(int n)
{
    if(n==0)
    {
        return;
    }
    
    inc_order(n-1);
    cout<<n;

}

int main()
{
    dec_order(5);
    inc_order(5);
}