#include <bits/stdc++.h>
 
using namespace std;

struct node{

    int data;
    node* next;
    node* prev;

    node(int x){
        data=x;
        next=NULL;
        

    }

};

void insert(node* &head,int x){
        node* p=head;
        if(head==NULL){
            head=new node(x);
            head->prev=NULL;
        }
        else{
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=new node(x);
            p->next->prev=p;
        }
        return;
    }

void insertAt(node* &head,int x,int pos){
        node* p=head;
        int i=0;
        while(i!=pos-1 && p!=NULL){
            p=p->next;
            i++;
        }
        node* temp=new node(x);
        temp->next=p->next;
        p->next=temp;
        temp->prev=p;
        temp->next->prev=temp;
        return;

}

node* removeAtEnd(node* &head){
    node* p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    node* temp=p->next;
    p->next=NULL;
   
    free(temp);
    return head;
}

node* removeAtStart(node* &head){
    node* p=head;
    head=head->next;
    head->prev=NULL;
    
    free(p);
    return head;
}

node* removeAt(node* &head,int pos){
    node* p=head;
    int i=0;
    while(i!=pos-1 && p!=NULL){
        p=p->next;
        i++;
    }
    node* temp=p->next;
    p->next=temp->next;
    temp->next->prev=p;

    free(temp);
    return head;
}

node* removeVal(node* &head,int x){
    node* p=head;
    while(p->next->data!=x && p!=NULL){
        p=p->next;
    }
    node* temp=p->next;
    p->next=temp->next;
    temp->next->prev=p;

    free(temp);
    return head;
}


void printList(node* head){
    cout<<"Printing items of list :"<<endl;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}
void revprintList(node* head){
    cout<<"Printing items of list in reverse :"<<endl;
    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->prev;
    }
    cout<<endl;
    return;
}


int main(){
    node* head=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    insert(head,60);
    insert(head,70);
    insert(head,80);
    insert(head,90);
    printList(head);
    revprintList(head);
    return 0;
}