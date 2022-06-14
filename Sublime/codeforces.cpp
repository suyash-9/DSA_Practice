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
    	ll n;
    	cin>>n;
    	vector<ll>arr(n);
    	for(auto &x:arr)cin>>x;
    		sort(arr.begin(),arr.end());
    	set<ll>st;
    	for(auto &x:arr){
    		st.insert(x);
    	}
    	if(st.size()<=2){
    		cout<<"NO\n";
    	}
    	else{
    		cout<<"YES\n";
    		vector<ll>left,right;
    		ll s=0,e=n-1;
    		while(e>s){
    			left.push_back(arr[s]);
    			s++;
    			right.push_back(arr[e]);
    			e--;
    		}
    		if(n%2)left.push_back(arr[s]);
    		sort(right.begin(),right.end());
    		for(ll i=0;i<right.size();i++){
    			cout<<left[i]<<" "<<right[i]<<" ";
    		}
    		if(n%2){
    			cout<<left[left.size()-1];
    		}
    	

    		cout<<"\n";
    	}

        
    	

    	
       
    }
       
    return 0;
}