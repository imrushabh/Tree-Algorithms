/*
  Author:-Rushabh Gaherwar
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;

  node(int data)
  {
    this->data=data;
    left=NULL;
    right=NULL;
  }
};


bool isIdentical(struct node* n1,struct node* n2)
{
  if(!n1 && !n2)return true;
  if(!n1 && !n2)return false;

  queue<node *> q1, q2;

  q1.push(n1);
  q2.push(n2);

  while(!q1.empty() && !q2.empty())
  {
    node* l1=q1.front();
    node* l2=q2.front();

    if (l1->data != l2->data) 
           return false; 
    q1.pop(), q2.pop(); 

    if (l1->left && l2->left) 
    { 
        q1.push(l1->left); 
        q2.push(l2->left); 
    } 
    else if(l1->left || l2->left)
            return false;
    if (l1->right && l2->right) 
    { 
        q1.push(l1->right); 
        q2.push(l2->right); 
    } 
    else if (l1->right || l2->right) 
            return false; 
  } 
  
  return true; 
  
}

int main() {

  struct node* root1=new node(1);
  struct node* root2=new node(2);
  struct node* root3=new node(3);
  struct node* root4=new node(4);
  struct node* root5=new node(5);
  root1->left=root2;
  root1->right=root3;
  root2->left=root4;
  root2->right=root5;
  
  struct node* root11=new node(1);
  struct node* root21=new node(2);
  struct node* root31=new node(3);
  struct node* root41=new node(4);
  struct node* root51=new node(5);
  root11->left=root21;
  root11->right=root31;
  root21->left=root41;
  root21->right=root51;
  
  cout<<isIdentical(root1,root11);

}
