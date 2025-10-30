#include<iostream>
#include<vector>
using namespace std;

void meerge(vector<int> &arr, int lo,int hi)
{
    int i=lo;
    int m= (hi+lo)/2;
    int k=m+1;

    vector<int> temp;

    while(i<=m && k<=hi)
    {
        if(arr[i]<arr[k])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[k]);
            k++;
        }
    }

    while (i<=m)    
    {
       temp.push_back(arr[i]);
            i++; 
    }

    while (k<=hi)    
    {
        temp.push_back(arr[k]);
            k++;
    }

    int j=0;
    for(int idx=lo; idx<=hi; idx++)
    {
        arr[idx]=temp[j++];
    }
    
    return;

}


void m_sort(vector<int> & arr,int lo,int hi)
{

    if(lo>=hi)
    {
        return;
    }
        int mid= (hi+lo)/2;
        m_sort(arr,lo,mid);
        m_sort(arr,mid+1,hi);
        return meerge(arr,lo,hi);

}

int main()
{
    vector<int> arr= {1,7,4,9,10,2,6,5};
    int l=0;
    int r= arr.size()-1;
    m_sort(arr,l,r);
    for(int i=0;i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}