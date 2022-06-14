#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N=1000;
const int inf=1e9+9;

int dp[N][N];

int main(){
    fastIO();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=N;i++){
    	for(int j=0;j<=N;j++){
    		if(i==j)dp[i][j]=0;
    		else dp[i][j]=inf;
    	}
    }
    for(int i=0;i<m;i++){
    	int x,y,wt;
    	cin>>x>>y>>wt;
    	dp[x][y]=wt;
    }
    for(int k=1;k<=n;k++){
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    		}
    	}
    }

    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		if(dp[i][j]==inf){
    			cout<<"I"<<" ";
    		}
    		else cout<<dp[i][j]<<" ";
    	}
    	cout<<"\n";
    }


    //This is extra to find negative edge cycle
    bool f=false;
    for(int i=0;i<=n;i++){
        
            if(dp[i][i]<0){
                cout<<"The graph has a negative edge cycle.";
                f=true;
                break;
            }
        
    }

    
   
       
    return 0;
}