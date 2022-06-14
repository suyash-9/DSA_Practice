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
        if((b-a)%x==0 && b>=a){
            cout<<(b-a)/x<<endl;
        }
        else cout<<-1<<endl;
       
    }
       
    return 0;
}