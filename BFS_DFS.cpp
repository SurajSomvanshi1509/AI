#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class Suraj{
    public:
    map<int,list<int>>adjList;
    map<int,bool>visited;
    queue<int>q;
    void addEdges(int source,int destination){
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }
    void DFS(int node){
        visited[node]=true;
        cout<<node<<" ";
        for(int i:adjList[node]){
            if(!visited[i]) DFS(i);
        }
    }
    void BFS(){
        if(q.empty())return;
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i:adjList[node]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
        BFS();
    }
};
int main(){
    Suraj g;
    g.addEdges(0,1);
    g.addEdges(0,2);
    g.addEdges(1,3);
    g.addEdges(1,4);
    int a;
    cout<<"Enter 0 for DFS and Enter any number for BFS ";
    cin>>a;
    if(!a){
        cout<<"The DFS of the given graph is ";
        g.DFS(0);
    }
    else{
        cout<<"The BFS of the given graph is ";
        g.q.push(0);
        g.visited[0]=true;
        g.BFS();
    }
    return 0;
    
}