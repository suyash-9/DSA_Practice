#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();
    
   ll n;
   cin>>n;
   ll arr[n];
   for(ll i=0;i<n;i++){
       cin>>arr[i];
   }
   ll s=0,e=n-1;
   ll ans=0;
   bool flag=false;
   while(e>=s){
       if(arr[s]!=arr[e]){
           flag=true;
           break;
       }
       s++;
       e--;
   }
   if(flag){
       cout<<"NO"<<endl;
   }
   else cout<<"YES"<<endl;
   
       
    return 0;
}