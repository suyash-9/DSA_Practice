#include <iostream>
using namespace std;

typedef long long int ll;

class stack{
    public:
    int *arr;
    int top;
    int size;
    
    stack(int n){
        arr=new int[n];
        size=n;
        top=-1;
    }

    bool isFull(){
        if(top==size-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
        return;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty , Nothing to pop."<<endl;
            return -1;
        }
        int a=arr[top];
        top--;
        return a;
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack is Empty "<<endl;
            return ;
        }
        cout<<arr[top];
    }

    void insertAtBottom(stack st,int x){
        if(st.size==0){
            st.push(x);
        }
        else{
            int a=st.top;
            st.pop();
            insertAtBottom(st,x);
            st.push(a);
        }
    }

    void reverse(stack st){
        if(st.size>0){
            int x=st.top;
            st.pop();
            reverse(st);
            insertAtBottom(st,x);
        }

    }

    void print(stack st){
        while(!st.isEmpty()){
            cout<<st.top<<" ";
            st.pop();
        }
        cout<<endl;
    }
    

};

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // s.print(s);
    // s.reverse(s);
    //  s.print(s);


    return 0;
}
