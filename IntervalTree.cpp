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

bool doOverlap(interval range1, interval range2){
  if(range1.low <= range2.high && range2.low <= range1.high)
    return true;
  return false;
}

interval* overlap(node* root, interval range){
  if(root == NULL){
    return NULL
  }
  if(doOverlap(*(root->i), range))
    return root;
  if(root->left != NULL && root->left->max >= range.low)
    overlap(root->left, range);
  return overlap(root->right, range);
}

int main(){
  return 0;
}
