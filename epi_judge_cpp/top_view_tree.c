#include <iostream>  
#include<queue>  
#include<map> 
using namespace std; 
  
// Structure of binary tree 
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 
}; 
  
// function to create a new node 
Node* newNode(int key) 
{ 
    Node* node=new Node(); 
    node->left = node->right = NULL; 
    node->data=key; 
    return node; 
} 
void leftview(Node * root )
{
  queue<Node * > q;
  map<int,int> m;
  root->hd = 0;
  int hd1;
  q.push(root);
  Node * temp;
  while(q.size()) {
    temp = q.front();
    q.pop();
    hd1 = temp->hd;
    if(temp!=NULL) {
      if(m.count(hd1) == 0) {
        m[hd1] = temp->data;
      }
      if(temp->left) {
        temp->left->hd = hd1 + 1;
        q.push(temp->left);
      }
      if(temp->right) {
        temp->right->hd = hd1 + 1;
        q.push(temp->right);
      }
    }
  }
  for(auto i = m.begin(); i!= m.end(); i++) {
    cout <<i->second<<" ";
  }
} 
 
void rightview(Node * root )
{
  queue<Node * > q;
  map<int,int> m;
  root->hd = 0;
  int hd1;
  q.push(root);
  Node * temp;
  while(q.size()) {
    temp = q.front();
    q.pop();
    hd1 = temp->hd;
    if(temp!=NULL) {
      if(m.count(hd1) == 0) {
        m[hd1] = temp->data;
      }
      if(temp->right) {
        temp->right->hd = hd1 + 1;
        q.push(temp->right);
      }
      if(temp->left) {
        temp->left->hd = hd1 + 1;
        q.push(temp->left);
      }
    }
  }
  for(auto i = m.begin(); i!= m.end(); i++) {
    cout <<i->second<<" ";
  }
} 
 
// function should print the topView of 
// the binary tree 
void topview(Node* root) 
{ 
  queue<Node * > q;
  map<int,int> m;
  int hd1 = 0;
  int sum = 0;
  root->hd = 0;
  q.push(root);
  Node * temp;
  while(q.size()) {
    temp = q.front();
    q.pop();
    hd1 = temp->hd;
    if(temp!=NULL) {
      if(m.count(hd1) == 0) {
        m[hd1] = temp->data;
      }
      if(temp->left) {
        temp->left->hd = hd1 - 1;
        q.push(temp->left);
      }
      if(temp->right) {
        temp->right->hd = hd1 + 1;
        q.push(temp->right);
      }
    }
  }
  for(auto i = m.begin(); i!= m.end(); i++) {
    cout <<i->second<<" ";
  }
} 
   
// Driver Program to test above functions 
int main() 
{ 
   Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 
    cout<<"Following are nodes in LEFT view of Binary Tree\n";  
    leftview(root); 
    cout<<"Following are nodes in RIGHT view of Binary Tree\n";  
    rightview(root); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    topview(root); 
    return 0; 
} 
/* This code is contributed by Niteesh Kumar */
