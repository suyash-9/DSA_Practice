#include <iostream>
using namespace std;

typedef long long int ll;

class queue{
    int *arr;
    int size;
    int front ,end;

    public:
    queue(int n){
        size=n;
        arr=new int[n];
        front =-1;
        end=-1;
    }

    bool isFull(){
        if(end==size-1)return true;
        else return false;
    }

    bool isEmpty(){
        if(front==-1|| end==-1|| front==size-1||front>end)return true;
        else return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<" Queue is Full."<<endl;
            return;
        }
        if(front==-1 && end==-1){
            front++;
            end++;
        }
        else{
            end++;
        }
        arr[end]=x;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        front++;
    }

    int frontpeek(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[front];

    }
};

int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
     q.enqueue(3);
      q.enqueue(4);
       q.enqueue(5);
       q.dequeue();
    cout<<q.frontpeek();
    return 0;
}