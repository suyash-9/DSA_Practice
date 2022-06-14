#include <bits/stdc++.h>
using namespace std;

struct lists{
    int size;
    int* arr;
    int currsize=0;

    lists(int n){
        size=n;
        arr=new int[n];
    }

    bool isFull(){
        if(currsize==size)return true;
        else return false;
    }

    bool isEmpty(){
        if(currsize==0)return true;
        else return false;
    }

    void insert(int x){
        if(isFull()){
            cout<<"List is Full"<<endl;
            return;
        }
        arr[currsize]=x;
        currsize++;
        return;
    }

    void insertat(int x,int pos){
        if(isFull()){
            cout<<"List is Full"<<endl;
            return;
        }
        if(pos==size-1) {
            arr[size-1]=x;
            currsize++;
            return;
            }
        for(int i=currsize;i>=pos;i--){
            arr[i+1]=arr[i];
        }
        arr[pos]=x;
        currsize++;
        return;
    }

    void print(){
        for(int i=0;i<currsize;i++){
            cout<<arr[i]<<" ";
        }
    }

    void remove(){
        if(isEmpty()){
            cout<<"No element to delete"<<endl;
            return;
        }
        currsize--;
    }

    void removeat(int pos){
        if(isEmpty()){
            cout<<"No element to delete"<<endl;
            return;
        }
        for(int i=pos;i<currsize-1;i++){
            arr[i]=arr[i+1];
        }
        currsize--;
        return;
    }
    
    int search(int value){
        for(int i=0;i<currsize;i++){
            if(arr[i]==value) return i;
        }
        
        return -1;
    }
    
    bool identify(int value){
        if(value>=2021 && value<=2030) return true;
        return false;
    }
    
    



};

int main(){
    lists l(10);
    l.insert(2022);
    l.insert(2023);
    l.insert(2024);
    l.insert(2025);
    l.insert(2026);
    l.insert(2021);
    l.insert(2030);
    l.insert(2023);
    l.insert(2024);
    l.insert(2025);
    cout<<"The elements of the list are :"<<endl;
    l.print();
    
    
    
    //1
    l.removeat(5);
    cout<<endl<<endl<<"The results after identifying the 6th element as expired. "<<endl;
    l.print();
    
    
    //2
    int pos=l.search(2030);
    l.removeat(pos);
    l.insert(2031);
     cout<<endl<<endl<<"The results after identifying the 2030 as expired. "<<endl;
    l.print();
    
    //3
    int pos1=l.search(2021);
    l.removeat(pos1);
     cout<<endl<<endl<<"The results after deleting the value with 2021 as expired. "<<endl;
    l.print();
    l.insertat(2031,pos1);
     cout<<endl<<endl<<"The results after replacing the 2021 . "<<endl;
    l.print();
        
    
    
    
    
   

    return 0;
}
