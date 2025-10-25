#include<iostream>
#include <queue>
using namespace std;

class dh{
    public:
    int height;
    int diameter;
};

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

int height_tree(node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int h_left=height_tree(root->left);
    int h_right=height_tree(root->right);

    return 1+max(h_left,h_right);
}

int diameter_tree(node*root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int d1= height_tree(root->right)+height_tree(root->left);
    int d2= diameter_tree(root->left);
    int d3= diameter_tree(root->right);

    return max(d1,max(d2,d3));
}

dh opt_diameter(node* root)
{
    dh ans;
    if(root==nullptr)
    {
        ans.height=0;
        ans.diameter=0;
        return ans;
    }

    dh left_dia=opt_diameter(root->left);
    dh right_dia=opt_diameter(root->right);
    ans.height= 1+max(left_dia.height,right_dia.height);
    
    int d1=left_dia.height+right_dia.height;
    int d2=left_dia.diameter;
    int d3=right_dia.diameter;


    ans.diameter= max(d1,max(d2,d3));
    return ans;
}

int main()
{
    node* head=pre_order_build();
    level_order_traversal(head);
    cout<<height_tree(head)<<endl;
    dh wow;
    wow= opt_diameter(head);
    cout<<wow.height<<" "<<wow.diameter<<endl;
    cout<<diameter_tree(head);
    return 0;
}

////1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 10 -1 -1 -1 7 -1 -1///
