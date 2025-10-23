#include<iostream>
#include <queue>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;

        node(int d)
        {
            data= d;
            left=nullptr;
            right= nullptr;
        }

};

node* pre_order_build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return nullptr;
    }
    node* root = new node(d);
    root->left= pre_order_build();
    root->right= pre_order_build();
    return root;
}

void level_order_traversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    if(root==nullptr)
    {
        return;
    }

    while(!q.empty())
    {
        node* front= q.front();
        q.pop();
        if(front==nullptr)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }

        else{

            cout<<front->data<<" ";
            if(front->left)
            {
                q.push(front->left);
            }

            if(front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{

    node* head=pre_order_build();
    level_order_traversal(head);
    return 0;
}