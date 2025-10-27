#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int key;

    node(int d)
    {
        key=d;
        right=left=nullptr; 
    }
};

node* bst_build(node* root, int data)
{
    if(root==nullptr)
    {
        return new node(data);
    }

    else if(data<root->key)
    {
        root->left=bst_build(root->left,data);
    }

    else if(data>root->key)
    {
        root->right=bst_build(root->right,data);
    }

    return root;
}


void in_order(node*root)
{
    if(root==nullptr)
    {
        return;
    }

    in_order(root->left);
    cout<<root->key<<" ";
    in_order(root->right);
}

bool search(node* root, int val)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->key==val)
    {
        return true;
    }

    else if(val<root->key)
    {
        return search(root->left,val);
    }

    else if(val>root->key)
    {
        return search(root->right,val);
    }

    return false;
}

int min_order(node*root)
{
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root->key;
}

node* delete_in_bst(node*root, int val)
{
    if(root==nullptr)
    {
        return nullptr;
    }

    

    else if(val<root->key)
    {
        root->left=delete_in_bst(root->left,val);
    }

    else if(val>root->key)
    {
        root->right=delete_in_bst(root->right,val);
    }

    if(root->key==val)
    {
        //case1: leaf node
        if(root->left==nullptr && root->right==nullptr)
        {
            delete root;
            return nullptr;
        }
        //case if 1 child
        else if(root->right==nullptr)
        {
            node*temp= root;
            root= root->left;
            delete temp;
        }

        else if(root->left==nullptr)
        {
            node* temp= root;
            root= root->right;
            delete temp;
        }
        //case if 2 children
        else{
            int min= min_order(root->right);
            root->key=min;
            root->right= delete_in_bst(root->right,min);
        }
    }

    return root;
}

void print_in_range(node*root,int lo,int hi)
{
    if(root==nullptr)
    {
        return;
    }
    else if(root->key>hi)
    {
        print_in_range(root->left,lo,hi);
    }
    
    if(root->key>=lo && root->key<=hi)
    {
        cout<<root->key<<" ";
        print_in_range(root->left,lo,hi);
        print_in_range(root->right,lo,hi);
    }


    else if(root->key<lo)
    {
        print_in_range(root->right,lo,hi);
    }
}

int main() {
    node* root = nullptr;

    // 1. Build BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int v : values) {
        root = bst_build(root, v);
    }

    cout << "In-order traversal (should be sorted): ";
    in_order(root);
    cout << endl;

    // 2. Search tests
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not Found") << endl;

    // 3. Print in range
    cout << "Keys between 25 and 65: ";
    print_in_range(root, 25, 65);
    cout << endl;

    // 4. Delete leaf node
    root = delete_in_bst(root, 20);
    cout << "After deleting 20 (leaf): ";
    in_order(root);
    cout << endl;

    // 5. Delete node with one child
    root = delete_in_bst(root, 30);
    cout << "After deleting 30 (one child): ";
    in_order(root);
    cout << endl;

    // 6. Delete node with two children
    root = delete_in_bst(root, 50);
    cout << "After deleting 50 (two children): ";
    in_order(root);
    cout << endl;

    return 0;
}
