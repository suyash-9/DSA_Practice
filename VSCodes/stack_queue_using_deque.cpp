#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class stacks{
    public:
    deque<int>q;

    void push(int x){
        q.push_back(x);
    }

    void pop(){
        if(q.empty()){
            cout<<" Stack is empty."<<endl;
            return;
        }
        q.pop_back();
    }

    int top(){
        if(q.empty())return -1;
        else return q.back();
    }

};

class queues{
    deque<int>q;
    public:
    void enqueue(int x){
        q.push_back(x);
    }
    void dequeue(){
        if(q.empty()){
            cout<<" Queue is empty."<<endl;
            return;
        }
        q.pop_front();
    }

    int front(){
         if(q.empty())return -1;
        else return q.front();
    }
};

int main(){
    stacks st;
    st.push(1);
    st.push(2);
    st.pop();
    cout<<st.top()<<endl;

    queues q;
    q.enqueue(0);
    q.enqueue(-1);
    q.dequeue();
    cout<<q.front()<<endl;

    return 0;
}
