#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class graph{
    list<int> *l; // list stl is used over here
    int v; //number of vertices 
    public:
    graph(int v1)
    {
        v=v1;
        l= new list<int>[v1];  //initializing in the constructor
    }

    void addEdge(int num,int dest, bool uni_direct=true)
    {
        l[num].push_back(dest); //source to destination ka ek edge
        if(uni_direct)
        {
            l[dest].push_back(num); //if bidirectional to destination se source ka ek edge
        }

    }

    void print_adj()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(auto nbr: l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        vector<bool> visited(v,0);

        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int front= q.front();
            cout<<front<<" ";
            q.pop();
            
            for(auto nbr: l[front])
            {
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        cout<<endl;
    }

    void dfs_helper(int node, vector<bool>& visited)
    {
        visited[node]=true;
        cout<<node<<" ";
        for(auto nbr: l[node])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(int source)
    {
        vector<bool> visited(v,0);
        dfs_helper(source,visited);
    }
};

int main()
{
    graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.print_adj();
    g.bfs(1);
    g.dfs(1);
    return 0;
}