/// Undirected graph

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

 void create(vector<vector<int>>&adj,int x,int y){
    adj[x][y]=1;
    adj[y][x]=1;

}

void printAdjacencyMatrix(vector<vector<int>>&adj,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[0].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void createList(vector<int>graphList[],int x,int y){
    graphList[x].push_back(y);
    graphList[y].push_back(x);

}

void printList(vector<int>graphList[],int n){
    for(int i=0;i<n;i++){
        cout<<i<<"  --> ";
        for(auto x: graphList[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

void BFS(vector<int>graphList[],int n){
    queue<int>q;
    int vis[n]={0};
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto x:graphList[node]){
            if(!vis[x]){
                vis[x]=1;
                q.push(x);
            }
        }
    }

}

bool visited_dfs[100];

void dfs(vector<int>graphList[],int node){
    visited_dfs[node]=true;
    //pre-order
    // cout<<node<<" ";

    for(auto x:graphList[node]){
        if(!visited_dfs[x]){
            dfs(graphList,x);
        }
    }

    //post-order
     cout<<node<<" ";
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n,0));
    vector<int>graphList[n];
    int m,x,y;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        create(adj,x,y);
        createList(graphList,x,y);
    }
   // create(adj,0,1);
    //printAdjacencyMatrix(adj,n);
    printList(graphList,n);
    cout<<endl;
    BFS(graphList,n);
    cout<<endl;
    dfs(graphList,0);

    return 0;
}