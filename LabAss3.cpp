#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

/* Solution functions */
void oneAns();
//void twoAns();
//void thrAns();


/*    PROGRAM UTILS   */
void error(){
  cout << endl << "Error encountered. restarting program..." << endl;
  Sleep(1500);
}

int getMin(int a, int b){
  return (a<b)?a:b;
}

int getMid(int a, int b){
  return (a+(b-a)/2);
}

void ques(int n){
  switch(n){
    case 1:
      cout << "QUESTION 1" << endl;
      break;
    case 2:
      cout << "QUESTION 2" << endl;
      break;
    case 3:
      cout << "QUESTION 3" << endl;
      break;
  }
}

void pause(){
  char c = 'a';
  while(c!='c'){
    cout << endl << "Enter 'c' to continue..." << endl;
    cin >> c;
  }
}

void manage(int n){
  system("cls");
  switch(n){
    case 1:
      ques(1);
      oneAns();
      break;
    case 2:
      ques(2);
      //twoAns();
      break;
    case 3:
      ques(3);
      //thrAns();
      break;
  }
  pause();
}

/*  ONE ANSWER  */
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
  return temp;
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

void inorder(node* root){
  if(root == NULL)
    return;
  inorder(root->left);
  cout << " {" << root->i->l << ", " << root->i->h << "} ";
  inorder(root->right);
}

void oneAns(){
  interval ranges[] = {{17,19}, {21,24}, {30, 35}, {5, 8}, {20, 30}, {4, 8}, {24, 27}, {15, 18}, {16, 20}, {7, 10}, {28, 29}, {6, 7}};
  node* root = NULL;
  int n = sizeof(ranges)/sizeof(ranges[0]);
  for(int i = 0; i<n; i++)
    root = insert(root, ranges[i]);
  while(1){
    system("cls");
    cout << "\t\tLab Assignment 3 | Question 1" << endl << endl;
    cout << "[ _ ] Select a part:" << endl;
    cout << "\t[ 1 ] Display inorder traversal" << endl;
    cout << "\t[ 2 ] Insert an interval" << endl;
    cout << "\t[ 3 ] Search for interval" << endl;
    cout << "\t[ 4 ] Delete an interval" << endl << endl;
    cout << "\t[ 0 ] Return" << endl;
    cout << "[ _ ] Option: ";
    int n;
    cin >> n;
    switch (n) {
      case 0:
        return;
      case 1:
        cout << "Inorder Traversal: ";
        inorder(root);
        break;
      case 2:
        cout << "Enter the lower value: ";
        int lo;
        cin >> lo;
        cout << "ENter the higher value: ";
        int up;
        cin >> up;
        interval ins = {lo, up};
        root = insert(root, ins);
        break;
    }
    cout << "[ = ] Done!" << endl;
    pause();
  }
  interval target={6,25};
  interval *container = overlap(root, target);
  cout << "Interval containing the target range {" << target.l << ", " << target.h << "} is : {" << container->l << ", " << container->h << "}." << endl;
  cout << endl << "Inorder traversal of the Interval Tree: ";
  inorder(root);
  return;
}

/*  Answer Two  */


/*  DRIVER FUNCTION */
int main(){
  while(1){
    system("cls");
    cout << "\t\tLab Assignment 3" << endl << endl;
    cout << "[ _ ] Select a question:" << endl;
    cout << "\t[ - ] Question 1" << endl;
    cout << "\t[ - ] Question 2" << endl;
    cout << "\t[ - ] Question 3" << endl;
    cout << "\t[ - ] Question 4" << endl << endl;
    cout << "\t[ 0 ] Exit" << endl;
    int n;
    cout << "[ _ ] Option: ";
    cin >> n;
    switch(n){
      case 0:
        return 0;
      case 1:
        manage(1);
        break;
      case 2:
        manage(2);
        break;
      case 3:
        manage(3);
        break;
      case 4:
        manage(4);
        break;
      default:
        error();
        break;
    }
  }
}
