#include <bits/stdc++.h>
 
using namespace std;
 typedef long long int ll;
 

struct Stacks{
    int size;
    int currsize;
    queue<int>q;

    Stacks(int n){
        size=n;
        currsize=0;
    }

    bool isFull(){
        return (currsize==size);
    }

    bool isEmpty(){
        return (currsize==0);
    }

   void push(int x){
       if(isFull()){
           cout<<"Stack Overflow"<<endl;
           return;
       }
       q.push(x);
        currsize++;
       return;
   }

   int pop(){
       if(isEmpty()){
           cout<<"No element to delete."<<endl;
           return -1;
       }
       int n=q.size();
       for(int i=0;i<n-1;i++){
           int a=q.front();
           q.pop();
           q.push(a);
       }
       int a=q.front();
       q.pop();
       currsize--;

       return a;

   }

   int top(){
       if(isEmpty()){
           cout<<"No element to delete."<<endl;
           return -1;
       }
       int n=q.size();
       for(int i=0;i<n-1;i++){
           int a=q.front();
           q.pop();
           q.push(a);
       }
       int a=q.front();
       q.pop();
       q.push(a);
       return a;
   }

   void insertAtBottom(Stacks st,int x){
        if(st.currsize==0){
            st.push(x);
        }
        else{
            int a=st.top();
            st.pop();
            insertAtBottom(st,x);
            st.push(a);
        }
    }

    void reverse(Stacks &st){
        if(st.currsize>0){
            int x=st.top();
            st.pop();
            reverse(st);
            insertAtBottom(st,x);
        }
        return ;

    }
    void print(Stacks &st){
        Stacks s1(st.currsize);
        while(!st.isEmpty()){
            int x=st.pop();
            cout<<x<<" ";
            s1.push(x);
        }
        while(!s1.isEmpty()){
             int x=s1.pop();
            st.push(x);
        }


    }
};


 
int main(){
    Stacks s(5);
    s.push(1);
    s.push(2);
   s.push(3);
   s.push(4);
   //s.print(s);
   s.reverse(s);
   cout<<endl;
   s.print(s);
   
       
    return 0;
}