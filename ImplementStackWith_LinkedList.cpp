#include<iostream>
using namespace std;

//   Creating a NODE Structure
struct Node
{
    int data;
    Node *next;
};

// Creating a class STACK
class Stack
{
public:
  Node *top;
  Stack(){top=NULL;}
  
  void push(int value);
  void pop();
  void display();
  ~Stack();
};

void Stack::push(int value){
  Node *tmp= new Node;
  if(tmp==NULL)
  {
    cout<<"overflow"<<endl;
    return;
  }
  tmp->data= value;
  tmp->next=top;
  top= tmp;
  cout<<value<<" has been pushed"<<endl;
}

void Stack::pop(){
  if(top==NULL){
    cout<<"underflow"<<endl;
    return;
  }
  Node *tmp=top;
  cout<<top->data<<" is being popped"<<endl;
  top=top->next;
  delete tmp;
}

void Stack::display(){
  if(top==NULL){
    cout<<"underflow"<<endl;
    return;
  }
  Node *tmp=top;
  while(tmp){
    cout<<tmp->data<<" ";
    tmp=tmp->next;
  }
  cout<<endl;
}

Stack::~Stack(){
  while(top!=NULL){
    Node *tmp=top;
    top=top->next;
    delete tmp;
  }
}

int main()
{
  Stack s;
  s.display();
  s.push(10);
  s.push(20);
  s.push(30);
  s.display();
  s.pop();
  s.pop();
  s.display();
  return 0;
}
  