#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int>adj[1001];
int indegree[1001];
int dis[1001];

void addEdge(int x,int y){
    
        adj[x].push_back(y);
        indegree[y]++;
    
}



void bfs(int n,int m){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            dis[i]=1;
            
        }
    }
	int distance=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		
		for(auto x:adj[node]){
			indegree[x]--;
            if(indegree[x]==0){
                dis[x]=dis[node]+1;
                q.push(x);
            }
		}

	}
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return;
}

int main(){
    fastIO();
    //n=vertices && m=m=edges	
    int n,m;
    cin>>n>>m;
    //n=10 m=13

    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
    
    
    
    bfs(n,m);




    
       
    return 0;
}