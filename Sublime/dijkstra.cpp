#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e5+10;
const int inf=1e9+9;

/*
	Here for g[a]={b,wt} it represents :
										for node 'a' it is connected to node 'b' with weight = wt
*/
vector<pair<int,int>>g[N];

void dijkstra(int source,int v,int e){
	vector<int>vis(N,0);
	vector<int>dis(N,inf);

/*
	Here for set the first member of pair is weight and second member is the node 
*/
	set<pair<int ,int>>st;
	st.insert({0,source});
	dis[source]=0;
	while(st.size()>0){
		auto node=*st.begin();
		int wt_parent=node.first;
		int parent=node.second;
		st.erase(st.begin());
		if(vis[parent]==1)continue;
		vis[parent]=1;
		for(auto child:g[parent]){
			int child_v=child.first;
			int child_wt=child.second;

			// Here dis[i] stores latest istance from sourde to a node 'i' .
			int new_distance=dis[parent]+child_wt;
			if(new_distance<dis[child_v]){
				dis[child_v]=new_distance;
				st.insert({dis[child_v],child_v});
			}

		}
	}
	int mn=INT_MAX;
	for(int i=1;i<=v;i++){
		if(mn>dis[i])cout<<i<<"\n";
		mn=min(mn,dis[i]);
	}
	cout<<mn;

}

int main(){
    fastIO();

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
    	int x,y,wt;
    	cin>>x>>y>>wt;
    	g[x].push_back({y,wt});
    }
    dijkstra(1,v,e);

    

       
    return 0;
}