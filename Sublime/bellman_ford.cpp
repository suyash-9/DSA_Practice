#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int inf=1e6;

int main(){
    fastIO();
    int v,e;
    cin>>v>>e;
    vector<int>dis(v,inf);
    dis[0]=0;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        edges.push_back({src,dest,wt});
    }

    for(int i=0;i<v-1;i++){
        for(auto e:edges){
            // For edge x--y we minimize the dis[y]
            int x=e[0];
            int y=e[1];
            int wt=e[2];
            dis[y]=min(dis[y],wt+dis[x]);
        }
    }

    //This is extra step to find negative cycle
    bool f=false;
       for(int i=0;i<v;i++){
        for(auto e:edges){
            int x=e[0];
            int y=e[1];
            int wt=e[2];
            if(dis[x]+wt<dis[y]){
                f=true;
                break;
            }
        }
        
    }
    if(f){
        cout<<"Graph contains negative cyle.\n";
    }

    for(auto &x:dis){
        if(x==inf)cout<<-1<<" ";
        else
        cout<<x<<" ";
    }

    

       
    return 0;
}

/*
    Input -
    5 8
    0 1 -1
    0 2 4
    1 2 3
    3 2 5
    1 3 2
    3 1 1
    4 3 -3
    1 4 2

*/