#include <bits/stdc++.h>
using namespace std;
 typedef long long int ll;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();
    
    ll t;
    cin>>t;
    while(t--){
        ll a,b,x;
        cin>>a>>b>>x;
        ll ans=0;
        while(b!=a && a<=b){
            a+=x;
            ans++;
        }
        if(a==b) cout<<ans<<endl;
        else cout<<-1<<endl;
       
    }
       
    return 0;
}