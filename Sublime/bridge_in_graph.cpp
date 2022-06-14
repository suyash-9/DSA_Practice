#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int>adj[101];
vector<int>vis(101),in(101),low(101);
int timer=0;

void dfs(int node,int parent){
	vis[node]=1;
	low[node]=timer;
	in[node]=timer;
	timer++;
	for(auto child:adj[node]){
		if(child==parent)continue;
		if(vis[child]==1){
			//back edge present
			low[node]=min(low[node],in[child]);
		}
		else{
			dfs(child,node);
			if(low[child]>in[node]){
				cout<<child<<"--"<<node<<" is a Bridge. \n";
			}
			low[node]=min(low[node],low[child]);
		}

	}
}

int main(){
    fastIO();

    int n,m;
    //n= Vertices and m=Edges
    cin>>n>>m;
    while(m--){
    	int x,y;
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    dfs(1,-1);


    
    
       
    return 0;
}