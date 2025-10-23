#include <iostream>
using namespace std;

void is_odd(int n)
{
    if(n&1)
    {
        cout<<"odd";
    }

    cout<<"even"<<endl;
}

int get_bit(int n, int i)
{
    int bit_mask= 1<<i;

    return n & bit_mask;
}

int set_bit(int n, int i)
{
    int bit_mask= 1<<i;

    return n|bit_mask;
}

int clear_bit(int n, int i)
{
    int bit= ~(1<<i);

    return n & bit;
}

int update_bit(int n, int i,int v)
{
    n=clear_bit(n,i);
    int mask= v<<i;
    return n | mask;
}

int main()
{
    is_odd(4);
    int n=5;
    cout<<get_bit(n,1)<<endl;
    cout<<set_bit(n,1)<<endl;
    cout<<clear_bit(n,0)<<endl;
    cout<<clear_bit(n,1)<<endl;
    return 0;
}