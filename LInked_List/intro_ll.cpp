#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

class LL{
    Node * head;
    Node * tail;

    public:
     LL()
     {
        head=NULL;
        tail=NULL;
     }

     void push_front(int dd)
     {
        if(head==nullptr)
        {
            Node* n= new Node(dd);
            head=tail=n;
            return;
        }

        else{
            Node * n= new Node(dd);
            n->next=head;
            head=n;

        }
     }

     void push_back(int dd)
     {
        if(head==nullptr)
        {
            Node * n= new Node(dd);
            head= tail= n;
        }

        else{
            Node* n= new Node(dd);
            tail->next=n;
            tail=n;
        }
     }

     void printLL()
     {
        Node* ptr= head;

        while(ptr!=NULL)
        {
            cout<<ptr->data<<"->"<<" ";
            ptr=ptr->next;
        }

        cout<<endl;
     }

     void insert(int pos,int dd)
     {
        if(pos==0)
        {
            push_front(dd);
            return;
        }
        Node * temp= head;
        for(int jumps=1;jumps<=pos-1;jumps++)
        {
            temp=temp->next;
        }

        Node* n= new Node(dd);
        n->next=temp->next;
        temp->next=n;

     }

     int help_search(int key,Node* h)
     {

        if(h->data==key)
        {
            return 0;
        }

        if(h->next==NULL)
        {
            return -1;
        }

        int sub_idx= help_search(key,h->next);

        return sub_idx+1;
     }

     int search(int key)
     {
        Node* h= head;
        return help_search(key,h);
     }
};

int main()
{
    LL obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);
    obj.printLL();
    obj.push_front(0);
    obj.printLL();
    obj.insert(3,5);
    obj.printLL();
    cout<<obj.search(3);
    return 0;
}