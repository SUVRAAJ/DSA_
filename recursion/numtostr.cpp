#include<string>
#include <iostream>
using namespace std;

string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void oral(int n)
{
    if(n==0)
    {
        return;
    }

    int a=n%10;
    oral(n/10);
    cout<<s[a]<<endl;

}

int main()
{
     oral(2120);
    return 0;
}