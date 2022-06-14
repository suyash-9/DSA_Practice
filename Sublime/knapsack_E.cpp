#include <bits/stdc++.h>
 
using namespace std;
 typedef long long int ll;

 const long long inf=1e18;
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll w[101];ll v[101];
ll dp[100][100007];
int main(){
    fastIO();
    
   ll n,W;
   cin>>n>>W;
    for(ll i=0;i<100;i++){
    for(ll j=0;i<=100000;j++){
        dp[i][j]=inf;
    }
   }
   
   for(ll i=0;i<n;i++){
       cin>>w[i]>>v[i];
   }

  
   
   dp[0][0]=0;
   dp[0][v[0]]=w[0];
   for(int i=1;i<n;i++){
       dp[i][0]=0;
       for(ll j=1;j<=100000;j++){
           //not including
           dp[i][j]=dp[i-1][j];
           
           //including
           if(j>=v[i])
           dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
       }
   }
   ll ans;
  for(ll i=100000;i>=0;i--){
    if(dp[n-1][i]<=W){
        ans=i;
    }
  }
   cout<<ans;
       
    return 0;
}