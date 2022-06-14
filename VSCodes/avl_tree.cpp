#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
    
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
        height=1;
    } 
};

int getHeight(struct node* root){
    if(root==NULL)return 0;
    return root->height;
}

int getBalance(struct node* root){
    if(root==NULL)return 0;
    return getHeight(root->left)-getHeight(root->right);
}


struct node* rightRotate(struct node* y){
/*                                   y                                                      x
                                    / \                                                    / \
                                   x   t3                ------->                         t1  y                        
                                  / \           Right rotate w.r.t  y                        / \
                                 t1  t2                                                     t2  t3
*/
  
  struct node* x=y->left;
  struct node* t2=x->right;

  x->right=y;
  y->left=t2;

  x->height=max(getHeight(x->left),getHeight(x->right))+1;
  y->height=max(getHeight(y->left),getHeight(y->right))+1;
  return x;


}

struct node* leftRotate(struct node* x){
/*                                   x                                                      y
                                    / \                                                    / \
                                   t1  y                ------->                          x   t3                        
                                      / \           Left rotate w.r.t  x                 / \   
                                     t2  t3                                             t1  t2  
*/
  
  struct node* y=x->right;
  struct node* t2=y->left;

  y->left=x;
  x->right=t2;

  x->height=max(getHeight(x->left),getHeight(x->right))+1;
  y->height=max(getHeight(y->left),getHeight(y->right))+1;
  return y;


}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else   return root;
     root->height=max(getHeight(root->left),getHeight(root->right))+1;
    int bf=getBalance(root);

    // Left-Left Case
    if(bf>1 && val<root->left->data){
        return rightRotate(root);
    }

    //Right-Right Case
    if(bf<-1 && val>root->right->data){
       return leftRotate(root);
    }

    //Left-Right Case
    if(bf>1 && val>root->right->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    //right-Left Case
    if(bf<-1 && val<root->left->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(struct node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct node* root=NULL; 
    root= insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    preorder(root);

    return 0;
}


