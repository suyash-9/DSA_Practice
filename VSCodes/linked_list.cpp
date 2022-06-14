#include <bits/stdc++.h>
 
using namespace std;
 typedef long long int ll;

  bool isEmpty(struct node* head){
         if(head==NULL) return true;
         return false;
  }

 struct node{
     int regd_no;
     string name;
     string branch;
     int marks;
     struct node* next;

     node(int r,string n,string b,int m){
         regd_no=r;
         name=n;
         branch=b;
         marks=m;
         next=NULL;
     }

     struct node* insert(struct node* head,int r,string n,string b,int m){
          struct node* p=head;
          if(head==NULL){
              head=new node(r,n,b,m);
          }
          else{
              while(p->next!=NULL){
              p=p->next;
          }
          p->next=new node(r,n,b,m);
          }
          return head;

      }

      struct node* insert_at_start(struct node* head,int r,string n,string b,int m){
          struct node* p=new node(r,n,b,m);
          
          p->next=head;
          head=p;
        
          return head;

      }

      struct node* make_circular(struct node* head){
          struct node* p=head;
          if(isEmpty(head)){
              cout<<"Empty List"<<endl;
          }
          while(p->next!=NULL){
              p=p->next;
          }
          p->next=head;
          return head;

      }
    

 };

  

       

 void printlist(struct node* head){
          if(isEmpty(head)){
              cout<<"Empty List"<<endl;
          }
          cout<<"Regd. No.   Name  Branch   marks"<<endl;
          while(head!=NULL){
              cout<<head->regd_no<<"        "<<head->name<<"    "<<head->branch<<"      "<<head->marks<<endl;
              head=head->next;
          }
      }

     

 int main(){
      struct node* head_topper=NULL;
     head_topper=head_topper->insert(head_topper,4003,"SSS","MECH",95);
     head_topper=head_topper->insert(head_topper,3001,"KKK","EEE",91);
     head_topper=head_topper->insert(head_topper,4001,"QQQ","MECH",92);
     head_topper=head_topper->insert(head_topper,3002,"GGG","LLL",89);
     head_topper=head_topper->insert(head_topper,4001,"QQQ","MECH",92);

     struct node* head_cse=NULL;
     head_cse=head_cse->insert(head_cse,1001,"AAA","CSE",94);
     head_cse=head_cse->insert(head_cse,1002,"BBB","CSE",91);
     head_cse=head_cse->insert(head_cse,1003,"CCC","CSE",75);
     head_cse=head_cse->insert(head_cse,1004,"DDD","CSE",89);
     head_cse=head_cse->insert(head_cse,1005,"EEE","CSE",69);
     

     struct node* head_ece=NULL;
     head_ece=head_ece->insert(head_ece,2001,"FFF","ECE",72);
     head_ece=head_ece->insert(head_ece,2002,"GGG","ECE",89);
     head_ece=head_ece->insert(head_ece,2003,"HHH","ECE",75);
     head_ece=head_ece->insert(head_ece,2004,"III","ECE",76);
     head_ece=head_ece->insert(head_ece,2005,"JJJ","ECE",58);

      struct node* head_eee=NULL;
     head_eee=head_eee->insert(head_eee,3001,"KKK","EEE",91);
     head_eee=head_eee->insert(head_eee,3002,"GGG","LLL",89);
     head_eee=head_eee->insert(head_eee,3003,"MMM","EEE",75);
     head_eee=head_eee->insert(head_eee,3004,"NNN","EEE",76);
     head_eee=head_eee->insert(head_eee,3005,"OOO","EEE",58);

     struct node* head_mech=NULL;
     head_mech=head_mech->insert(head_mech,4001,"QQQ","MECH",92);
     head_mech=head_mech->insert(head_mech,4002,"RRR","MECH",89);
     head_mech=head_mech->insert(head_mech,4003,"SSS","MECH",95);
     head_mech=head_mech->insert(head_mech,4004,"TTT","MECH",66);
     head_mech=head_mech->insert(head_mech,4005,"UUU","MECH",78);

    printlist(head_topper);
    cout<<endl;

    printlist(head_cse);
    cout<<endl;

    printlist(head_ece);
    cout<<endl;

    printlist(head_eee);
    cout<<endl;

    printlist(head_mech);
    cout<<endl;
 
   //Implemented function to make lists circular

     head_cse=head_cse->make_circular(head_cse);
    head_ece=head_cse->make_circular(head_ece);








     return 0;
 }

 