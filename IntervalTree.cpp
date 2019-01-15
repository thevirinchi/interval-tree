#include <bits/stdc++.h>
using namespace std;

struct interval{
  int l, h;
};

struct node{
  interval * i;
  int max;
  node* left;
  node* right;
};

node* newNode(interval range){
  node* temp = new node;
  temp->i = new interval(range);
  temp->max = range.h;
  temp->left = temp->right = NULL;
}

node* insert(node* root, interval range){
  if(root == NULL)
    return newNode(range);
  int low = root->i->l;
  if(range.l < root->max)
    root->left = insert(root->left, range);
  else
    root->right = insert(root->right, range);
  if(root->max < range.h)
    root->max = range.h;
  return root;
}

bool doOverlap(interval range1, interval range2){
  if(range1.l <= range2.h && range2.l <= range1.h)
    return true;
  return false;
}

interval* overlap(node* root, interval range){
  if(root == NULL){
    return NULL;
  }
  if(doOverlap(*(root->i), range))
    return root->i;
  if(root->left != NULL && root->left->max >= range.l)
    overlap(root->left, range);
  return overlap(root->right, range);
}

int main(){
  int ranges[] = {{0,9}, {10,19}, {20, 29}, {30, 39}, {40, 49}};
  node* root = NULL;
  int n = sizeof(ranges)/sizeof(ranges[0]);
  for(int i = 0; i<n; i++)
    root = insert(root, ranges[i]);
  return 0;
}
