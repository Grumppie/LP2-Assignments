#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   int data;
   node* left;
   node* right;
   
   node(int data){
   	this->data = data;
   	this->left = NULL;
   	this->right = NULL;
   }
};

node* buildTree(node* root){
   int data;
   cout<<"Enter data for node : ";
   cin>>data;
   
   if(data == -1){
      return NULL;
   }
   
   root = new node(data);
   
   cout<<"Enter data for left child of node "<<data<<endl;
   root->left = buildTree(root->left);
   
   cout<<"Enter data for right child of node "<<data<<endl;
   root->right = buildTree(root->right);
   
   return root;
   
 }
 
void dfs(node *root){
    if(root == NULL){
       return;
    }
    
    dfs(root->left);
    cout<<root->data<<" ";
    dfs(root->right);
}

void bfs(node *root){
   if(root == NULL){
      return;
   }
   
   queue<node*> q;
   q.push(root);
   
   while(!q.empty()){
      node* front = q.front();
      q.pop();
      
      cout<<front->data<<" ";
      if(front->left){
         q.push(front->left);
      }
      if(front->right){
         q.push(front->right);
      }
   }
}
      
   
   
int main(){
   node* root = NULL;
   root = buildTree(root);
   
   cout<<"DFS Traversal : ";
   dfs(root);
   
   cout<<endl;
   
   cout<<"BFS Traversal : ";
   bfs(root);
   
   map<int,int> m;


   return 0;
}