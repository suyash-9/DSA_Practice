#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();

    
  vector<ll>v1={1,2,3};
  vector<ll>v2={1,1,2};
  vector<vector<ll>>v={{1,1,3},{1,1,1}};
  sort(v.begin(),v.end());
  for(auto x:v){
    for(auto y:x)cout<<y<<" ";
        cout<<"\n";
  }

       
    return 0;
  
  
}