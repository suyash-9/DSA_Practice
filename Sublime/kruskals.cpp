#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e5;


vector<int>parent(N);
vector<int>size(N);

//DSU
void make(int a){
	parent[a]=a;
	size[a]=1;
}

int find(int a){
	if(parent[a]==a)return a;
	return parent[a]=find(parent[a]);
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(size[a]<size[b]){
		swap(a,b);
	}
	parent[b]=a;
	size[a]+=size[b];
}


void kruskals(vector<vector<int>>&edges){
	int cost=0;

	sort(edges.begin(), edges.end());
	for(auto element:edges){
		int x=element[1];
		int y=element[2];
		int wt=element[0];
		if(find(x)!=find(y)){
			Union(x,y);
			cost+=wt;
			cout<<x<<" ---- "<<y<<'\n';
		}
	}
	cout<<"Cost = "<<cost<<"\n";
}

int main(){
    fastIO();

    int v,e;
    cin>>v>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
    	int x,y,wt;
    	cin>>x>>y>>wt;
    	edges.push_back({wt,x,y});
    }
    for(auto element:edges){
    	int x=element[1];
    	int y=element[2];
    	make(x);
    	make(y);
    }
    kruskals(edges);

       
    return 0;
}