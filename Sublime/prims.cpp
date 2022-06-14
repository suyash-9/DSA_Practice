#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e5;
const int inf=1e9;

vector<pair<int,int>>adj[N];
vector<int>parent(N,-1);
vector<int>mst(N,0);
vector<int>dis(N,inf);

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

void prims(int src){
	
	dis[src]=0;
	q.push({0,src});
	while(!q.empty()){
		auto node=q.top();
		int u=node.second;
		int wt=node.first;
		q.pop();
		if(mst[u])continue;
		mst[u]=1;
		for(auto x:adj[u]){
			int v=x.second;
			int w=x.first;
			if(mst[v]==0 && dis[v]>w){
				dis[v]=w;
				q.push({dis[v],v});
				parent[v]=u;
			}
		}
	}
	

}

int main(){
    fastIO();

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
    	int x,y,wt;
    	cin>>x>>y>>wt;
    	adj[x].push_back({wt,y});
    	adj[y].push_back({wt,x});
    }
    prims(0);
    int cost=0;
    for(int i=1;i<v;i++){
    	cost+=dis[i];
    	cout<<parent[i]<<" "<<i<<"\n";
    }
    cout<<"cost = "<<cost<<"\n";

    
  
       
    return 0;
}