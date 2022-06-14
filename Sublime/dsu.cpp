#include <bits/stdc++.h>

using namespace std;
 typedef long long int ll;


 #define N 200001

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int>parent(N);
vector<int>size(N);

//makes new parent node/ parent of a group
void make(int a){
    parent[a]=a;
    size[a]=1;
}

//find the parent of agroup
int find(int a){
    if(parent[a]==a)return a;

    //Path compression
    return parent[a]=find(parent[a]);
}


//merges two groups
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        //Union by size 
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
        
    }
}

int main(){
    fastIO();
    ll n=4;
    //cin>>n;
 
    make(1);
    make(2);
    make(3);
    Union(2,3);

    cout<<find(3);

       
    return 0;
}