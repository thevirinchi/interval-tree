#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

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
      twoAns();
      break;
    case 3:
      ques(3);
      thrAns();
      break;
  }
  pause();
}

int main(){
  while(1){
    system("cls");
    cout << "\t\tLab Assignment 2" << endl << endl;
    cout << "[ _ ] Select a question:" << endl;
    cout << "     [ - ] Question 1" << endl;
    cout << "     [ - ] Question 2" << endl;
    cout << "     [ - ] Question 3" << endl;
    cout << "     [ - ] Question 4" << endl;
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
