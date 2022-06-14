#include <bits/stdc++.h>
 
using namespace std;

struct node{

    int coeff;
    int pow;
    node* next;

    node(int x,int y){
         coeff=x;
         pow=y;
        next=NULL;
    }

};

node* insert(node* head,int x,int y){
    node* p=head;
    if(p==NULL){
        head=new node(x,y);
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new node(x,y);
    }
    return head;
}

node* print(node* head){
    node* p=head;
    while(p!=NULL){
        if(p->pow==0){
            cout<<p->coeff<<" ";
        }
        else{
            cout<<p->coeff<<"x"<<p->pow<<" + ";
        }
        p=p->next;
    }
    return head;
}

node* add(node* poly1,node* poly2,node* poly3){
    node* p=poly1;
    node* q=poly2;
    while(p!=NULL && q!=NULL){
        if(p->pow==q->pow){
            poly3=insert(poly3,p->coeff+q->coeff,p->pow);
            p=p->next;
            q=q->next;
        }
        else{
            if(p->pow>q->pow){
                poly3=insert(poly3,p->coeff,p->pow);
                p=p->next;
            }
            else{
                poly3=insert(poly3,q->coeff,q->pow);
                q=q->next;
            }
        }
    }
    if(p!=NULL && q==NULL){
        while(p!=NULL){
            poly3=insert(poly3,p->coeff,p->pow);
            p=p->next;
        }
    }
    else if(p==NULL && q!=NULL){
         while(q!=NULL){
            poly3=insert(poly3,q->coeff,q->pow);
            q=q->next;
        }
    }
    return poly3;
}


int main(){
    node* poly1=NULL;
    poly1=insert(poly1,5,4);
    poly1=insert(poly1,3,2);
    poly1=insert(poly1,1,0);
    cout<<"The First Polynomial is : "<<endl;
    poly1=print(poly1);
    cout<<endl<<endl<<"The Second Polynomial is : "<<endl;
    node* poly2=NULL;
    poly2=insert(poly2,4,3);
    poly2=insert(poly2,2,1);
    poly2=insert(poly2,2,0);
    poly2=print(poly2);
    node* poly3=NULL;
    poly3=add(poly1,poly2,poly3);
    cout<<endl<<endl<<"The addition of above two polynomials is :"<<endl;
    poly3=print(poly3);

   
    return 0;
}