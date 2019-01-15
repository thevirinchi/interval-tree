#include <bits/stdc++.h>
using namespace std;

struct interval{
  int l, h;
};

struct node{
  interval * i;
  int max;
  node* left, right;
};

node* newNode(interval range){
  node* temp = new node;
  temp->i = new interval(range);
  temp->max = range.high;
  temp->left = temp->right = NULL;
}

node* insert(node* root, interval range){
  if(root == NULL)
    return newNode(i);
  int low = root->i->l;
  if(range.low < l)
    root->left = insert(root->left, range);
  else
    root->right = insert(root->right, range);
  if(root->max < range.high)
    root->max = range.high;
  return root;
}

int main(){
  return 0;
}
