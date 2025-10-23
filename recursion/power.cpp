#include <iostream>
using namespace std;

int pp(int num,int p)
{
    if(p==0)
    {
        return 1;
    }

    int res= num*pp(num,p-1);
    return res;
}

int pp_opt(int num, int p)
{
    if(p==0)
    {
        return 1;
    }

    int sub= pp_opt(num,p/2);
    sub=sub*sub;
    if(p&1)
    {
        return num*sub;
    }

    return sub;
}

int main()
{
    cout<<pp_opt(3,5);
    return 0;
}